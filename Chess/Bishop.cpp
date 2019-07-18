#include "Bishop.h"

void Bishop::move(int x, int y) {
	if (abs(x - posX) == abs(y - posY)) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}

Bishop::Bishop(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}
