#pragma once
class Piece {
private:
	bool isAlive;
	bool hasMoved;
	int posX;
	int posY;
public:
	virtual bool isMoveElgbl() = 0;		//ελεγχος εγκυρης κινησης
};