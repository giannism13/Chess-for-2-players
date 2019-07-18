#include "Chessboard.h"

Chessboard::Chessboard() {
	this->board[0][0] = new Rook(true, false, 0, 0);
}
