#ifndef CELLULEM_H
#define CELLULEM_H
#include "cmpCellule.h"

class CelluleVie : public Cellule {
public:
	
	bool status() const override;
	virtual bool nextStatus(int voisinsVivants) const override;
};

#endif

