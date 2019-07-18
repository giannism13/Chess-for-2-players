#include "Pawn.h"

void Pawn::move(int x, int y) {
	if (!this->hasMoved && posX == x && abs(y - posX) <= 2) {
		this->posX = x;
		this->posY = y;
	}
	else if (this->hasMoved && posX == x && abs(y - posX) <= 1) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}

Pawn::Pawn(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}