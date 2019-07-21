#include "Queen.h"

bool Queen::checkMove(int x, int y) {
	if ((x == posX || y == posY) || (abs(x - posX) == abs(y - posY)))
		return true;
	else
		return false;
}

Queen::Queen(bool hasMoved, char letter, int posX, int posY) {
	this->hasMoved = hasMoved;
	this->posX = posX;
	this->posY = posY;
	this->letter = letter;
}

Queen::Queen(const Queen& copy) {
	this->hasMoved = copy.hasMoved;
	this->posX = copy.posX;
	this->posY = copy.posY;
	this->letter = copy.letter;
}
