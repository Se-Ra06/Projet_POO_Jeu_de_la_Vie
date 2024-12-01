#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
protected:
	int voisins;
public:
	virtual ~Cellule() {}
	virtual bool status() = 0;
	virtual Cellule* nextStatus(int voisins) = 0;
};

#endif 