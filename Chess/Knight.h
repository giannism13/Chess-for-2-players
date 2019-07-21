#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
	bool checkMove(int, int);
	Knight(bool, char, int, int);		//general constructor
	Knight(Knight const&);		//copy constructor
};