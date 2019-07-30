#include "Piece.h"

Piece::Piece(bool hasMoved, char letter, int posX, int posY) {
	this->hasMoved = hasMoved;
	this->letter = letter;
	this->posX = posX;
	this->posY = posY;
}

Piece::Piece() {
	this->hasMoved = false;
	this->letter = ' ';
	this->posX = 0;
	this->posY = 0;
}

Piece::Piece(const Piece& copy) {
	this->hasMoved = copy.hasMoved;
	this->posX = copy.posX;
	this->posY = copy.posY;
	this->letter = copy.letter;
}

bool Piece::checkMove(int x, int y) {
	//cout << x << " " << y << endl;								//DEBUG
	//cout << "here1" << endl;										//DEBUG
	//cout << this->getPosX() << " " << this->getPosY() << endl;	//DEBUG
	//cout << "here" << endl;										//DEBUG
	//cout << this->getLetter();									//DEBUG
	if (this->letter == 'R' || this->letter == 'r') {	//πυργος
		if (x == this->posX || y == this->posY)
			return true;
		else
			return false;
	}
	else if (this->letter == 'N' || this->letter == 'n') {	//ιππος
		if ((abs(x - this->posX) == 2 && abs(y - this->posY) == 1) ||
			(abs(x - this->posX) == 1 && abs(y - this->posY) == 2))
			return true;
		else
			return false;
	}
	else if (this->letter == 'B' || this->letter == 'b') {	//αξιωματικος
		if (abs(x - this->posX) == abs(y - this->posY))
			return true;
		else
			return false;
	}
	else if (this->letter == 'K' || this->letter == 'k') {	//βασιλιας
		if (abs(x - this->posX) <= 1 && abs(y - this->posX) <= 1)
			return true;
		else
			return false;
	}
	else if (this->letter == 'Q' || this->letter == 'q') {	//βασιλισσα
		if ((x == this->posX || y == this->posY) || (abs(x - this->posX) == abs(y - this->posY)))
			return true;
		else
			return false;
	}
	else {									//πιονι
		if (isupper(this->letter)) {		//λευκο
			cout << "pioni" << endl;		//DEBUG
			if (!this->hasMoved && this->posX == x && y - this->posY <= 2){			
				return true;
			}
			else if (abs(this->posX - x) <= 1 && y - this->posY == 1){			
				return true;				//DEBUG
			}
		}
		else {								//μαυρο
			if (!this->hasMoved && this->posX == x && this->posY - y <= 2)
				return true;
			else if (abs(this->posX - x) <= 1 && this->posY - y == 1)
				return true;
		}
		cout << "false" << endl;			//DEBUG
		return false;
	}
}

void Piece::setHasMoved(bool moved) {
	this->hasMoved = moved;
}

void Piece::setPosX(int x) {
	this->posX = x;
}

void Piece::setPosY(int y) {
	this->posY = y;
}

void Piece::setletter(char letter) {
	this->letter = letter;
}

bool Piece::getHasMoved() { return this->hasMoved; }

int Piece::getPosX() { return this->posX; }

int Piece::getPosY() { return this->posY; }

char Piece::getLetter() { return this->letter; }
