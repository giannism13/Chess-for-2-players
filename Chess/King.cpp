#include "King.h"

bool King::checkMove(int x, int y) {
	if (abs(x - posX) <= 1 && abs(y - posX) <= 1)
		return true;
	else
		return false;
}

King::King(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}

King::King(const King& copy) {
	this->color = copy.checkMove;
	this->hasMoved = copy.hasMoved;
	this->isAlive = copy.isAlive;
	this->posX = copy.posX;
	this->posY = copy.posY;
}