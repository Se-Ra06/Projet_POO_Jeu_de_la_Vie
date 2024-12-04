#include "CelluleMort.h"

bool CelluleMort::status() const {
    return false;
}

bool CelluleMort::nextStatus(int voisinsVivants) const {
    return (voisinsVivants == 3);
}
