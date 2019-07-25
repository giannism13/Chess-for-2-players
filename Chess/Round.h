#pragma once
//Η κλαση αυτη περιεχει τις κινησεις των δυο παικτων ανα γυρο
#include <string>
using namespace std;

class Round {
private:
	string white;
	string black;
public:
	void setWhite(string);
	void setBlack(string);
	string getWhite();
	string getBlack();
};