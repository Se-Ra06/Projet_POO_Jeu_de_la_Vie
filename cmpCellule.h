#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
public:
    virtual ~Cellule() = default;
    // Méthodes virtuelles pures
    virtual bool status() const = 0; 
    virtual bool nextStatus(int voisinsVivants) const = 0;
};

#endif 
