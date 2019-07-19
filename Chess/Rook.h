#pragma once
#include "Piece.h"
class Rook : public Piece {
public:
	bool checkMove(int x, int y);
	Rook(bool, bool, bool, int, int);	//general constructor
	Rook(const Rook&);	//copy constructor
};