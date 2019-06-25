#include "Pawn.h"

bool Pawn::checkMove(int x, int y) {
	if (!this->hasMoved && posX == x && abs(y - posX) <= 2)
		return true;
	else if (this->hasMoved && posX == x && abs(y - posX) <= 1)
		return true;
	return false;
}
