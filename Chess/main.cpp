#include "Chessboard.h"
#include "UI.h"

void main() {
	system("chcp 1253");
	while (true) {
		switch (UI::displayMenu()) {
		case 1:
			//Chessboard board;
			//TODO stuff
			break;
		case 2:
			//TODO File input
			break;
		case 3:
			exit(0);
		default:
			cout << "Λαθος επιλογη! Παρακαλω ξαναπροσπαθειστε!" << endl;
			break;
		}
	}
}