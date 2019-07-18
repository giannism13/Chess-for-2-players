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