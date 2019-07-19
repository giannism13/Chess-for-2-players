#include "displayMenu.h"

int displayMenu() {
	system("cls");

	int sel;

	cout << "=====ΣKAKI=====" << endl;
	cout << "1. Νεο παιχνιδι" << endl;
	cout << "2. Φορτωση παιχνιδιου απο αρχειο" << endl;
	cout << "3. Εξοδος" << endl << endl;
	cout << "Δωστε την επιλογη σας: ";
	cin >> sel;
	return sel;
}