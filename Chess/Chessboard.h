#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

class Chessboard {
private:
	Piece* board[8][8];		//πινακας σκακιερας
public:
	Chessboard();	//default constructor για νεο παιχνιδι
	void move(int ,int);	//μετακινει τα κομματια στη σκακιερα
	void showBoard();	//εμφανιζει την τρεχουσα κατασταση της σκακιερας
};