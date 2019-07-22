#pragma once
//Αυτη η κλαση χρησιμοποιειται για την διαχειριση της διεπαφης χρηστη
//καθως και την επεξεργασια των δεδομενων που εισαγονται απο αυτον, ωστε
//να ειναι χρησιμοποιησιμα απο τις αλλες κλασεις.

#include <iostream>
#include <string>
#include "Chessboard.h"
using namespace std;

class UI {
public:
	static int displayMenu();	//εμφανιζει το αρχικο μενου και διαβαζει την επιλογη του χρηστη
	static void newGame();		//Ξεκιναει νεο παιχνιδι
	static void play(Chessboard*);	//Κυρια λειτουργια παιχνιδιου
};