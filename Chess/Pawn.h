#pragma once
#include "Piece.h"
class Pawn : public Piece {
public:
	void move(int, int);
	Pawn(bool, bool, bool, int, int);
};