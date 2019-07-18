#include "Knight.h"

void Knight::move(int x, int y) {
	if ((abs(x - posX) == 2 && abs(y - posY) == 1) || (abs(x - posX) == 1 && abs(y - posY) == 2)) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}

Knight::Knight(bool isAlive, bool hasMoved, bool color, int posX, int posY) {
	this->isAlive = isAlive;
	this->hasMoved = hasMoved;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
}