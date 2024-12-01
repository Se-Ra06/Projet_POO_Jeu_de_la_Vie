#include "cmpCelluleVie.h"
#include "cmpCelluleMort.h"
#include "cmpCellule.h"

CelluleVie::CelluleVie() {}

bool CelluleVie::status() {
	return 1;
}

Cellule* CelluleVie::nextStatus(int voisins) {
	if (voisins < 2 || voisins > 3) {
		return new CelluleMort();
	}
	else { return new CelluleVie(); }
}