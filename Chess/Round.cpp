#include "Round.h"

Round::Round(){
	this->white = "0";
	this->black = "0";
}

void Round::setWhite(string white) {
	this->white = white;
}

void Round::setBlack(string black) {
	this->black = black;
}

string Round::getWhite() {
	return this->white;
}

string Round::getBlack() {
	return this->black;
}

