#pragma once
#include "Piece.h"
#include "Rook.h"

class Chessboard {
private:
	Piece* board[8][8];		//������� ���������
public:
	Chessboard();	//default constructor
};