#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
	void move(int, int);
	Bishop(bool, bool, bool, int, int);
};