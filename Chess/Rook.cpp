#include "Rook.h"

bool Rook::checkMove(int x, int y) {
	if (x == posX || y == posY)
		return true;
	else
		return false;
}

Rook::Rook(bool hasMoved, char letter, int posX, int posY) {
	this->hasMoved = hasMoved;
	this->posX = posX;
	this->posY = posY;
	this->letter = letter;
}

Rook::Rook(const Rook& copy) {
	this->hasMoved = copy.hasMoved;
	this->posX = copy.posX;
	this->posY = copy.posY;
	this->letter = copy.letter;
}
