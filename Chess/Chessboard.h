#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include <math.h>
#include <cctype>

class Chessboard {
private:
	Piece* board[8][8];		//������� ���������
	bool whiteTurn;			//����� ������;
public:
	Chessboard();						//default constructor ��� ��� ��������
	bool move(int ,int, int, int);		//��������� �� �������� ��� ��������
	void showBoard();					//��������� ��� �������� ��������� ��� ���������
	bool pathCheck(int, int, Piece*);	//������� ��� � �������� ���� �������� (���� �����) ����� ��������
	bool kingChecked();					//������� ��� � �������� ����� �� ���
};