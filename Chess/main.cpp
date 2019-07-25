#include "Chessboard.h"
#include "UI.h"

int main() {
	system("chcp 1253");
	while (true) {
		switch (UI::displayMenu()) {
		case 1:
			UI::newGame();
			break;
		case 2:
			UI::loadGame();
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