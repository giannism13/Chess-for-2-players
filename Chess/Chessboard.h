#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

class Chessboard {
private:
	Piece* board[8][8];		//������� ���������
public:
	Chessboard();	//default constructor ��� ��� ��������
	void move(int ,int);	//��������� �� �������� ��� ��������
	void showBoard();	//��������� ��� �������� ��������� ��� ���������
};