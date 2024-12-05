#ifndef JEU_H
#define JEU_H

#include "cmpGrille.h"
#include <string>

class Jeu {
private:
    Grille grille;
    int iterations;

public:
    Jeu(int largeur, int longueur, int iterations);
    Jeu(const Grille& grille, int iterations);
    void Simulation(const std::string& outputDir);
    void MiseAJourGrille();
};

#endif 
