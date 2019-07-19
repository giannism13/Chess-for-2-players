#include "Knight.h"

bool Knight::checkMove(int x, int y) {
	if ((abs(x - posX) == 2 && abs(y - posY) == 1) || (abs(x - posX) == 1 && abs(y - posY) == 2))
		return true;
	else
		return false;
}

Knight::Knight(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}

Knight::Knight(Knight const& copy) {
	this->color = copy.checkMove;
	this->hasMoved = copy.hasMoved;
	this->isAlive = copy.isAlive;
	this->posX = copy.posX;
	this->posY = copy.posY;
}
