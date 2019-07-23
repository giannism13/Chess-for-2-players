#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include <math.h>
#include <cctype>

class Chessboard {
private:
	Piece* board[8][8];		//πινακας σκακιερας
	bool whiteTurn;			//Ποιος παιζει;
public:
	Chessboard();						//default constructor για νεο παιχνιδι
	bool move(int ,int, int, int);		//μετακινει τα κομματια στη σκακιερα
	void showBoard();					//εμφανιζει την τρεχουσα κατασταση της σκακιερας
	bool pathCheck(int, int, Piece*);	//Ελεγχει εαν η διαδρομη ενος κοματιου (πλην ιππου) ειναι ελευθερη
	bool kingChecked();					//Ελεγχει εαν ο βασιλιας ειναι σε σαχ
	bool castle(bool);					//ΕΛεγχει τις προυποθεσεις για ροκε και το πραγματοποιει
};