#include "Rook.h"

bool Rook::checkMove(int x, int y) {
	if (x == posX || y == posY)
		return true;
return false;
}