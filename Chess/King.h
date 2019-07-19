#pragma once
#include "Piece.h"
class King : public Piece {
public:
	bool checkMove(int, int);
	King(bool, bool, bool, int, int);		//general constructor
	King(const King &copy);		//copy constructor
};