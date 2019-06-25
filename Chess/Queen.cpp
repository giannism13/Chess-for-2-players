#include "Queen.h"

bool Queen::checkMove(int x, int y) {
	if ((x == posX || y == posY) || (abs(x - posX) == abs(y - posY)))
		return true;
	return false;
}