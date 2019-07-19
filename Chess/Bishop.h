#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
	bool checkMove(int, int);
	Bishop(bool, bool, bool, int, int);		//general constructor
	Bishop(const Bishop& copy);		//copy constructor
};