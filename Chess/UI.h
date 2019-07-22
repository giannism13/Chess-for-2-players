#pragma once
//���� � ����� ��������������� ��� ��� ���������� ��� �������� ������
//����� ��� ��� ����������� ��� ��������� ��� ���������� ��� �����, ����
//�� ����� ��������������� ��� ��� ����� �������.

#include <iostream>
#include <string>
#include "Chessboard.h"
using namespace std;

class UI {
public:
	static int displayMenu();	//��������� �� ������ ����� ��� �������� ��� ������� ��� ������
	static void newGame();		//�������� ��� ��������
	static void play(Chessboard*);	//����� ���������� ����������
};