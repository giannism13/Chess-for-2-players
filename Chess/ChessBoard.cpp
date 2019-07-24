#include "Chessboard.h"

Chessboard::Chessboard() {
	this->whiteTurn = true;	//����� ������ � ������
	//�����
	this->board[0][0] = new Rook(false, 'R', 0, 0);
	this->board[7][0] = new Rook(false, 'R', 7, 0);

	this->board[1][0] = new Knight(false, 'N', 1, 0);
	this->board[6][0] = new Knight(false, 'N', 6, 0);

	this->board[2][0] = new Bishop(false, 'B', 2, 0);
	this->board[5][0] = new Bishop(false, 'B', 5, 0);

	this->board[3][0] = new Queen(false, 'Q', 3, 0);
	this->board[4][0] = new King(false, 'K', 4, 0);

	for (int i = 0; i < 8; i++)
		this->board[i][1] = new Pawn(false, 'P', i, 1);

	//�����
	this->board[0][7] = new Rook(false, 'r', 0, 7);
	this->board[7][7] = new Rook(false, 'r', 7, 7);

	this->board[1][7] = new Knight(false, 'n', 1, 7);
	this->board[6][7] = new Knight(false, 'n', 6, 7);

	this->board[2][7] = new Bishop(false, 'b', 2, 7);
	this->board[5][7] = new Bishop(false, 'b', 5, 7);

	this->board[3][7] = new Queen(false, 'q', 3, 7);
	this->board[4][7] = new King(false, 'k', 4, 7);

	for (int i = 0; i < 8; i++)
		this->board[i][6] = new Pawn(false, 'p', i, 6);

	for (int i = 2; i < 6; i++)		//�� �������� ��������� ������ �� ����� "����"
		for (int j = 0; j < 7; j++)
			this->board[i][j] = NULL;
}

bool Chessboard::move(int x, int y, int finX, int finY) {
	if (this->board[x][y]->checkMove(finX, finY) && this->pathCheck(finX, finY, this->board[x][y])) {
		//������� ��� �� ��������� ���������� ����� ���� � �������� �������� �������
		if (isupper((this->board[finX][finY]->getLetter())) == isupper(this->board[x][y]->getLetter()) ||
			this->board[finX][finY] == NULL) {
			//������� ��� � ������ ���� �� �������� �� ��� ��� ����� ��� ������
			Piece* test = this->board[finX][finY];
			this->board[finX][finY] = this->board[x][y];
			this->board[x][y] = NULL;
			if (this->kingChecked()) {		//��������� ��������� �� ��������� ���
				this->board[x][y] = this->board[finX][finY];
				this->board[finX][finY] = test;
				return false;
			}

			this->board[finX][finY]->setPosX(finX);
			this->board[finX][finY]->setPosY(finY);
			this->board[finX][finY]->setHasMoved(true);
			return true;
		}
	}
	else
		return false;
}

void Chessboard::showBoard() {
	system("chcp 65001");	//��� ��� ���������� unicode ����������
	//������ ����� ������ �������
	cout << ( char) 218;	//�
	for (int i = 0; i < 16; i++) {
		if (i % 2 == 0)
			cout << ( char) 196;	//-
		else
			cout << ( char) 194;	//T

		cout << ( char) 191 << endl;
	}
	//������ ���������
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 16; j++) {
			if (i % 2 != 0)
				if (j == 0)
					cout << ( char) 195;
				else if (j == 16)
					cout << ( char) 180;
				else if (j % 2 == 0)
					cout << ( char) 196;	//-
				else
					cout << ( char) 197;	//+
			else
				if (j % 2 == 0)
					cout << ( char) 179;	//|
				else if (this->board[i / 2][j / 2] == NULL)
					cout << "  ";
				else
					cout << this->board[i / 2][j / 2]->getLetter() << " ";

			cout << endl;
		}

	system("chcp 1253");

	//������ ���� ����� ���������� �������
	cout << ( char) 192;	//L
	for (int i = 0; i < 16; i++)
		if (i % 2 == 0)
			cout << ( char) 196;	//-
		else
			cout << ( char) 193;

	cout << ( char) 217 << endl;

	cout << " A B C D E F G H" << endl;
}

bool Chessboard::pathCheck(int x, int y, Piece* p) {
	if (p->getPosX() == x) {	//�������� ������
		if (p->getPosY() < y) {	//���� �� ����
			for (int j = p->getPosY(); j < y; j++)
				if (this->board[x][j] != NULL)	//������� �� ��� ��������� ��������� ��� ����� ����
					return false;
		}
		else {	//���� �� ����
			for (int j = p->getPosY(); j > y; j--)
				if (this->board[x][j] != NULL)
					return false;
		}
	}
	else if (p->getPosY() == y) {	//�������� ���������
		if (p->getPosX() < x) {	//���� �� �����
			for (int i = p->getPosX(); i < x; i++)
				if (this->board[i][y] != NULL)
					return false;
		}
		else {	//���� �� ��������
			for (int i = p->getPosX(); i > x; i--)
				if (this->board[i][y] != NULL)
					return false;
		}
	}
	else {	//�������� ������
		if (p->getPosX() < x && p->getPosY() < y) {	//���� �����
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else if (p->getPosX() > x && p->getPosY() < y) {	//���� ��������
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else if (p->getPosX() < x && p->getPosY() > y) {	//���� �����
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else {	//���� ��������
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
	}
	return true;
}

bool Chessboard::kingChecked() {
	int kx, ky;
	for (int i = 0; i < 7; i++)				//������ �������
		for (int j = 0; j < 7; j++)
			if (this->board[i][j]->getLetter() == 'K' && this->whiteTurn) {
				kx = i;
				ky = j;
				break;
			}
			else if (this->board[i][j]->getLetter() == 'k' && !this->whiteTurn) {
				kx = i;
				ky = j;
				break;
			}

	for (int i = 0; i < 7; i++)				//������� ��� ������ �������� ������ "������" ��� �������
		for (int j = 0; j < 7; j++)
			if (this->board[i][j] != NULL && this->whiteTurn && isupper(this->board[i][j]->getLetter())) {
				//� ����� ��� ���������� ������ ���������
				if (this->board[i][j]->getLetter() == 'N' && this->board[i][j]->checkMove(kx, ky))
					return true;
				else if (this->board[i][j]->checkMove(kx, ky) && this->pathCheck(kx, ky, this->board[i][j]))
					return true;
			}
			else if (this->board[i][j] != NULL && !this->whiteTurn && islower(this->board[i][j]->getLetter())) {
				if (this->board[i][j]->getLetter() == 'n' && this->board[i][j]->checkMove(kx, ky))
					return true;
				else if (this->board[i][j]->checkMove(kx, ky) && this->pathCheck(kx, ky, this->board[i][j]))
					return true;
			}

	return false;
}

bool Chessboard::castle(bool kingside) {
	if (kingside) {		//����� ����
		if (whiteTurn) {
			//������� ��� � �������� ��� � ������ ���������� ���� ������� ���� ������ ��� ��� ����� ��������
			if (this->board[7][0] != NULL && this->board[7][0]->getLetter() == 'R' && !this->board[7][0]->getHasMoved() &&
				this->board[4][0] != NULL && this->board[4][0]->getLetter() == 'K' && !this->board[4][0]->getHasMoved() &&
				!this->kingChecked()) {			//� �������� ��� ����� �� ���
				if (this->board[5][0] != NULL || this->board[6][0] != NULL)	//������� ��� �� ��������� ��������� ����� ��������
					return false;
				//������� ��� �� ��������� ��������� �����������
				for (int i = 0; i < 7; i++)
					for (int j = 0; j < 7; j++)
						if (this->board[i][j] != NULL && isupper(this->board[i][j]->getLetter())) {
							if (this->board[i][j]->getLetter() == 'N' && (this->board[i][j]->checkMove(6, 0) ||
								this->board[i][j]->checkMove(5, 0)))
								return false;
							else if (this->board[i][j]->checkMove(6, 0) && this->pathCheck(6, 0, this->board[i][j]))
								return false;
						}
			}
			else {
				//���������� �������
				this->board[4][0]->setPosX(6);
				this->board[6][0] = this->board[4][0];
				this->board[6][0]->setHasMoved(true);
				this->board[4][0] = NULL;

				//���������� ������
				this->board[7][0]->setPosX(7);
				this->board[5][0] = this->board[7][0];
				this->board[5][0]->setHasMoved(true);
				this->board[7][0] = NULL;
			}
		}
		else
			if (this->board[7][7] != NULL && this->board[7][7]->getLetter() == 'r' && !this->board[7][7]->getHasMoved() &&
				this->board[4][7] != NULL && this->board[4][7]->getLetter() == 'k' && !this->board[4][7]->getHasMoved() &&
				!this->kingChecked()) {
				if (this->board[5][7] != NULL || this->board[6][7] != NULL)
					return false;
				for (int i = 0; i < 7; i++)
					for (int j = 0; j < 7; j++)
						if (this->board[i][j] != NULL && isupper(this->board[i][j]->getLetter())) {
							if (this->board[i][j]->getLetter() == 'n' && (this->board[i][j]->checkMove(6, 7) ||
								this->board[i][j]->checkMove(5, 7)))
								return false;
							else if (this->board[i][j]->checkMove(6, 7) && this->pathCheck(6, 7, this->board[i][j]))
								return false;
						}
			}
			else {
				this->board[4][7]->setPosX(6);
				this->board[6][7] = this->board[4][7];
				this->board[6][7]->setHasMoved(true);
				this->board[4][7] = NULL;

				this->board[7][7]->setPosX(7);
				this->board[5][7] = this->board[7][7];
				this->board[5][7]->setHasMoved(true);
				this->board[7][7] = NULL;
			}
	}
	else {	//������ ����
		if (whiteTurn) {
			//������� ��� � �������� ��� � ������ ���������� ���� ������� ���� ������ ��� ��� ����� ��������
			if (this->board[0][0] != NULL && this->board[0][0]->getLetter() == 'R' && !this->board[0][0]->getHasMoved() &&
				this->board[4][0] != NULL && this->board[4][0]->getLetter() == 'K' && !this->board[4][0]->getHasMoved() &&
				!this->kingChecked()) {			//� �������� ��� ����� �� ���
				if (this->board[1][0] != NULL || this->board[2][0] != NULL || this->board[3][0] != NULL)	//������� ��� �� ��������� ��������� ����� ��������
					return false;
				//������� ��� �� ��������� ��������� �����������
				for (int i = 0; i < 7; i++)
					for (int j = 0; j < 7; j++)
						if (this->board[i][j] != NULL && isupper(this->board[i][j]->getLetter())) {
							if (this->board[i][j]->getLetter() == 'N' && (this->board[i][j]->checkMove(1, 0) ||
								this->board[i][j]->checkMove(2, 0) || this->board[i][j]->checkMove(3, 0)))
								return false;
							else if (this->board[i][j]->checkMove(6, 0) && this->pathCheck(6, 0, this->board[i][j]))
								return false;
						}
			}
			else {
				//���������� �������
				this->board[4][0]->setPosX(2);
				this->board[2][0] = this->board[4][0];
				this->board[2][0]->setHasMoved(true);
				this->board[4][0] = NULL;

				//���������� ������
				this->board[0][0]->setPosX(3);
				this->board[3][0] = this->board[0][0];
				this->board[3][0]->setHasMoved(true);
				this->board[0][0] = NULL;
			}
		}
		else
			if (this->board[0][7] != NULL && this->board[0][7]->getLetter() == 'r' && !this->board[0][7]->getHasMoved() &&
				this->board[4][7] != NULL && this->board[4][7]->getLetter() == 'k' && !this->board[4][7]->getHasMoved() &&
				!this->kingChecked()) {
				if (this->board[1][7] != NULL || this->board[2][7] != NULL || this->board[3][0] != NULL)
					return false;
				for (int i = 0; i < 7; i++)
					for (int j = 0; j < 7; j++)
						if (this->board[i][j] != NULL && isupper(this->board[i][j]->getLetter())) {
							if (this->board[i][j]->getLetter() == 'n' && (this->board[i][j]->checkMove(1, 7) ||
								this->board[i][j]->checkMove(2, 7) || this->board[i][j]->checkMove(3, 7)))
								return false;
							else if (this->board[i][j]->checkMove(6, 7) && this->pathCheck(6, 7, this->board[i][j]))
								return false;
						}
			}
			else {
				this->board[4][7]->setPosX(2);
				this->board[2][7] = this->board[4][7];
				this->board[2][7]->setHasMoved(true);
				this->board[4][7] = NULL;

				this->board[0][7]->setPosX(3);
				this->board[3][7] = this->board[7][7];
				this->board[3][7]->setHasMoved(true);
				this->board[0][7] = NULL;
			}
	}
}

bool Chessboard::checkmate() {
	if (!this->kingChecked())	//��� ������� ��� ����� �� ���������� � ��������
		return false;

	int kx, ky;
	for (int i = 0; i < 7; i++)				//������ �������
		for (int j = 0; j < 7; j++)
			if (this->board[i][j]->getLetter() == 'K' && this->whiteTurn) {
				kx = i;
				ky = j;
				break;
			}
			else if (this->board[i][j]->getLetter() == 'k' && !this->whiteTurn) {
				kx = i;
				ky = j;
				break;
			}

	//������� ��� � �������� ������ �� ��������
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (this->board[kx][ky]->checkMove(kx + i, ky + j) &&
				this->pathCheck(kx + i, ky + j, this->board[kx][ky])) {
				//������� ��� � ������ ���� �� �������� �� ��� ��� ����� ��� ������
				Piece* test = this->board[kx][ky];
				this->board[kx + i][ky + j] = this->board[kx][ky];
				this->board[kx][ky] = NULL;
				if (!this->kingChecked()) {		//��������� ��������� �� ��������� ���
					this->board[kx][ky] = this->board[kx + i][ky + j];
					this->board[kx + i][ky + j] = test;
					return false;
				}
				else {
					//���������
					this->board[kx][ky] = this->board[kx + i][ky + j];
					this->board[kx + i][ky + j] = test;
				}
			}

	//������� ��� ������ ������� ������ �� ����������� ��� �������
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			if (this->board[i][j] != NULL &&
				(this->board[i][j]->getLetter() != 'K' && this->board[i][j]->getLetter() != 'k') &&
				isupper(this->board[i][j]->getLetter()) == isupper(this->board[kx][ky]->getLetter()))
				for (int x = 0; x < 7; x++)
					for (int y = 0; y < 7; y++)
						if (this->board[i][j]->checkMove(x, y) && this->pathCheck(x, y, this->board[i][j])) {
							Piece* test = this->board[i][j];
							this->board[x][y] = this->board[i][j];
							this->board[i][j] = NULL;
							if (!this->kingChecked()) {		//��������� ��������� �� ��������� ���
								this->board[i][j] = this->board[x][y];
								this->board[x][y] = test;
								return false;
							}
							else {
								//���������
								this->board[i][j] = this->board[x][y];
								this->board[x][y] = test;
							}
						}

	return true;
}

bool Chessboard::stalemate() {
	if (this->kingChecked())	//��� � �������� ���������� ���� �������� ��� ������� ���
		return false;

	//������� ��� ������� ����������� ��������� ������
	if (this->whiteTurn) {
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 7; j++)
				if (this->board[i][j] != NULL && isupper(this->board[i][j]->getLetter()))
					for (int x = 0; x < 7; x++)
						for (int y = 0; y < 7; y++)
							if (this->board[i][j]->checkMove(x, y) && this->pathCheck(x, y, this->board[i][j])) {
								Piece* test = this->board[x][y];
								this->board[x][y] = this->board[i][j];
								this->board[i][j] = NULL;
								if (this->kingChecked()) {
									this->board[i][j] = this->board[x][y];
									this->board[x][y] = test;
								}
								else
									return false;
							}
		return true;
	}
	else
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 7; j++)
				if (this->board[i][j] != NULL && islower(this->board[i][j]->getLetter()))
					for (int x = 0; x < 7; x++)
						for (int y = 0; y < 7; y++)
							if (this->board[i][j]->checkMove(x, y) && this->pathCheck(x, y, this->board[i][j])) {
								Piece* test = this->board[x][y];
								this->board[x][y] = this->board[i][j];
								this->board[i][j] = NULL;
								if (this->kingChecked()) {
									this->board[i][j] = this->board[x][y];
									this->board[x][y] = test;
								}
								else
									return false;
							}
	return true;
}

void Chessboard::promotion(int m, Pawn* pawn) {
	if (pawn->getLetter() == 'P') {
		if (m == 1)			//�������� �� ���������
			this->board[pawn->getPosX()][pawn->getPosY()] = new Queen(false, 'Q', pawn->getPosX(), pawn->getPosY());
		else if (m == 2)	//�������� �� �����
			this->board[pawn->getPosX()][pawn->getPosY()] = new Rook(false, 'R', pawn->getPosX(), pawn->getPosY());
		else if (m == 3)	//�������� �� ����������
			this->board[pawn->getPosX()][pawn->getPosY()] = new Queen(false, '�', pawn->getPosX(), pawn->getPosY());
		else				//�������� �� ����
			this->board[pawn->getPosX()][pawn->getPosY()] = new Queen(false, '�', pawn->getPosX(), pawn->getPosY());
	}
	else {
		if (m == 1)
			this->board[pawn->getPosX()][pawn->getPosY()] = new Queen(false, 'q', pawn->getPosX(), pawn->getPosY());
		else if (m == 2)
			this->board[pawn->getPosX()][pawn->getPosY()] = new Rook(false, 'r', pawn->getPosX(), pawn->getPosY());
		else if (m == 3)
			this->board[pawn->getPosX()][pawn->getPosY()] = new Queen(false, 'b', pawn->getPosX(), pawn->getPosY());
		else
			this->board[pawn->getPosX()][pawn->getPosY()] = new Queen(false, 'n', pawn->getPosX(), pawn->getPosY());
	}
	delete pawn;
}