#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"

class Grille {
private:
    std::vector<std::vector<Cellule*>> grid;
    int largeur;
    int longueur;

    int wrapIndex(int index, int max) const;

public:
    Grille(int largeur, int longueur);
    

    void InitialisationGrille(const std::vector<std::vector<int>>& etatInitial);
    bool getEtat(int x, int y) const;
    Cellule* GetCelluleEtat(int x, int y) const;
    int NombreVoisinsVivants(int x, int y) const;
    void SetCelluleEtat(int x, int y, bool etat);
    int getLargeur() const { return largeur; }
    int getLongueur() const { return longueur; }
    void MiseAJourGrille();
    
};

#endif 
