#ifndef MODEGRAPHIQUE_H
#define MODEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "cmpGrille.h"


class ModeGraphique {
public:
	// Dimensions de la grille
	const int GRILLE_LARGEUR = 50;
	const int GRILLE_LONGUEUR = 50;
	const int TAILLE_CELLULE = 15;

	// Types
	using Grille = std::vector<std::vector<bool>>;

	void run();
	void mettreAJourGrille(Grille& grid, Grille& nextGrid);
};

#endif