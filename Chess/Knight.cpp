#include "Knight.h"

bool Knight::checkMove(int x, int y) {
	if ((abs(x - posX) == 2 && abs(y - posY) == 1) || (abs(x - posX) == 1 && abs(y - posY) == 2))
		return true;
	return false;
}
