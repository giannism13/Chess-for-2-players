#include "Chessboard.h"
#include "UI.h"

int main() {
	system("chcp 1253");
	//Chessboard b;
	//b.showBoard();
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
	return 0;
}