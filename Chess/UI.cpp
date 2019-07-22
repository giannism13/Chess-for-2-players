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

void UI::translate(string command) {
	int move[4];
	if (command.size() == 4) {
		if (isalpha(command[0]) && isalpha(command[2])) {
			if (isupper(command[0])) {
				move[0] = ( int) command[0] - 65;
				move[2] = ( int) command[2] - 65;
			}
			else {
				move[0] = ( int) command[0] - 97;
				move[2] = ( int) command[2] - 97;
			}
		}
		else {	//ωστε να βγει ακυρη η κινηση απο την chechMove
			move[0] = 8;
			move[2] = 8;
		}

		if (isdigit(command[1]) && isdigit(command[3])) {
			move[1] = command[1];
			move[3] = command[3];
		}
		else {
			move[1] = 8;
			move[3] = 8;
		}
	}
	else if (command.size() == 3)
		if (command == "0-0")
			//μικρο ροκε
		else {
			move[0] = 8;
			move[1] = 8;
			move[2] = 8;
			move[3] = 8;
		}
	else if (command.size() == 5)
		if (command == "0-0-0")
			//μεγαλο ροκε
		else {
			move[0] = 8;
			move[1] = 8;
			move[2] = 8;
			move[3] = 8;
		}
}		