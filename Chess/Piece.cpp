#include "Piece.h"

void Piece::setIsAlive(bool alive) {
	this->isAlive = alive;
}

void Piece::setHasMoved(bool moved) {
	this->hasMoved = moved;
}

void Piece::setColor(bool color) {
	this->color = color;
}

void Piece::setPosX(int x) {
	this->posX = x;
}

void Piece::setPosY(int y) {
	this->posY = y;
}

bool Piece::getIsAlive() { return this->isAlive; }

bool Piece::getHasMoved() { return this->hasMoved; }

bool Piece::getColor() { return this->color; }

int Piece::getPosX() { return this->posX; }

int Piece::getPosY() { return this->posY; }
