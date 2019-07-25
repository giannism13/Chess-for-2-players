#pragma once
//���� � ����� ��������������� ��� ��� ���������� ��� �������� ������
//����� ��� ��� ����������� ��� ��������� ��� ���������� ��� �����, ����
//�� ����� ��������������� ��� ��� ����� �������.

#include <iostream>
#include <string>
#include "Chessboard.h"
#include <vector>
using namespace std;

class UI {
public:
	static int displayMenu();				//��������� �� ������ ����� ��� �������� ��� ������� ��� ������
	static void newGame();					//�������� ��� ��������
	static void play(Chessboard*);			//����� ���������� ����������
	static vector<int> translate(string);	//���������� ��� ������ ��� ����� � �������
	static string saveUI();					//�������� �� ����� ��� ������� ��� ����� �� ����������� � �������
	static void loadGame();			//�������� ��� ������������ ��������
	static void replay();					//������������� ��� �������� ��� ��� ����
};