#include "Queen.h"

void Queen::move(int x, int y) {
	if ((x == posX || y == posY) || (abs(x - posX) == abs(y - posY))) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "�� ������ ������!" << endl;
}