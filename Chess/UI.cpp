#include "UI.h"

int UI::displayMenu() {
	system("cls");

	int sel;

	cout << "=====�KAKI=====" << endl;
	cout << "1. ��� ��������" << endl;
	cout << "2. ������� ���������� ��� ������" << endl;
	cout << "3. ������" << endl << endl;
	cout << "����� ��� ������� ���: ";
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
		cout << endl << "������ ������: ";
		getline(cin, move);
		//checks


		b->showBoard();
		cout << endl << "������ ������: ";
		getline(cin, move);
		//checks
	}
}