#include "Chessboard.h"

Chessboard::Chessboard() {
	this->whiteTurn = true;	//����� ������ � ������
	//�����
	this->board[0][0] = new Piece(false, 'R', 0, 0);
	this->board[7][0] = new Piece(false, 'R', 7, 0);

	this->board[1][0] = new Piece(false, 'N', 1, 0);
	this->board[6][0] = new Piece(false, 'N', 6, 0);

	this->board[2][0] = new Piece(false, 'B', 2, 0);
	this->board[5][0] = new Piece(false, 'B', 5, 0);

	this->board[3][0] = new Piece(false, 'K', 3, 0);
	this->board[4][0] = new Piece(false, 'Q', 4, 0);

	for (int i = 0; i < 8; ++i)
		this->board[i][1] = new Piece(false, 'P', i, 1);

	//�����
	this->board[0][7] = new Piece(false, 'r', 0, 7);
	this->board[7][7] = new Piece(false, 'r', 7, 7);

	this->board[1][7] = new Piece(false, 'n', 1, 7);
	this->board[6][7] = new Piece(false, 'n', 6, 7);

	this->board[2][7] = new Piece(false, 'b', 2, 7);
	this->board[5][7] = new Piece(false, 'b', 5, 7);

	this->board[3][7] = new Piece(false, 'k', 3, 7);
	this->board[4][7] = new Piece(false, 'q', 4, 7);

	for (int i = 0; i < 8; ++i)
		this->board[i][6] = new Piece(false, 'p', i, 6);

	for (int i = 0; i < 8; i++)		//�� �������� ��������� ������ �� ����� "����"
		for (int j = 2; j < 6; j++)
			this->board[i][j] = new Piece();		
}

bool Chessboard::move(char x, char y, char finX, char finY) {
	int ix = x - '0';
	int iy = y - '0';
	int ifinX = finX - '0';
	int ifinY = finY - '0';
	if (this->board[ix][iy]->getLetter() == 'e'){		//������� ��� � ������� ������� ���� ��������� ���� ����������
		return false;
	}
	
	//������� ��� � ������� ������� ������ ��� ��������� ���� ����������
	if (this->getWhiteTurn() && islower(this->board[ix][iy]->getLetter()))
		return false;
	else if (!this->getWhiteTurn() && isupper(this->board[ix][iy]->getLetter()))
		return false;
	cout << "Move called for: " << this->board[ix][iy]->getLetter() << endl;
	if (this->board[ix][iy]->checkMove(ifinX, ifinY) && this->pathCheck(ifinX, ifinY, this->board[ix][iy])) {
		//������� ��� �� ��������� ���������� ����� ���� � �������� �������� �������
		if (this->board[ifinX][ifinY]->getLetter() == 'e' || isupper((this->board[ifinX][ifinY]->getLetter())) != isupper(this->board[ix][iy]->getLetter())) {
			//������� ��� � ������ ���� �� �������� �� ��� ��� ����� ��� ������
			Piece* test = this->board[ifinX][ifinY];
			this->board[ifinX][ifinY] = this->board[ix][iy];
			this->board[ix][iy] = new Piece();
			if (this->kingChecked()) {		//��������� ��������� �� ��������� ���
				this->board[ix][iy] = new Piece(*this->board[ifinX][ifinY]);
				this->board[ifinX][ifinY] = test;
				return false;
			}
			this->board[ix][iy] = new Piece(*this->board[ifinX][ifinY]);	//��������� ���������
			this->board[ifinX][ifinY] = test;

			//���������� ���������
			this->board[ifinX][ifinY] = new Piece(true, this->board[ix][iy]->getLetter(), ifinX, ifinY);
			this->board[ifinX][ifinY]->setPosX(ifinX);
			this->board[ifinX][ifinY]->setPosY(ifinY);
			this->board[ifinX][ifinY]->setHasMoved(true);
			this->board[ix][iy] = new Piece();
			return true;
		}
	}
	else{
		cout << "move failed" << endl;
		return false;
	}
}

void Chessboard::showBoard() {
	system("cls");
	cout << "   +---+---+---+---+---+---+---+---+" << endl;
	for (int y = 7; y >= 0; y--){
		cout << " " << y+1 << " |";
		for (int x = 7; x >= 0; x--) {
			if (this->board[x][y]->getLetter() != 'e')
				cout << " " << this->board[x][y]->getLetter() << " |";
			else
				cout << "   |";
		}
		cout << endl;
		cout << "   +---+---+---+---+---+---+---+---+" << endl;
	}
	cout << "     A   B   C   D   E   F   G   H " << endl;
	cin.clear();
	fflush(stdin);
}

bool Chessboard::pathCheck(int x, int y, Piece* p) {
	//������� ������� ��� ������
	if (p->getLetter() == 'P') {
		if (p->getPosX() == x && this->board[x][y]->getLetter() == 'e'){
			return true;
		}
		else if (x == p->getPosX() + 1 && y == p->getPosY() + 1 && this->board[p->getPosX() + 1][p->getPosY() + 1]->getLetter() != 'e' &&
			islower(this->board[p->getPosX() + 1][p->getPosY() + 1]->getLetter())){
			return true;
		}
		else if (x == p->getPosX() - 1 && y == p->getPosY() + 1 && this->board[p->getPosX() - 1][p->getPosY() + 1]->getLetter() != 'e' &&
			islower(this->board[p->getPosX() + 1][p->getPosY() + 1]->getLetter())){
			return true;
		}
		else{
			return false;
		}
	}
	else if (p->getLetter() == 'p') {
		if (p->getPosX() == x && this->board[x][y]->getLetter() == 'e')
			return true;
		else if (x == p->getPosX() + 1 && y == p->getPosY() - 1 && this->board[p->getPosX() + 1][p->getPosY() - 1]->getLetter() != 'e' &&
			isupper(this->board[p->getPosX() + 1][p->getPosY() - 1]->getLetter()))
			return true;
		else if (x == p->getPosX() - 1 && y == p->getPosY() - 1 && this->board[p->getPosX() - 1][p->getPosY() + 1]->getLetter() != 'e' &&
			isupper(this->board[p->getPosX() + 1][p->getPosY() - 1]->getLetter()))
			return true;
		else
			return false;
	}

	if (p->getPosX() == x) {	//�������� ������
		if (p->getPosY() < y) {	//���� �� ����
			for (int j = p->getPosY(); j < y; j++)
				if (this->board[x][j]->getLetter() != 'e'){	//������� �� ��� ��������� ��������� ��� ����� ����
					return false;
				}
		}
		else {	//���� �� ����
			for (int j = p->getPosY(); j > y; j--)
				if (this->board[x][j]->getLetter() != 'e')
					return false;
		}
	}
	else if (p->getPosY() == y) {	//�������� ���������
		if (p->getPosX() < x) {	//���� �� �����
			for (int i = p->getPosX(); i < x; i++)
				if (this->board[i][y]->getLetter() != 'e')
					return false;
		}
		else {	//���� �� ��������
			for (int i = p->getPosX(); i > x; i--)
				if (this->board[i][y]->getLetter() != 'e')
					return false;
		}
	}
	else {	//�������� ������
		if (p->getPosX() < x && p->getPosY() < y) {	//���� �����
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i]->getLetter() != 'e')
					return false;
		}
		else if (p->getPosX() > x && p->getPosY() < y) {	//���� ��������
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i]->getLetter() != 'e')
					return false;
		}
		else if (p->getPosX() < x && p->getPosY() > y) {	//���� �����
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i]->getLetter() != 'e')
					return false;
		}
		else {	//���� ��������
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i]->getLetter() != 'e')
					return false;
		}
	}
	return true;
}

bool Chessboard::kingChecked() {
	int kx, ky;
	for (int i = 0; i < 8; i++)				//������ �������
		for (int j = 0; j < 8; j++)
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

	for (int i = 0; i < 8; i++)				//������� ��� ������ �������� ������ "������" ��� �������
		for (int j = 0; j < 8 ; j++)
			if (this->board[i][j]->getLetter() != 'e' && this->whiteTurn && islower(this->board[i][j]->getLetter())) {
				//� ����� ��� ���������� ������ ���������
				if (this->board[i][j]->getLetter() == 'N' && this->board[i][j]->checkMove(kx, ky))
					return true;
				else if (this->board[i][j]->checkMove(kx, ky) && this->pathCheck(kx, ky, this->board[i][j]))
					return true;
			}
			else if (this->board[i][j]->getLetter() != 'e' && !this->whiteTurn && isupper(this->board[i][j]->getLetter())) {
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
			if (this->board[7][0]->getLetter() != 'e' && this->board[7][0]->getLetter() == 'R' && !this->board[7][0]->getHasMoved() &&
				this->board[4][0]->getLetter() != 'e' && this->board[4][0]->getLetter() == 'K' && !this->board[4][0]->getHasMoved() &&
				!this->kingChecked()) {			//� �������� ��� ����� �� ���
				if (this->board[5][0]->getLetter() != 'e' || this->board[6][0]->getLetter() != 'e')	//������� ��� �� ��������� ��������� ����� ��������
					return false;
				//������� ��� �� ��������� ��������� �����������
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (this->board[i][j]->getLetter() != 'e' && isupper(this->board[i][j]->getLetter())) {
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
				this->board[4][0] = new Piece();

				//���������� ������
				this->board[7][0]->setPosX(7);
				this->board[5][0] = this->board[7][0];
				this->board[5][0]->setHasMoved(true);
				this->board[7][0] = new Piece();
			}
		}
		else
			if (this->board[7][7]->getLetter()!= 'e' && this->board[7][7]->getLetter() == 'r' && !this->board[7][7]->getHasMoved() &&
				this->board[4][7]->getLetter()!= 'e' && this->board[4][7]->getLetter() == 'k' && !this->board[4][7]->getHasMoved() &&
				!this->kingChecked()) {
				if (this->board[5][7]->getLetter()!= 'e' || this->board[6][7]->getLetter()!= 'e')
					return false;
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (this->board[i][j]->getLetter() != 'e' && isupper(this->board[i][j]->getLetter())) {
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
				this->board[4][7] = new Piece();

				this->board[7][7]->setPosX(7);
				this->board[5][7] = this->board[7][7];
				this->board[5][7]->setHasMoved(true);
				this->board[7][7] = new Piece();
			}
	}
	else {	//������ ����
		if (whiteTurn) {
			//������� ��� � �������� ��� � ������ ���������� ���� ������� ���� ������ ��� ��� ����� ��������
			if (this->board[0][0]->getLetter()!= 'e' && this->board[0][0]->getLetter() == 'R' && !this->board[0][0]->getHasMoved() &&
				this->board[4][0]->getLetter()!= 'e' && this->board[4][0]->getLetter() == 'K' && !this->board[4][0]->getHasMoved() &&
				!this->kingChecked()) {			//� �������� ��� ����� �� ���
				if (this->board[1][0]->getLetter()!= 'e' || this->board[2][0]->getLetter()!= 'e' || this->board[3][0]->getLetter()!= 'e')	//������� ��� �� ��������� ��������� ����� ��������
					return false;
				//������� ��� �� ��������� ��������� �����������
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (this->board[i][j]->getLetter() != 'e' && isupper(this->board[i][j]->getLetter())) {
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
				this->board[4][0] = new Piece();

				//���������� ������
				this->board[0][0]->setPosX(3);
				this->board[3][0] = this->board[0][0];
				this->board[3][0]->setHasMoved(true);
				this->board[0][0] = new Piece();
			}
		}
		else
			if (this->board[0][7]->getLetter()!= 'e' && this->board[0][7]->getLetter() == 'r' && !this->board[0][7]->getHasMoved() &&
				this->board[4][7]->getLetter()!= 'e' && this->board[4][7]->getLetter() == 'k' && !this->board[4][7]->getHasMoved() &&
				!this->kingChecked()) {
				if (this->board[1][7]->getLetter()!= 'e' || this->board[2][7]->getLetter()!= 'e' || this->board[3][0]->getLetter()!= 'e')
					return false;
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (this->board[i][j]->getLetter() != 'e' && isupper(this->board[i][j]->getLetter())) {
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
				this->board[4][7] = new Piece();

				this->board[0][7]->setPosX(3);
				this->board[3][7] = this->board[7][7];
				this->board[3][7]->setHasMoved(true);
				this->board[0][7] = new Piece();
			}
	}
}

bool Chessboard::checkmate() {
	if (!this->kingChecked())	//��� ������� ��� ����� �� ���������� � ��������
		return false;

	int kx, ky;
	for (int i = 0; i < 8; i++)				//������ �������
		for (int j = 0; j < 8; j++)
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
				this->board[kx][ky] = new Piece();
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
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (this->board[i][j]->getLetter() != 'e' &&
				(this->board[i][j]->getLetter() != 'K' && this->board[i][j]->getLetter() != 'k') &&
				isupper(this->board[i][j]->getLetter()) == isupper(this->board[kx][ky]->getLetter()))
				for (int x = 0; x < 8; x++)
					for (int y = 0; y < 8; y++)
						if (this->board[i][j]->checkMove(x, y) && this->pathCheck(x, y, this->board[i][j])) {
							Piece* test = this->board[i][j];
							this->board[x][y] = this->board[i][j];
							this->board[i][j] = new Piece();
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
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (this->board[i][j]->getLetter() != 'e' && isupper(this->board[i][j]->getLetter()))
					for (int x = 0; x < 8; x++)
						for (int y = 0; y < 8; y++)
							if (this->board[i][j]->checkMove(x, y) && this->pathCheck(x, y, this->board[i][j])) {
								Piece* test = this->board[x][y];
								this->board[x][y] = this->board[i][j];
								this->board[i][j] = new Piece();
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
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (this->board[i][j]->getLetter() != 'e' && islower(this->board[i][j]->getLetter()))
					for (int x = 0; x < 8; x++)
						for (int y = 0; y < 8; y++)
							if (this->board[i][j]->checkMove(x, y) && this->pathCheck(x, y, this->board[i][j])) {
								Piece* test = this->board[x][y];
								this->board[x][y] = this->board[i][j];
								this->board[i][j] = new Piece();
								if (this->kingChecked()) {
									this->board[i][j] = this->board[x][y];
									this->board[x][y] = test;
								}
								else
									return false;
							}
	return true;
}

void Chessboard::promotion(int m, Piece* pawn) {
	if (pawn->getLetter() == 'P') {
		if (m == 1)			//�������� �� ���������
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'Q', pawn->getPosX(), pawn->getPosY());
		else if (m == 2)	//�������� �� �����
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'R', pawn->getPosX(), pawn->getPosY());
		else if (m == 3)	//�������� �� ����������
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, '�', pawn->getPosX(), pawn->getPosY());
		else				//�������� �� ����
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, '�', pawn->getPosX(), pawn->getPosY());
	}
	else if (pawn->getLetter() == 'p') {
		if (m == 1)
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'q', pawn->getPosX(), pawn->getPosY());
		else if (m == 2)
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'r', pawn->getPosX(), pawn->getPosY());
		else if (m == 3)
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'b', pawn->getPosX(), pawn->getPosY());
		else
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'n', pawn->getPosX(), pawn->getPosY());
	}
	delete pawn;
}

bool Chessboard::getWhiteTurn() { return whiteTurn; }

void Chessboard::setWhiteTurn(bool whiteTurn) {
	this->whiteTurn = whiteTurn;
}

void Chessboard::save(string filename) {
	ofstream file;
	file.open(filename.c_str(), ios::binary);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			file.write((char*)this->board[i][j], sizeof(Piece));
	file.close();
}

void Chessboard::load(string filename) {
	ifstream file;
	Piece piece;
	file.open(filename.c_str(), ios::binary);
	while (file.read((char*)&piece, sizeof(Piece)))
		*this->board[piece.getPosX()][piece.getPosY()] = piece;
	file.close();
}
