#include "Queen.h"

void Queen::move(int x, int y) {
	if ((x == posX || y == posY) || (abs(x - posX) == abs(y - posY))) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}

Queen::Queen(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}