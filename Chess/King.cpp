#include "King.h"

bool King::checkMove(int x, int y) {
	if (abs(x - posX) <= 1 && abs(y - posX) <= 1)
		return true;
	return false;
}