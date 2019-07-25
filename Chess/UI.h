#pragma once
//Αυτη η κλαση χρησιμοποιειται για την διαχειριση της διεπαφης χρηστη
//καθως και την επεξεργασια των δεδομενων που εισαγονται απο αυτον, ωστε
//να ειναι χρησιμοποιησιμα απο τις αλλες κλασεις.

#include <iostream>
#include <string>
#include "Chessboard.h"
#include <vector>
using namespace std;

class UI {
public:
	static int displayMenu();				//εμφανιζει το αρχικο μενου και διαβαζει την επιλογη του χρηστη
	static void newGame();					//Ξεκιναει νεο παιχνιδι
	static void play(Chessboard*);			//Κυρια λειτουργια παιχνιδιου
	static vector<int> translate(string);	//μεταφραζει την εντολη που δινει ο παικτης
	static string saveUI();					//διαβαζει το ονομα του αρχειου στο οποιο θα αποθηκευτει η παρτιδα
	static void loadGame();			//Φορτωνει ενα αποθηκευμενο παιχνιδι
	static void replay();					//Επαναλαμβανει τις κινησεις απο την αρχη
};