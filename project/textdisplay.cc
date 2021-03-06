#include "textdisplay.h"
#include <vector>
#include <iostream>
#include "subject.h"

using namespace std;


// other methods ------------------

void TextDisplay::notify(Subject<CellData> &notifier) {
	CellData cd = notifier.getData();
	grid.at(cd.position.y).at(cd.position.x) = cd.blockType;
}

void TextDisplay::notify(Subject<ScoreBoardData> &notifier) {
	ScoreBoardData sbData = notifier.getData();
	currentLevel = sbData.level;
	currentScore = sbData.currentScore;
	hiScore = sbData.hiScore;
	nextBlockLetter = sbData.nextBlockLetter;
	gameOver = sbData.gameOver;
}


// Big 5 + ctor ------------------

TextDisplay::TextDisplay()
: grid{vector<vector<char>>(18, vector<char>(11, '-'))} {/* CTOR BODY */}

ostream &operator<<(ostream &out, const TextDisplay &td) {

	if (td.gameOver) {
		out << " ---- GAME OVER ---- " << endl;
		out << " Current Score: " << td.currentScore << endl;
		out << " High Score:    " << td.hiScore << endl;
		out << " ------------------- " << endl << endl << endl << endl;
		out << " ------------------- " << endl;
		out << " ---- NEW GAME ----- " << endl;
		out << " ------------------- " << endl << endl;

	}

	out << "Current Level: " << td.currentLevel << endl;
	out << "Current Score: " << td.currentScore << endl;
	out << "Hi Score:      " << td.hiScore << endl;
	auto &grid = td.grid;
	out << "---------------------" << endl;
	for (auto it = grid.begin() + 3; it != grid.end(); ++it) {
		for (auto innerIt = it->begin(); innerIt != it->end(); ++innerIt) {
			out << *innerIt << " ";
		}
		out << endl;
	}
	out << "---------------------" << endl;
	out << "Next Block: " << endl;
	char nextBlockLetter = td.nextBlockLetter;
	if (nextBlockLetter == 'I') {
		out << "IIII" << endl;
	} else if (nextBlockLetter == 'J') {
		out << "J" << endl << "JJJ" << endl;
	} else if (nextBlockLetter == 'L') {
		out << "LLL" << endl << "L" << endl;
	} else if (nextBlockLetter == 'O') {
		out << "OO" << endl << "OO" << endl;
	} else if (nextBlockLetter == 'S') {
		out << " SS" << endl << "SS" << endl;
	} else if (nextBlockLetter == 'T') {
		out << "TTT" << endl << " T" << endl;
	} else if (nextBlockLetter == 'Z') {
		out << "ZZ" << endl << " ZZ" << endl;
	}	
	
	

	return out;
}


