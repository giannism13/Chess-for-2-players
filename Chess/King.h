#pragma once
#include "Piece.h"
class King : public Piece {
public:
	void move(int, int);
	King(bool, bool, bool, int, int);
};