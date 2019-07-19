#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
	bool checkMove(int, int);
	Knight(bool, bool, bool, int, int);		//general constructor
	Knight(Knight const&);		//copy constructor
};