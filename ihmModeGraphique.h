#ifndef MODEGRAPHIQUE_H
#define MODEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

class ModeGraphique {
public:
	// Dimensions de la grille
	const int GRILLE_LARGEUR = 50;
	const int GRILLE_LONGUEUR = 50;
	const int TAILLE_CELLULE = 15;

	
	using GrilleGraph = std::vector<std::vector<bool>>;

	void run();
	void mettreAJourGrille(GrilleGraph& grille, GrilleGraph& nextGrille);
};

#endif
