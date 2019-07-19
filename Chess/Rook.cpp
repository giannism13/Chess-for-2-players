#include "Rook.h"

bool Rook::checkMove(int x, int y) {
	if (x == posX || y == posY)
		return true;
	else
		return false;
}

Rook::Rook(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}

Rook::Rook(const Rook& copy) {
	this->color = copy.checkMove;
	this->hasMoved = copy.hasMoved;
	this->isAlive = copy.isAlive;
	this->posX = copy.posX;
	this->posY = copy.posY;
}
