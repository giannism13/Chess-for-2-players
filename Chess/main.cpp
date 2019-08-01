#include "UI.h"
#include <unistd.h>
using namespace std;

int main() {
	system("chcp 1253");
	
	do {
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
			cout << "Λάθος επιλογή! Παρακαλώ ξαναπροσπαθήστε!" << endl;
			sleep(2);
			cin.clear();
			fflush(stdin);			
			break;
		}
	}while (true);
	return 0;
}
