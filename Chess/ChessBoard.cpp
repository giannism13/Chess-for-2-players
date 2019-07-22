#include "Chessboard.h"

Chessboard::Chessboard() {
	//λευκα
	this->board[0][0] = new Rook(true, 'R', 0, 0);
	this->board[7][0] = new Rook(true, 'R', 7, 0);

	this->board[1][0] = new Knight(true, 'N', 1, 0);
	this->board[6][0] = new Knight(true, 'N', 6, 0);

	this->board[2][0] = new Bishop(true, 'B', 2, 0);
	this->board[5][0] = new Bishop(true, 'B', 5, 0);

	this->board[3][0] = new Queen(true, 'Q', 3, 0);
	this->board[4][0] = new King(true, 'K', 4, 0);
	
	for (int i = 0; i < 8; i++)
		this->board[i][1] = new Pawn(true, 'P', i, 1);

	//μαυρα
	this->board[0][7] = new Rook(true,'r', 0, 7);
	this->board[7][7] = new Rook(true, 'r', 7, 7);

	this->board[1][7] = new Knight(true, 'n', 1, 7);
	this->board[6][7] = new Knight(true, 'n', 6, 7);

	this->board[2][7] = new Bishop(true, 'b', 2, 7);
	this->board[5][7] = new Bishop(true, 'b', 5, 7);

	this->board[3][7] = new Queen(true, 'q', 3, 7);
	this->board[4][7] = new King(true, 'k', 4, 7);

	for (int i = 0; i < 8; i++)
		this->board[i][6] = new Pawn(true, 'p', i, 6);

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

void Chessboard::showBoard() {
	system("chcp 65001");	//για την υποστηριξη unicode χαρακτηρων
	//τυπωση οριου πρωτης γραμμης
	cout << ( char) 218;	//Γ
	for (int i = 0; i < 16; i++) {
		if (i % 2 == 0)
			cout << ( char) 196;	//-
		else
			cout << ( char) 194;	//T

		cout << ( char) 191 << endl;
	}
	//τυπωση σκακιερας
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 16; j++) {
			if (i % 2 != 0)
				if (j == 0)
					cout << ( char) 195;
				else if (j == 16)
					cout << ( char) 180;
				else if (j % 2 == 0)
					cout << ( char) 196;	//-
				else
					cout << ( char) 197;	//+
			else
				if (j % 2 == 0)
					cout << ( char) 179;	//|
				else if (this->board[i / 2][j / 2] == NULL)
					cout << "  ";
				else
					cout << this->board[i / 2][j / 2]->getLetter() << " ";

			cout << endl;
		}

	system("chcp 1253");

	//τυπωση κατω οριου τελευταιας γραμμης
	cout << ( char) 192;	//L
	for (int i=0; i<16; i++)
		if (i % 2 == 0)
			cout << ( char) 196;	//-
		else
			cout << ( char) 193;

	cout << ( char) 217 << endl;

	cout << " A B C D E F G H" << endl;
}

bool Chessboard::pathCheck(int x , int y, Piece* p) {
	if (p->getPosX() == x) {	//κινειται καθετα
		if (p->getPosY() < y) {	//προς τα πανω
			for (int j = p->getPosY(); j < x; j++)
				if (this->board[x][j] != NULL)	//ελεγχος αν ενα ενδιαμεσο τετραγωνο δεν ειναι κενο
					return false;
		}
		else {	//προς τα κατω
			for (int j = p->getPosY(); j < x; j--)
				if (this->board[x][j] != NULL)
					return false;
		}
	}
	else if (p->getPosY == y) {	//κινειται οριζοντια
		if (p->getPosX() < x) {	//προς τα δεξια
			for (int i = p->getPosX(); i < x; i++)
				if (this->board[i][y] != NULL)
					return false;
		}
		else {	//προς τα αριστερα
			for (int i = p->getPosX(); i < x; i--)
				if (this->board[i][y] != NULL)
					return false;
		}
	}
	else {	//διαγωνια κινηση
		if (p->getPosX() < x && p->getPosY() < y) {	//πανω δεξια
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else if (p->getPosX() > x && p->getPosY() < y) {	//πανω αριστερα
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else if (p->getPosX() < x && p->getPosY() > y) {	//κατω δεξια
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else {	//κατω αριστερα
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
	}
}
