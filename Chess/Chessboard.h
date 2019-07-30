#ifndef Chessboard_h
#define Chessboard_h

#pragma once
#include "Piece.h"
#include <math.h>
#include <cctype>
#include <fstream>
using namespace std;

class Chessboard {
private:
	Piece* board[8][8];		//πινακας σκακιερας
	bool whiteTurn;			//Ποιος παιζει;
public:
	Chessboard();						//default constructor για νεο παιχνιδι
	bool move(char, char, char, char);		//μετακινει τα κομματια στη σκακιερα
	void showBoard();					//εμφανιζει την τρεχουσα κατασταση της σκακιερας
	bool pathCheck(int, int, Piece*);	//Ελεγχει εαν η διαδρομη ενος κοματιου (πλην ιππου) ειναι ελευθερη
	bool kingChecked();					//Ελεγχει εαν ο βασιλιας ειναι σε σαχ
	bool castle(bool);					//Ελεγχει τις προυποθεσεις για ροκε και το πραγματοποιει
	bool checkmate();					//Ελεγχει εαν υπαρχει ματ
	bool stalemate();					//Ελεγχει εαν υπαρχει πατ
	void promotion(int, Piece*);		//Προαγει πιονι σε κοματι επιλογης του παικτη
	void save(string);					//Αποθηκευει το ταμπλο σε αρχειο
	void load(string);					//Φορτωνει ενα ταμπλο απο αρχειο;

	//Accessors 
	bool getWhiteTurn();
	void setWhiteTurn(bool);
};
#endif
