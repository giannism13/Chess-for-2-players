#include "King.h"

bool King::checkMove(int x, int y) {
	if (abs(x - posX) <= 1 && abs(y - posX) <= 1)
		return true;
	else
		return false;
}

King::King(bool hasMoved, char letter, int posX, int posY) {
	this->hasMoved = hasMoved;
	this->posX = posX;
	this->posY = posY;
	this->letter = letter;
}

King::King(const King& copy) {
	this->hasMoved = copy.hasMoved;
	this->posX = copy.posX;
	this->posY = copy.posY;
	this->letter = copy.letter;
}