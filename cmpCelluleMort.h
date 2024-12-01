#ifndef CELLULEM_H
#define CELLULEM_H
#include "cmpCellule.h"

class CelluleMort : public Cellule {
public:
	CelluleMort();
	bool status() override;
	Cellule* nextStatus(int voisins) override;
};

#endif