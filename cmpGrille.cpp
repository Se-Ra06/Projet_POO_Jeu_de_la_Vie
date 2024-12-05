#include "cmpGrille.h"
#include "cmpCelluleVie.h"
#include "cmpCelluleMort.h"
#include <stdexcept>
#include <iostream>  

using namespace std;

Grille::Grille(int largeur, int longueur) : largeur(largeur), longueur(longueur) {
    grid.resize(longueur, std::vector<Cellule*>(largeur, nullptr));
}


void Grille::InitialisationGrille(const std::vector<std::vector<int>>& etatInitial) {
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            delete grid[i][j]; 
            if (etatInitial[i][j] == 1) {
                grid[i][j] = new CelluleVie();
            }
            else {
                grid[i][j] = new CelluleMort();
            }
        }
    }

    
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            std::cout << (grid[i][j]->status() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}

bool Grille::getEtat(int x, int y) const {
    if (x < 0 || x >= longueur || y < 0 || y >= largeur) {
        throw std::out_of_range("Indices hors limites dans Grille::getEtat");
    }

    if (!grid[x][y]) {
        throw std::runtime_error("Cellule non initialisée dans Grille::getEtat");
    }

    return grid[x][y]->status();
}

int Grille::wrapIndex(int index, int max) const {
    if (max <= 0) {
        throw std::invalid_argument("wrapIndex: max doit être supérieur à 0.");
    }

    if (index < 0) {
        return (index % max + max) % max; 
    }
    if (index >= max) {
        return index % max; 
    }
    return index; 
}

int Grille::NombreVoisinsVivants(int x, int y) const {
    int count = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            
            if (dx == 0 && dy == 0) continue;

            // Calculer les indices des voisins
            int nx = wrapIndex(x + dx, longueur);
            int ny = wrapIndex(y + dy, largeur);

            // Vérifier si le voisin est vivant
            if (grid[nx][ny] && grid[nx][ny]->status()) {
                ++count;
            }
        }
    }
    return count;
}

void Grille::SetCelluleEtat(int x, int y, bool etat) {
    delete grid[x][y];
    if (etat) {
        grid[x][y] = new CelluleVie();
    }
    else {
        grid[x][y] = new CelluleMort();
    }
}

Cellule* Grille::GetCelluleEtat(int x, int y) const {
    int wrappedX = wrapIndex(x, longueur);
    int wrappedY = wrapIndex(y, largeur);
    return grid[wrappedX][wrappedY];
}

void Grille::MiseAJourGrille() {
    
    std::vector<std::vector<bool>> prochainsEtats(longueur, std::vector<bool>(largeur));

    // Calculer les états pour la prochaine itération
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int voisinsVivants = NombreVoisinsVivants(i, j);

            if (grid[i][j]->status()) {
                // Cellule vivante : reste vivante avec 2 ou 3 voisins
                prochainsEtats[i][j] = (voisinsVivants == 2 || voisinsVivants == 3);
            }
            else {
                // Cellule morte : devient vivante avec exactement 3 voisins
                prochainsEtats[i][j] = (voisinsVivants == 3);
            }
        }
    }

    // Appliquer les nouveaux états à la grille
    for (int i = 0; i < longueur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            SetCelluleEtat(i, j, prochainsEtats[i][j]);
        }
    }
}
