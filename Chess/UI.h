//���� � ����� ��������������� ��� ��� ���������� ��� �������� ������
//����� ��� ��� ����������� ��� ��������� ��� ���������� ��� �����, ����
//�� ����� ��������������� ��� ��� ����� �������.
#ifndef UI_h
#define UI_h
#include <iostream>
#include <string>
#include <vector>
#include "Round.h"
#include "Chessboard.h"
using namespace std;

class UI {
public:
	static int displayMenu();				//��������� �� ������ ����� ��� �������� ��� ������� ��� ������
	static void newGame();					//�������� ��� ��������
	static void play(Chessboard*);			//����� ���������� ����������
	static vector<int> translate(string);	//���������� ��� ������ ��� ����� � �������
	static string saveUI();					//�������� �� ����� ��� ������� ��� ����� �� ����������� � �������
	static void loadGame();					//�������� ��� ������������ ��������
	static void replay(vector<Round>);					//������������� ��� �������� ��� ��� ����
};
#endif
