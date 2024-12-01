#ifndef GRILLE_H
#define GRILLE_H
#include <vector>
#include <string>
#include <stdexcept>
#include "cmpCellule.h"

using namespace std;


class Grille {
protected:
	int largeur;
	int longueur;
public:
	vector<vector<Cellule*>> grid;
	Grille(int longueur, int largeur); // Constructeur
	~Grille(); // Destructeur
	void initialisationGrille(const string& fichier); // Initialisation à partir du fichier fourni
	int NombreVoisinsVivants(int x, int y); // Méthode pour calculer le nombre de voisins vivants
	bool GetCelluleEtat(int x, int y); // Getter pour obtenir l'état des cellules 
	void SetCelluleEtat(int x, int y, bool etat); // Setter pour changer l'état des cellules
	void getEtat(); // Méthode pour mettre à jour l'état de la grille
};

#endif