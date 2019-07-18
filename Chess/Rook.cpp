#include "Rook.h"

void Rook::move(int x, int y) {
	if (x == posX || y == posY) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}

Rook::Rook(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}