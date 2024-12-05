#ifndef CELLULEM_H
#define CELLULEM_H
#include "cmpCellule.h"

class CelluleMort : public Cellule {
public:
	CelluleMort();
	bool status() const override;
	virtual bool nextStatus(int voisinsVivants) const override;
};

#endif
