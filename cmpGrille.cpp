#include "cmpGrille.h"
#include "cmpCelluleVie.h"
#include "cmpCelluleMort.h"
#include "cmpCellule.h"
#include <fstream>
#include <iostream>
using namespace std;

Grille::Grille(int longueur, int largeur) : longueur(longueur), largeur(largeur) {
	grid.resize(longueur, std::vector<Cellule*>(largeur, nullptr));
	for (int y = 0; y < longueur; ++y) {
		for (int x = 0; x < largeur; ++x) {
			grid[y][x] = new CelluleMort();
		}
	}
}

Grille::~Grille() {
	for (auto& row : grid) {
		for (auto& cell : row) {
			delete cell;
		}
	}
}

void Grille::initialisationGrille(const string& fichier) {
	ifstream file(fichier);
	if (!file.is_open()) {
		cerr << "Erreur lors de l'ouverture du fichier. \n";
		return;
	}
	string line;
	int y = 0;
	while (getline(file, line) && y < longueur) {
		for (int x = 0; x < largeur && x < static_cast<int>(line.size()); x++) {
			delete grid[y][x];
			grid[y][x] = (line[x] == '1') ? static_cast<Cellule*>(new CelluleVie())
				: static_cast<Cellule*>(new CelluleMort());
		}
		y++;
	}
	file.close();
}

int Grille::NombreVoisinsVivants(int x, int y) {
	int count = 0;
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx == 0 && dy == 0) continue;
			int nx = x + dx;
			int ny = y + dy;
			if (nx >= 0 && nx < largeur && ny >= 0 && ny < longueur && grid[ny][nx]->status()) {
				++count;
			}
		}
	}
	return count;
}

bool Grille::GetCelluleEtat(int x, int y) {
	return grid[y][x]->status();
}

void Grille::SetCelluleEtat(int x, int y, bool etat) {
	if (x < 0 || x >= largeur || y < 0 || y >= longueur) {
		throw std::out_of_range("Coordonnées hors de la grille");
	}
	if (grid[y][x] != nullptr) {
		delete grid[y][x]; // Supprimer l'ancienne cellule
	}
	grid[y][x] = etat ? static_cast<Cellule*>(new CelluleVie())
		: static_cast<Cellule*>(new CelluleMort());
}

void Grille::getEtat() {
	vector<vector<Cellule*>> newGrid = grid;
	for (int y = 0; y < longueur; ++y) {
		for (int x = 0; x < largeur; ++x) {
			int voisins = NombreVoisinsVivants(x, y);
			delete newGrid[y][x];
			newGrid[y][x] = grid[y][x]->nextStatus(voisins);
		}
	}
	grid.swap(newGrid);
}