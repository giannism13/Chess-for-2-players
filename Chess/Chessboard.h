#pragma once
#include "Piece.h"
#include <math.h>
#include <cctype>
#include <fstream>
using namespace std;

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
	bool castle(bool);					//������� ��� ������������ ��� ���� ��� �� �������������
	bool checkmate();					//������� ��� ������� ���
	bool stalemate();					//������� ��� ������� ���
	void promotion(int, Piece*);		//������� ����� �� ������ �������� ��� ������
	void save(string);					//���������� �� ������ �� ������
	void load(string);					//�������� ��� ������ ��� ������;

	//Accessors 
	bool getWhiteTurn();
	void setWhiteTurn(bool);
};