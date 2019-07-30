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
	vector<char> m;
	vector<Round> rounds;
	Round r;

	while (true) {
		b->showBoard();
		do {
			cout << endl << "������ ������: ";
			getline(cin, move);
			if (move == "0-0") {		//����� ����
				if (!b->castle(true))
					cout << "�� ���� ���� ��� ����� � ��� �����������!" << endl;
				else {
					b->setWhiteTurn(false);
					r.setWhite(move);
				}
			}
			else if (move == "0-0-0") {	//������ ����
				if (!b->castle(false))
					cout << "�� ���� ���� ��� ����� � ��� �����������!" << endl;
				else {
					b->setWhiteTurn(false);
					r.setWhite(move);
				}
			}
			else if (move == "save") {	//���������� ����������
				string name = UI::saveUI();
				b->save(name);
				cout << "�� �������� ������������! ������ ��������� ��� ����� ��� �������� �����" << endl;
				system("pause");
				exit(0);
			}
			else if (move == "replay")	//��������� ��������
				UI::replay(rounds);
			else {
				fflush(stdin);
				m = UI::translate(move);
				cout << "Arxiko:" << m.at(0) << m.at(1) << endl << "Teliko:" << m[2] << m[3] << endl;	//DEBUG
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
					r.setWhite(move);
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
				else {
					b->setWhiteTurn(true);
					r.setBlack(move);
				}
			}
			else if (move == "0-0-0") {	//������ ����
				if (!b->castle(false))
					cout << "�� ���� ���� ��� ����� � ��� �����������!" << endl;
				else {
					b->setWhiteTurn(true);
					r.setBlack(move);
				}
			}
			else if (move == "save") {	//���������� ����������
				cout << "�� �������� ������ �� ����������� ���� ��� ����� ��� ������!" << endl;
				exit(0);
			}
			else if (move == "replay")	//��������� ��������
				UI::replay(rounds);
			else {						//������� ��� �������� ��� ��������� ��������
				m = UI::translate(move);
							
				for (std::vector<char>::const_iterator i = m.begin(); i != m.end(); ++i)
					std::cout << *i << ' ';				
					//cout << m[0] << " " << m[1] << " " << m[2] << " " << m[3] << endl;	//DEBUG
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
					r.setBlack(move);
				}
				else
					cout << "�� ������ ������!" << endl;
			}
		} while (!b->getWhiteTurn());
		rounds.push_back(r);
	}
}

vector<char> UI::translate(string command) {
	vector<char> move;
	move.assign(4, 0);
	if (command.size() == 4) {
		if (isalpha(command[0]) && isalpha(command[2])) {
			if (isupper(command[0])) {
				move[0] = command[0] - 17;		//��������� ��� ��������� �� ������ 				
				move[2] = command[2] - 17;
			}
			else {
				move[0] = command[0] - 49;				
				move[2] = command[2] - 49;
			}
		}
		else {									//���� �� ���� ����� � ������ ��� ��� checkMove
			move[0] = 8;
			move[2] = 8;
		}

		if (isdigit(command[1]) && isdigit(command[3])) {
			move[1] = command[1] - 1;
			move[3] = command[3] - 1;
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
	else if (command.size() == 5){
		if (command == "0-0-0")
			move[4] = 2; //������ ����
		else {
			move[0] = 8;
			move[1] = 8;
			move[2] = 8;
			move[3] = 8;
			move[4] = 8;
		}
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

void UI::replay(vector<Round> rounds) {
	Chessboard b;
	Round r;
	string move;
	vector<char> m;
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
	UI::play(&b);	//�������� ����������
}
