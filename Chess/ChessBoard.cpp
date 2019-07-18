#include "Chessboard.h"

Chessboard::Chessboard() {
	this->board[0][0] = new Rook(true, true, true, 0, 0);
}
