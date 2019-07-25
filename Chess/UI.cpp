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
	vector<int> m;
	while (true) {
		b->showBoard();
		do {
			cout << endl << "������ ������: ";
			getline(cin, move);
			if (move == "0-0") {		//����� ����
				if (!b->castle(true))
					cout << "�� ���� ���� ��� ����� � ��� �����������!" << endl;
				else
					b->setWhiteTurn(false);
			}
			else if (move == "0-0-0") {	//������ ����
				if (!b->castle(false))
					cout << "�� ���� ���� ��� ����� � ��� �����������!" << endl;
				else
					b->setWhiteTurn(false);
			}
			else if (move == "save") {	//���������� ����������
				string name = UI::saveUI();
				b->save(name);
				cout << "�� �������� ������������! ������ ��������� ��� ����� ��� �������� �����" << endl;
				system("pause");
				exit(0);
			}
			else if (move == "replay") {	//��������� ��������
				//todo
			}
			else {
				m = UI::translate(move);
				if (b->move(m[0], m[1], m[2], m[3])) {
					if (b->checkmate()) {
						cout << "���! ���� ������!" << endl;
						system("pause");
						exit(0);
					}
					if (b->stalemate()) {
						cout << "���! ��������!" << endl;
						system("pause");
						exit(0);
					}
					b->setWhiteTurn(false);
				}
				else
					cout << "�� ������ ������!" << endl;
			}
		} while (b->getWhiteTurn());
		
		b->showBoard();
		do {
			cout << endl << "������ ������: ";
			getline(cin, move);
			if (move == "0-0") {		//����� ����
				if (!b->castle(true))
					cout << "�� ���� ���� ��� ����� � ��� �����������!" << endl;
				else
					b->setWhiteTurn(true);
			}
			else if (move == "0-0-0") {	//������ ����
				if (!b->castle(false))
					cout << "�� ���� ���� ��� ����� � ��� �����������!" << endl;
				else
					b->setWhiteTurn(true);
			}
			else if (move == "save") {	//���������� ����������
				cout << "�� �������� ��� ������ �� ���� ��� ����� ��� ������!" << endl;
				exit(0);
			}
			else if (move == "replay") {	//��������� ��������
				//todo
			}
			else {
				m = UI::translate(move);
				if (b->move(m[0], m[1], m[2], m[3])) {
					if (b->checkmate()) {
						cout << "���! ���� ������!" << endl;
						system("pause");
						exit(0);
					}
					if (b->stalemate()) {
						cout << "���! ��������!" << endl;
						system("pause");
						exit(0);
					}
					b->setWhiteTurn(true);
				}
				else
					cout << "�� ������ ������!" << endl;
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
		else {	//���� �� ���� ����� � ������ ��� ��� chechMove
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
			move[4] = 1;	//����� ����
		else {
			move[0] = 8;
			move[1] = 8;
			move[2] = 8;
			move[3] = 8;
			move[4] = 8;
		}
	else if (command.size() == 5)
		if (command == "0-0-0")
			move[4] = 2; //������ ����
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
	cout << "����� �� ����� ��� �������: ";
	getline(cin, file);
	return file;
}

void UI::loadGame() {
	string name;
	Chessboard b;

	cout << "����� �� ����� ��� �������: ";
	getline(cin, name);
	b.load(name);
	UI::play(&b);
}

void UI::replay() {

}