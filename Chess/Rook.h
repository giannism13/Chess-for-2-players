#pragma once
#include "Piece.h"
class Rook : public Piece {
public:
	void move(int x, int y);
	Rook(bool, bool, bool, int, int);
};