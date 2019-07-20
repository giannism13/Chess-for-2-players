#include "Chessboard.h"

Chessboard::Chessboard() {
	//λευκα
	this->board[0][0] = new Rook(true, false, true, 0, 0);
	this->board[0][7] = new Rook(true, false, true, 0, 7);

	this->board[0][1] = new Knight(true, false, true, 0, 1);
	this->board[0][6] = new Knight(true, false, true, 0, 6);

	this->board[0][2] = new Bishop(true, false, true, 0, 2);
	this->board[0][2] = new Bishop(true, false, true, 0, 5);

	this->board[0][3] = new Queen(true, false, true, 0, 3);
	this->board[0][4] = new King(true, false, true, 0, 4);
	
	for (int i = 0; i < 8; i++)
		this->board[1][i] = new Pawn(true, false, true, 0, i);

	//μαυρα
	this->board[0][0] = new Rook(true, false, false, 7, 0);
	this->board[0][7] = new Rook(true, false, false, 7, 7);

	this->board[0][1] = new Knight(true, false, false, 7, 1);
	this->board[0][6] = new Knight(true, false, false, 7, 6);

	this->board[0][2] = new Bishop(true, false, false, 7, 2);
	this->board[0][2] = new Bishop(true, false, false, 7, 5);

	this->board[0][3] = new Queen(true, false, false, 7, 3);
	this->board[0][4] = new King(true, false, false, 7, 4);

	for (int i = 0; i < 8; i++)
		this->board[6][i] = new Pawn(true, false, false, 0, i);

	for (int i = 2; i < 6; i++)		//τα υπολοιπα τετραγωνα πρεπει να ειναι "κενα"
		for (int j = 0; j < 7; j++)
			this->board[i][j] = NULL;
}

void Chessboard::move(int x, int y) {
	if (this->board[y][x]->checkMove(x, y)) {
		//this->board[y][x] = this->board[this->board]
	}
	else
		cout << "Μη εγκυρη κινηση!" << endl;
}