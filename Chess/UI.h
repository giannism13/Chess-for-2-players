//Αυτη η κλαση χρησιμοποιειται για την διαχειριση της διεπαφης χρηστη
//καθως και την επεξεργασια των δεδομενων που εισαγονται απο αυτον, ωστε
//να ειναι χρησιμοποιησιμα απο τις αλλες κλασεις.
#ifndef UI_h
#define UI_h
#include <iostream>
#include <string>
#include <vector>
#include "Round.h"
#include "Chessboard.h"
using namespace std;

class UI {
public:
	static int displayMenu();				//εμφανιζει το αρχικο μενου και διαβαζει την επιλογη του χρηστη
	static void newGame();					//Ξεκιναει νεο παιχνιδι
	static void play(Chessboard*);			//Κυρια λειτουργια παιχνιδιου
	static vector<int> translate(string);	//μεταφραζει την εντολη που δινει ο παικτης
	static string saveUI();					//διαβαζει το ονομα του αρχειου στο οποιο θα αποθηκευτει η παρτιδα
	static void loadGame();					//Φορτωνει ενα αποθηκευμενο παιχνιδι
	static void replay(vector<Round>);					//Επαναλαμβανει τις κινησεις απο την αρχη
};
#endif
