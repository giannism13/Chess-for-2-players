#include "Pawn.h"

bool Pawn::checkMove(int x, int y) {
	if (!this->hasMoved && posX == x && abs(y - posX) <= 2)
		return true;
	else if (this->hasMoved && posX == x && abs(y - posX) <= 1)
		return true;
	else
		return false;
}

Pawn::Pawn(bool hasMoved, char letter, int posX, int posY) {
	this->hasMoved = hasMoved;
	this->posX = posX;
	this->posY = posY;
	this->letter = letter;
}

Pawn::Pawn(const Pawn& copy) {
	this->hasMoved = copy.hasMoved;
	this->posX = copy.posX;
	this->posY = copy.posY;
	this->letter = copy.letter;
}
