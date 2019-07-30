#include "Chessboard.h"

Chessboard::Chessboard() {
	this->whiteTurn = true;	//πρωτα παιζει ο λευκος
	//λευκα
	this->board[0][0] = new Piece(false, 'R', 0, 0);
	this->board[7][0] = new Piece(false, 'R', 7, 0);

	this->board[1][0] = new Piece(false, 'N', 1, 0);
	this->board[6][0] = new Piece(false, 'N', 6, 0);

	this->board[2][0] = new Piece(false, 'B', 2, 0);
	this->board[5][0] = new Piece(false, 'B', 5, 0);

	this->board[3][0] = new Piece(false, 'K', 3, 0);
	this->board[4][0] = new Piece(false, 'Q', 4, 0);

	for (int i = 0; i < 8; i++)
		this->board[i][1] = new Piece(false, 'P', i, 1);

	//μαυρα
	this->board[0][7] = new Piece(false, 'r', 0, 7);
	this->board[7][7] = new Piece(false, 'r', 7, 7);

	this->board[1][7] = new Piece(false, 'n', 1, 7);
	this->board[6][7] = new Piece(false, 'n', 6, 7);

	this->board[2][7] = new Piece(false, 'b', 2, 7);
	this->board[5][7] = new Piece(false, 'b', 5, 7);

	this->board[3][7] = new Piece(false, 'k', 3, 7);
	this->board[4][7] = new Piece(false, 'q', 4, 7);

	for (int i = 0; i < 8; i++)
		this->board[i][6] = new Piece(false, 'p', i, 6);

	for (int i = 0; i < 8; i++)		//τα υπολοιπα τετραγωνα πρεπει να ειναι "κενα"
		for (int j = 2; j < 6; j++)
			//this->board[i][j] = new Piece(false, ' ', i, j);
			this->board[i][j] = NULL;		
}

bool Chessboard::move(int x, int y, int finX, int finY) {
	//cout << x << " " << y << " " << finX << " " << finY << endl;	//DEBUG
	if (this->board[x][y] == NULL){		//Ελεγχος εαν ο παικτης επελεξε κενο τετραγωνο προς μετακινηση
		cout << "false null" << endl;	//DEBUG
		return false;
	}
	
	if (this->board[x][y]->checkMove(finX, finY) && this->pathCheck(finX, finY, this->board[x][y])) {
		//ελεγχος εαν το τετραγωνο προορισμου ειναι κενο ή περιεχει αντιπαλα κοματια
		if (isupper((this->board[finX][finY]->getLetter())) == isupper(this->board[x][y]->getLetter()) ||
			this->board[finX][finY] == NULL) {
			//Ελεγχος εαν η κινηση αυτη θα οδηγουσε σε σαχ για αυτον που παιζει
			Piece* test = this->board[finX][finY];
			this->board[finX][finY] = this->board[x][y];
			this->board[x][y] = NULL;
			if (this->kingChecked()) {		//Επαναφορα σκακιερας σε περιπτωση σαχ
				this->board[x][y] = this->board[finX][finY];
				this->board[finX][finY] = test;
				cout << "false check" << endl;	//DEBUG
				return false;
			}

			this->board[finX][finY]->setPosX(finX);
			this->board[finX][finY]->setPosY(finY);
			this->board[finX][finY]->setHasMoved(true);
			cout << "move ok" << endl;
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
			if (this->board[x][y] != NULL)
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
	//Ειδικοι κανονες για πιονια
	if (p->getLetter() == 'P') {
		if (p->getPosX() == x && this->board[x][y] == NULL){
			//cout << "reeee1" << endl;		//DEBUG
			return true;
		}
		else if (x == p->getPosX() + 1 && y == p->getPosY() + 1 && this->board[p->getPosX() + 1][p->getPosY() + 1] != NULL &&
			islower(this->board[p->getPosX() + 1][p->getPosY() + 1]->getLetter())){
			//cout << "reeee2" << endl;		//DEBUG
			return true;
		}
		else if (x == p->getPosX() - 1 && y == p->getPosY() + 1 && this->board[p->getPosX() - 1][p->getPosY() + 1] != NULL &&
			islower(this->board[p->getPosX() + 1][p->getPosY() + 1]->getLetter())){
			//cout << "reeee3" << endl;		//DEBUG
			return true;
		}
		else{
			//cout << "reeee false" << endl;	//DEBUG
			return false;
		}
	}
	else if (p->getLetter() == 'p') {
		if (p->getPosX() == x && this->board[x][y] == NULL)
			return true;
		else if (x == p->getPosX() + 1 && y == p->getPosY() - 1 && this->board[p->getPosX() + 1][p->getPosY() - 1] != NULL &&
			isupper(this->board[p->getPosX() + 1][p->getPosY() - 1]->getLetter()))
			return true;
		else if (x == p->getPosX() - 1 && y == p->getPosY() - 1 && this->board[p->getPosX() - 1][p->getPosY() + 1] != NULL &&
			isupper(this->board[p->getPosX() + 1][p->getPosY() - 1]->getLetter()))
			return true;
		else
			return false;
	}

	if (p->getPosX() == x) {	//κινειται καθετα
		if (p->getPosY() < y) {	//προς τα πανω
			for (int j = p->getPosY(); j < y; j++)
				if (this->board[x][j] != NULL)	//ελεγχος αν ενα ενδιαμεσο τετραγωνο δεν ειναι κενο
					return false;
		}
		else {	//προς τα κατω
			for (int j = p->getPosY(); j > y; j--)
				if (this->board[x][j] != NULL)
					return false;
		}
	}
	else if (p->getPosY() == y) {	//κινειται οριζοντια
		if (p->getPosX() < x) {	//προς τα δεξια
			for (int i = p->getPosX(); i < x; i++)
				if (this->board[i][y] != NULL)
					return false;
		}
		else {	//προς τα αριστερα
			for (int i = p->getPosX(); i > x; i--)
				if (this->board[i][y] != NULL)
					return false;
		}
	}
	else {	//διαγωνια κινηση
		if (p->getPosX() < x && p->getPosY() < y) {	//πανω δεξια
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else if (p->getPosX() > x && p->getPosY() < y) {	//πανω αριστερα
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else if (p->getPosX() < x && p->getPosY() > y) {	//κατω δεξια
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
		else {	//κατω αριστερα
			for (int i = 1; i < abs(x - p->getPosX()); i++)
				if (this->board[p->getPosX() + i][p->getPosY() + i] != NULL)
					return false;
		}
	}
	return true;
}

bool Chessboard::kingChecked() {
	int kx, ky;
	for (int i = 0; i < 8; i++)				//Ευρεση βασιλια
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

	for (int i = 0; i < 8; i++)				//Ελεγχος εαν καποιο αντιπαλο κοματι "βλεπει" τον βασιλια
		for (int j = 0; j < 8 ; j++)
			if (this->board[i][j] != NULL && this->whiteTurn && isupper(this->board[i][j]->getLetter())) {
				//Ο ιππος δεν χρειαζεται ελεγχο διαδρομης
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
	if (kingside) {		//Μικρο ροκε
		if (whiteTurn) {
			//Ελεγχος εαν ο βασιλιας και ο πυργος βρισκονται στις αρχικες τους θεσεις και δεν εχουν κουνηθει
			if (this->board[7][0] != NULL && this->board[7][0]->getLetter() == 'R' && !this->board[7][0]->getHasMoved() &&
				this->board[4][0] != NULL && this->board[4][0]->getLetter() == 'K' && !this->board[4][0]->getHasMoved() &&
				!this->kingChecked()) {			//Ο βασιλιας δεν ειναι σε σαχ
				if (this->board[5][0] != NULL || this->board[6][0] != NULL)	//Ελεγχος εαν τα ενδιαμεσα τετραγωνα ειναι ελευθερα
					return false;
				//Ελεγχος εαν τα ενδιαμεσα τετραγωνα απειλουνται
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (this->board[i][j] != NULL && isupper(this->board[i][j]->getLetter())) {
							if (this->board[i][j]->getLetter() == 'N' && (this->board[i][j]->checkMove(6, 0) ||
								this->board[i][j]->checkMove(5, 0)))
								return false;
							else if (this->board[i][j]->checkMove(6, 0) && this->pathCheck(6, 0, this->board[i][j]))
								return false;
						}
			}
			else {
				//Μετακινηση βασιλια
				this->board[4][0]->setPosX(6);
				this->board[6][0] = this->board[4][0];
				this->board[6][0]->setHasMoved(true);
				this->board[4][0] = NULL;

				//Μετακινηση πυργου
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
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
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
	else {	//Μεγαλο ροκε
		if (whiteTurn) {
			//Ελεγχος εαν ο βασιλιας και ο πυργος βρισκονται στις αρχικες τους θεσεις και δεν εχουν κουνηθει
			if (this->board[0][0] != NULL && this->board[0][0]->getLetter() == 'R' && !this->board[0][0]->getHasMoved() &&
				this->board[4][0] != NULL && this->board[4][0]->getLetter() == 'K' && !this->board[4][0]->getHasMoved() &&
				!this->kingChecked()) {			//Ο βασιλιας δεν ειναι σε σαχ
				if (this->board[1][0] != NULL || this->board[2][0] != NULL || this->board[3][0] != NULL)	//Ελεγχος εαν τα ενδιαμεσα τετραγωνα ειναι ελευθερα
					return false;
				//Ελεγχος εαν τα ενδιαμεσα τετραγωνα απειλουνται
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (this->board[i][j] != NULL && isupper(this->board[i][j]->getLetter())) {
							if (this->board[i][j]->getLetter() == 'N' && (this->board[i][j]->checkMove(1, 0) ||
								this->board[i][j]->checkMove(2, 0) || this->board[i][j]->checkMove(3, 0)))
								return false;
							else if (this->board[i][j]->checkMove(6, 0) && this->pathCheck(6, 0, this->board[i][j]))
								return false;
						}
			}
			else {
				//Μετακινηση βασιλια
				this->board[4][0]->setPosX(2);
				this->board[2][0] = this->board[4][0];
				this->board[2][0]->setHasMoved(true);
				this->board[4][0] = NULL;

				//Μετακινηση πυργου
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
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
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
	if (!this->kingChecked())	//Δεν γινεται ματ χωρις να απειλειται ο βασιλιας
		return false;

	int kx, ky;
	for (int i = 0; i < 8; i++)				//Ευρεση βασιλια
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

	//Ελεγχος εαν ο βασιλιας μπορει να κουνηθει
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (this->board[kx][ky]->checkMove(kx + i, ky + j) &&
				this->pathCheck(kx + i, ky + j, this->board[kx][ky])) {
				//Ελεγχος εαν η κινηση αυτη θα οδηγουσε σε σαχ για αυτον που παιζει
				Piece* test = this->board[kx][ky];
				this->board[kx + i][ky + j] = this->board[kx][ky];
				this->board[kx][ky] = NULL;
				if (!this->kingChecked()) {		//Επαναφορα σκακιερας σε περιπτωση σαχ
					this->board[kx][ky] = this->board[kx + i][ky + j];
					this->board[kx + i][ky + j] = test;
					return false;
				}
				else {
					//Επαναφορα
					this->board[kx][ky] = this->board[kx + i][ky + j];
					this->board[kx + i][ky + j] = test;
				}
			}

	//Ελεγχος εαν καποιο κομματι μπορει να προστατεψει τον βασιλια
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (this->board[i][j] != NULL &&
				(this->board[i][j]->getLetter() != 'K' && this->board[i][j]->getLetter() != 'k') &&
				isupper(this->board[i][j]->getLetter()) == isupper(this->board[kx][ky]->getLetter()))
				for (int x = 0; x < 8; x++)
					for (int y = 0; y < 8; y++)
						if (this->board[i][j]->checkMove(x, y) && this->pathCheck(x, y, this->board[i][j])) {
							Piece* test = this->board[i][j];
							this->board[x][y] = this->board[i][j];
							this->board[i][j] = NULL;
							if (!this->kingChecked()) {		//Επαναφορα σκακιερας σε περιπτωση σαχ
								this->board[i][j] = this->board[x][y];
								this->board[x][y] = test;
								return false;
							}
							else {
								//Επαναφορα
								this->board[i][j] = this->board[x][y];
								this->board[x][y] = test;
							}
						}

	return true;
}

bool Chessboard::stalemate() {
	if (this->kingChecked())	//Εαν ο βασιλιας απειλειται τοτε προφανως δεν υπαρχει πατ
		return false;

	//Ελεγχος εαν υπαρχει οποιαδηποτε διαθεσιμη κινηση
	if (this->whiteTurn) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (this->board[i][j] != NULL && isupper(this->board[i][j]->getLetter()))
					for (int x = 0; x < 8; x++)
						for (int y = 0; y < 8; y++)
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
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (this->board[i][j] != NULL && islower(this->board[i][j]->getLetter()))
					for (int x = 0; x < 8; x++)
						for (int y = 0; y < 8; y++)
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

void Chessboard::promotion(int m, Piece* pawn) {
	if (pawn->getLetter() == 'P') {
		if (m == 1)			//Προαγωγη σε βασιλισσα
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'Q', pawn->getPosX(), pawn->getPosY());
		else if (m == 2)	//Προαγωγη σε πυργο
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'R', pawn->getPosX(), pawn->getPosY());
		else if (m == 3)	//Προαγωγη σε αξιωματικο
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'Β', pawn->getPosX(), pawn->getPosY());
		else				//Προαγωγη σε ιππο
			this->board[pawn->getPosX()][pawn->getPosY()] = new Piece(false, 'Ν', pawn->getPosX(), pawn->getPosY());
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
			if (this->board[i][j] != NULL)
				file.write(reinterpret_cast<char*>(&this->board[i][j]), sizeof(this->board[i][j]));
	file.close();
}

void Chessboard::load(string filename) {
	ifstream file;
	Piece* piece;
	file.open(filename.c_str(), ios::binary);
	while (file.read(reinterpret_cast<char*>(&piece), sizeof(piece)))
		this->board[piece->getPosX()][piece->getPosY()] = piece;
	file.close();
}
