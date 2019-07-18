#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	void move(int, int);
	Queen(bool, bool, bool, int, int);
};