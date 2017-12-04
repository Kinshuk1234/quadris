#include "textdisplay.h"
#include <vector>
#include <iostream>
#include "subject.h"

using namespace std;


// other methods ------------------

void TextDisplay::notify(Subject<CellData> &notifier) {
	CellData cd = notifier.getData();
	// for (int i = 0; i < 18; i++) {
	// 	for (int j = 0; j < 11; j++) {
	// 		//gbData.cells.at(i).at(j).getLetter();
	// 		grid.at(i).at(j) = gbData.cells.at(i).at(j).getLetter();
	// 	}
	// }
	// currentScore = gbData.currentScore;
	// hiScore = gbData.hiScore;
	// currentLevel = gbData.currentLevel;
	grid.at(cd.position.y).at(cd.position.x) = cd.blockType;
}

void TextDisplay::notify(Subject<ScoreBoardData> &notifier) {
	ScoreBoardData sbData = notifier.getData();
	currentLevel = sbData.level;
	currentScore = sbData.currentScore;
	hiScore = sbData.hiScore;
}


int TextDisplay::getCurrentLevel() const {
	return currentLevel;
}

int TextDisplay::getCurrentScore() const {
	return currentScore;
}

int TextDisplay::getHiScore() const {
	return hiScore;
}

// Big 5 + ctor ------------------

TextDisplay::TextDisplay()
: grid{vector<vector<char>>(18, vector<char>(11, '-'))} {/* CTOR BODY */}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	auto &grid = td.grid;
	out << "Current Level: " << td.getCurrentLevel() << endl;
	out << "Current Score: " << td.getCurrentScore() << endl;
	out << "Hi Score: " << td.getHiScore() << endl;
	for (auto it = grid.begin() + 3; it != grid.end(); ++it) {
		for (auto innerIt = it->begin(); innerIt != it->end(); ++innerIt) {
			out << *innerIt;
		}
		out << endl;
	}

	return out;
}


