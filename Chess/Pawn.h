#pragma once
#include "Piece.h"
class Pawn : public Piece {
public:
	bool checkMove(int, int);
	Pawn(bool, bool, bool, int, int);	//general constructor
	Pawn(const Pawn&);	//copy constructor
};