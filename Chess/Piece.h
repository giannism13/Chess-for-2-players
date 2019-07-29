#ifndef Piece_h
#define Piece_h
#include <math.h>
#include <iostream>
using namespace std;

class Piece {
protected:
	bool hasMoved;
	char letter;
	int posX;
	int posY;

public:
	Piece(bool, char, int ,int);		//Constructor
	Piece();
	Piece(const Piece&);


	bool checkMove(int, int);	//������� ������� �������
	
	//accessor functions
	void setHasMoved(bool);
	void setPosX(int);
	void setPosY(int);
	void setletter(char);

	bool getHasMoved();
	int getPosX();
	int getPosY();
	char getLetter();
};
#endif
