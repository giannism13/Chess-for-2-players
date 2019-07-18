#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
	void move(int, int);
	Knight(bool, bool, bool, int, int);
};