#include "Bishop.h"

bool Bishop::checkMove(int x, int y) {
	if (abs(x - posX) == abs(y - posY))
		return true;
	else
		return false;
}

Bishop::Bishop(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}

Bishop::Bishop(const Bishop& copy) {
	this->color = copy.checkMove;
	this->hasMoved = copy.hasMoved;
	this->isAlive = copy.isAlive;
	this->posX = copy.posX;
	this->posY = copy.posY;
}