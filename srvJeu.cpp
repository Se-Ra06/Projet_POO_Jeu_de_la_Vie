#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <direct.h>
#include "srvJeu.h"
#include "srvFileService.h" 



Jeu::Jeu(int largeur, int longueur, int iterations)
    : grille(largeur, longueur), iterations(iterations) {}

Jeu::Jeu(const Grille& grille, int iterations)
    : grille(grille), iterations(iterations) {}

void Jeu::Simulation(const std::string& outputDir) {
    
    if (_mkdir(outputDir.c_str()) != 0 && errno != EEXIST) {
        throw std::runtime_error("Erreur lors de la création du repertoire : " + outputDir);
    } 

    std::cout << "Debut de la simulation pour " << iterations << " iterations" << std::endl;

   
    FileService::SauvegarderIteration(grille, outputDir, 0);

    
    for (int i = 1; i <= iterations; ++i) {
        std::cout << "Iteration " << i << "/" << iterations << std::endl;

       
        MiseAJourGrille();

        
        FileService::SauvegarderIteration(grille, outputDir, i);
    }

    std::cout << "Simulation terminee" << std::endl;
}

void Jeu::MiseAJourGrille() {
    std::vector<std::vector<bool>> prochainsEtats(grille.getLongueur(), std::vector<bool>(grille.getLargeur()));

    
    for (int x = 0; x < grille.getLongueur(); ++x) {
        for (int y = 0; y < grille.getLargeur(); ++y) {
            int voisinsVivants = grille.NombreVoisinsVivants(x, y);
            prochainsEtats[x][y] = grille.getEtat(x, y)
                ? (voisinsVivants == 2 || voisinsVivants == 3)
                : (voisinsVivants == 3);
        }
    }

    
    for (int x = 0; x < grille.getLongueur(); ++x) {
        for (int y = 0; y < grille.getLargeur(); ++y) {
            grille.SetCelluleEtat(x, y, prochainsEtats[x][y]);
        }
    }

   
    std::cout << "Etat actuel de la grille :\n";
    for (int x = 0; x < grille.getLongueur(); ++x) {
        for (int y = 0; y < grille.getLargeur(); ++y) {
            std::cout << (grille.getEtat(x, y) ? '1' : '0') << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::string(30, '-') << "\n"; 
}
