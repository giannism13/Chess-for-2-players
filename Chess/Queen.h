#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	bool checkMove(int, int);
	Queen(bool, bool, bool, int, int);	//general constructor
	Queen(const Queen&);	//copy constructor
};