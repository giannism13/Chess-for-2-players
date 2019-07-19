#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Piece {
protected:
	bool isAlive;
	bool hasMoved;
	bool color;		//true για λευκο
	int posX;
	int posY;
public:
	virtual bool checkMove(int, int) = 0;		//ελεγχος εγκυρης κινησης
};