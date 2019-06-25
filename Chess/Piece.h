#pragma once
#include <math.h>

class Piece {
protected:
	bool isAlive;
	bool hasMoved;
	int posX;
	int posY;
public:
	virtual bool checkMove() = 0;		//ελεγχος εγκυρης κινησης
};