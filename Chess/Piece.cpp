#include "Piece.h"

void Piece::setHasMoved(bool moved) {
	this->hasMoved = moved;
}

void Piece::setPosX(int x) {
	this->posX = x;
}

void Piece::setPosY(int y) {
	this->posY = y;
}

void Piece::setletter(char letter) {
	this->letter = letter;
}

bool Piece::getHasMoved() { return this->hasMoved; }

int Piece::getPosX() { return this->posX; }

int Piece::getPosY() { return this->posY; }

char Piece::getLetter() { return this->letter; }
