#pragma once
#include "Piece.h"
class Pawn : public Piece {
public:
	bool checkMove(int, int);
	Pawn(bool, char, int, int);	//general constructor
	Pawn(const Pawn&);	//copy constructor
};