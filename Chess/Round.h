#ifndef Round_h
#define Round_h

//� ����� ���� �������� ��� �������� ��� ��� ������� ��� ����
#include <string>
using namespace std;

class Round {
private:
	string white;
	string black;
public:
	Round();
	void setWhite(string);
	void setBlack(string);
	string getWhite();
	string getBlack();
};
#endif
