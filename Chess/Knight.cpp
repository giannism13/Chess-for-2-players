#include "Knight.h"

bool Knight::checkMove(int x, int y) {
	if ((abs(x - posX) == 2 && abs(y - posY) == 1) || (abs(x - posX) == 1 && abs(y - posY) == 2))
		return true;
	else
		return false;
}

Knight::Knight(bool hasMoved, char letter, int posX, int posY) {
	this->hasMoved = hasMoved;
	this->posX = posX;
	this->posY = posY;
	this->letter = letter;
}

Knight::Knight(Knight const& copy) {
	this->hasMoved = copy.hasMoved;
	this->posX = copy.posX;
	this->posY = copy.posY;
	this->letter = copy.letter;
}
