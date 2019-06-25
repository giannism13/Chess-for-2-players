#include "Bishop.h"

bool Bishop::checkMove(int x, int y) {
	if (abs(x - posX) == abs(y - posY))
		return true;
	return false;
}