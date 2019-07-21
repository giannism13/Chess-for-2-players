#include "Bishop.h"

bool Bishop::checkMove(int x, int y) {
	if (abs(x - posX) == abs(y - posY))
		return true;
	else
		return false;
}

Bishop::Bishop(bool hasMoved, char letter, int posX, int posY) {
	this->hasMoved = hasMoved;
	this->posX = posX;
	this->posY = posY;
	this->letter = letter;
}

Bishop::Bishop(const Bishop& copy) {
	this->hasMoved = copy.hasMoved;
	this->posX = copy.posX;
	this->posY = copy.posY;
	this->letter = copy.letter;
}