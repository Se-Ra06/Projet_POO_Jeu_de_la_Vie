#ifndef CELLULEV_H
#define CELLULLEV_H
#include "cmpCellule.h"

class CelluleVie : public Cellule {
public:

	CelluleVie();
	bool status() override;
	Cellule* nextStatus(int voisins) override;
};

#endif