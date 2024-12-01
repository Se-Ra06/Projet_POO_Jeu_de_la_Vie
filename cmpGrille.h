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
	void initialisationGrille(const string& fichier); // Initialisation � partir du fichier fourni
	int NombreVoisinsVivants(int x, int y); // M�thode pour calculer le nombre de voisins vivants
	bool GetCelluleEtat(int x, int y); // Getter pour obtenir l'�tat des cellules 
	void SetCelluleEtat(int x, int y, bool etat); // Setter pour changer l'�tat des cellules
	void getEtat(); // M�thode pour mettre � jour l'�tat de la grille
};

#endif