#include "King.h"

void King::move(int x, int y) {
	if (abs(x - posX) <= 1 && abs(y - posX) <= 1) {
		this->posX = x;
		this->posX = y;
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}