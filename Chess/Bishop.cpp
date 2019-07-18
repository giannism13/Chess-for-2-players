#include "Bishop.h"

void Bishop::move(int x, int y) {
	if (abs(x - posX) == abs(y - posY)) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}