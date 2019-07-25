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
	vector<int> m;
	while (true) {
		b->showBoard();
		do {
			cout << endl << "Κινηση Λευκου: ";
			getline(cin, move);
			if (move == "0-0") {		//Μικρο ροκε
				if (!b->castle(true))
					cout << "Το ροκε εχει ηδη γινει ή δεν επιτρεπεται!" << endl;
				else
					b->setWhiteTurn(false);
			}
			else if (move == "0-0-0") {	//Μεγαλο ροκε
				if (!b->castle(false))
					cout << "Το ροκε εχει ηδη γινει ή δεν επιτρεπεται!" << endl;
				else
					b->setWhiteTurn(false);
			}
			else if (move == "save") {	//Αποθηκευση παιχνιδιου
				string name = UI::saveUI();
				b->save(name);
				cout << "Το παιχνιδι αποθηκευτηκε! Πιεστε οτιδηποτε για εξοδο στο κεντρικο μενου" << endl;
				system("pause");
				exit(0);
			}
			else if (move == "replay") {	//Επαναληψη κινησεων
				//todo
			}
			else {
				m = UI::translate(move);
				if (b->move(m[0], m[1], m[2], m[3])) {
					if (b->checkmate()) {
						cout << "ΜΑΤ! Νικη λευκου!" << endl;
						system("pause");
						exit(0);
					}
					if (b->stalemate()) {
						cout << "ΠΑΤ! Ισοπαλια!" << endl;
						system("pause");
						exit(0);
					}
					b->setWhiteTurn(false);
				}
				else
					cout << "Μη εγκυρη κινηση!" << endl;
			}
		} while (b->getWhiteTurn());
		
		b->showBoard();
		do {
			cout << endl << "Κινηση Μαυρου: ";
			getline(cin, move);
			if (move == "0-0") {		//Μικρο ροκε
				if (!b->castle(true))
					cout << "Το ροκε εχει ηδη γινει ή δεν επιτρεπεται!" << endl;
				else
					b->setWhiteTurn(true);
			}
			else if (move == "0-0-0") {	//Μεγαλο ροκε
				if (!b->castle(false))
					cout << "Το ροκε εχει ηδη γινει ή δεν επιτρεπεται!" << endl;
				else
					b->setWhiteTurn(true);
			}
			else if (move == "save") {	//Αποθηκευση παιχνιδιου
				cout << "Το παιχνιδι δεν μπορει να μονο στη σειρα στο λευκου!" << endl;
				exit(0);
			}
			else if (move == "replay") {	//Επαναληψη κινησεων
				//todo
			}
			else {
				m = UI::translate(move);
				if (b->move(m[0], m[1], m[2], m[3])) {
					if (b->checkmate()) {
						cout << "ΜΑΤ! Νικη Μαυρου!" << endl;
						system("pause");
						exit(0);
					}
					if (b->stalemate()) {
						cout << "ΠΑΤ! Ισοπαλια!" << endl;
						system("pause");
						exit(0);
					}
					b->setWhiteTurn(true);
				}
				else
					cout << "Μη εγκυρη κινηση!" << endl;
			}
		} while (!b->getWhiteTurn());
	}
}

vector<int> UI::translate(string command) {
	vector<int> move;
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
		move[4] = 0;
	}
	else if (command.size() == 3)
		if (command == "0-0")
			move[4] = 1;	//μικρο ροκε
		else {
			move[0] = 8;
			move[1] = 8;
			move[2] = 8;
			move[3] = 8;
			move[4] = 8;
		}
	else if (command.size() == 5)
		if (command == "0-0-0")
			move[4] = 2; //μεγαλο ροκε
		else {
			move[0] = 8;
			move[1] = 8;
			move[2] = 8;
			move[3] = 8;
			move[4] = 8;
		}
	return move;
}

string UI::saveUI() {
	string file;
	cout << "Δωστε το ονομα του αρχειου: ";
	getline(cin, file);
	return file;
}

void UI::loadGame() {
	string name;
	Chessboard b;

	cout << "Δωστε το ονομα του αρχειου: ";
	getline(cin, name);
	b.load(name);
	UI::play(&b);
}

void UI::replay() {

}