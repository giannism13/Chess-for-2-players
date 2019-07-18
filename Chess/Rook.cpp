#include "Rook.h"

void Rook::move(int x, int y) {
	if (x == posX || y == posY) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}