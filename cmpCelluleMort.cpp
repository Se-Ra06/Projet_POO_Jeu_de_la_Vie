#include "cmpCelluleVie.h"
#include "cmpCelluleMort.h"
#include "cmpCellule.h"

CelluleMort::CelluleMort() {}

bool CelluleMort::status() {
	return 0;
}

Cellule* CelluleMort::nextStatus(int voisins) {
	if (voisins == 3) {
		return new CelluleVie();
	}
	else { return new CelluleMort(); }
}