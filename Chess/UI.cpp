#include "UI.h"

int UI::displayMenu() {
	system("cls");

	int sel;

	cout << "=====ΣKAKI=====" << endl;
	cout << "1. Νέο παιχνίδι" << endl;
	cout << "2. Φόρτωση παιχνιδιού απο αρχείο" << endl;
	cout << "3. Έξοδος" << endl << endl;
	cout << "Δώστε την επιλογή σας: ";
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
	vector<Round> rounds;
	Round r;

	while (true) {
		b->showBoard();
		do {
			cout << endl << "Κίνηση Λευκού: ";
			getline(cin, move);
			if (move == "0-0") {		//Μικρο ροκε
				if (!b->castle(true))
					cout << "Το ροκέ έχει ήδη γίνει ή δεν επιτρέπεται!" << endl;
				else {
					b->setWhiteTurn(false);
					r.setWhite(move);
				}
			}
			else if (move == "0-0-0") {	//Μεγαλο ροκε
				if (!b->castle(false))
					cout << "Το ροκέ έχει ήδη γίνει ή δεν επιτρέπεται!" << endl;
				else {
					b->setWhiteTurn(false);
					r.setWhite(move);
				}
			}
			else if (move == "save") {	//Αποθηκευση παιχνιδιου
				string name = UI::saveUI();
				b->save(name);
				cout << "Το παιχνίδι αποθηκεύτηκε! Πιέστε οτιδήποτε για έξοδο στο κεντρικό μενού" << endl;
				system("pause");
				exit(0);
			}
			else if (move == "replay")	//Επαναληψη κινησεων
				UI::replay(rounds);
			else {
				m = UI::translate(move);
				if (b->move(m[0], m[1], m[2], m[3])) {
					if (b->checkmate()) {
						cout << "ΜΑΤ! Νίκη λευκού!" << endl;
						system("pause");
						exit(0);
					}
					if (b->stalemate()) {
						cout << "ΠΑΤ! Ισοπαλία!" << endl;
						system("pause");
						exit(0);
					}
					b->setWhiteTurn(false);
					r.setWhite(move);
				}
				else
					cout << "Μη έγκυρη κίνηση!" << endl;
			}
		} while (b->getWhiteTurn());

		b->showBoard();
		do {
			cout << endl << "Κίνηση Μαύρου: ";
			getline(cin, move);
			if (move == "0-0") {		//Μικρο ροκε
				if (!b->castle(true))
					cout << "Το ροκέ έχει ήδη γίνει ή δεν επιτρέπεται!" << endl;
				else {
					b->setWhiteTurn(true);
					r.setBlack(move);
				}
			}
			else if (move == "0-0-0") {	//Μεγαλο ροκε
				if (!b->castle(false))
					cout << "Το ροκέ έχει ήδη γίνει ή δεν επιτρέπεται!" << endl;
				else {
					b->setWhiteTurn(true);
					r.setBlack(move);
				}
			}
			else if (move == "save") {	//Αποθηκευση παιχνιδιου
				cout << "Το παιχνίδι μπορεί να αποθηκευτεί μόνο στη σειρά του λευκού!" << endl;
				exit(0);
			}
			else if (move == "replay")	//Επαναληψη κινησεων
				UI::replay(rounds);
			else {
				m = UI::translate(move);
				if (b->move(m[0], m[1], m[2], m[3])) {
					if (b->checkmate()) {
						cout << "ΜΑΤ! Νίκη Μαύρου!" << endl;
						system("pause");
						exit(0);
					}
					if (b->stalemate()) {
						cout << "ΠΑΤ! Ισοπαλία!" << endl;
						system("pause");
						exit(0);
					}
					b->setWhiteTurn(true);
					r.setBlack(move);
				}
				else
					cout << "Μη έγκυρη κίνηση!" << endl;
			}
		} while (!b->getWhiteTurn());
		rounds.push_back(r);
	}
}

vector<int> UI::translate(string command) {
	vector<int> move;
	if (command.size() == 4) {
		if (isalpha(command[0]) && isalpha(command[2])) {
			if (isupper(command[0])) {
				command[0] += 0;
				command[2] += 0;
				move[0] = command[0] - 65;
				move[2] = command[2] - 65;
			}
			else {
				command[0] += 0;
				command[2] += 0;
				move[0] = command[0] - 97;
				move[2] = command[2] - 97;
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
	cout << "Δώστε το όνομα του αρχείου: ";
	getline(cin, file);
	return file;
}

void UI::loadGame() {
	string name;
	Chessboard b;

	cout << "Δώστε το όνομα του αρχείου: ";
	getline(cin, name);
	b.load(name);
	UI::play(&b);
}

void UI::replay(vector<Round> rounds) {
	Chessboard b;
	Round r;
	string move;
	vector<int> m;
	for (int i = 0; i < rounds.size(); i++) {
		r = rounds[i];
		move = r.getWhite();
		b.showBoard();
		if (move == "0-0")
			b.setWhiteTurn(false);
		else if (move == "0-0-0")
			b.setWhiteTurn(false);
		else {
			m = UI::translate(move);
			b.move(m[0], m[1], m[2], m[3]);
			b.setWhiteTurn(false);
		}

		move = r.getBlack();
		b.showBoard();
		if (move == "0-0")
			b.setWhiteTurn(true);
		else if (move == "0-0-0")
			b.setWhiteTurn(true);
		else {
			m = UI::translate(move);
			b.move(m[0], m[1], m[2], m[3]);
			b.setWhiteTurn(true);
		}
	}
	UI::play(&b);	//συνεχεια παιχνιδιου
}
