#include "displayMenu.h"

int displayMenu() {
	system("cls");

	int sel;

	cout << "=====�KAKI=====" << endl;
	cout << "1. ��� ��������" << endl;
	cout << "2. ������� ���������� ��� ������" << endl;
	cout << "3. ������" << endl << endl;
	cout << "����� ��� ������� ���: ";
	cin >> sel;
	return sel;
}