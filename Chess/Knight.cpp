#include "Knight.h"

void Knight::move(int x, int y) {
	if ((abs(x - posX) == 2 && abs(y - posY) == 1) || (abs(x - posX) == 1 && abs(y - posY) == 2)) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "�� ������ ������!" << endl;
}
