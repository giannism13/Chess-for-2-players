#include "Queen.h"

bool Queen::checkMove(int x, int y) {
	if ((x == posX || y == posY) || (abs(x - posX) == abs(y - posY)))
		return true;
	else
		return false;
}

Queen::Queen(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}

Queen::Queen(const Queen& copy) {
	this->color = copy.checkMove;
	this->hasMoved = copy.hasMoved;
	this->isAlive = copy.isAlive;
	this->posX = copy.posX;
	this->posY = copy.posY;
}
