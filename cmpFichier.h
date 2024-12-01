#ifndef FICHIER_H
#define FICHIER_H
#include <string>
#include "cmpGrille.h"
using namespace std;

class Fichier {
private:
	string NomFichier;
public:
	Grille LireFichier(const string& fichier); // M�thode pour lire le fichier fourni
	void EcrireFichier(const Grille& grid, const string& fichier); // M�thode pour �crire les changements de la grille dans un fichier
};

#endif