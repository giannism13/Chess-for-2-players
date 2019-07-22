#include "UI.h"

int UI::displayMenu() {
	system("cls");

	int sel;

	cout << "=====ΣKAKI=====" << endl;
	cout << "1. Νεο παιχνιδι" << endl;
	cout << "2. Φορτωση παιχνιδιου απο αρχειο" << endl;
	cout << "3. Εξοδος" << endl << endl;
	cout << "Δωστε την επιλογη σας: ";
	cin >> sel;
	return sel;
}

void UI::newGame() {
	Chessboard* b = new Chessboard;
	UI::play(b);
}

void UI::play(Chessboard* b) {
	string move;
	while (true) {
		b->showBoard();
		cout << endl << "Κινηση Λευκου: ";
		getline(cin, move);
		//checks


		b->showBoard();
		cout << endl << "Κινηση Μαυρου: ";
		getline(cin, move);
		//checks
	}
}