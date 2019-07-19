#include "Pawn.h"

bool Pawn::checkMove(int x, int y) {
	if (!this->hasMoved && posX == x && abs(y - posX) <= 2)
		return true;
	else if (this->hasMoved && posX == x && abs(y - posX) <= 1)
		return true;
	else
		return false;
}

Pawn::Pawn(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}

Pawn::Pawn(const Pawn& copy) {
	this->color = copy.checkMove;
	this->hasMoved = copy.hasMoved;
	this->isAlive = copy.isAlive;
	this->posX = copy.posX;
	this->posY = copy.posY;
}
