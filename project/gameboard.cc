#include <memory>
#include "gameboard.h"
#include "scoreboard.h"
#include "textdisplay.h"

#include <iostream>

using namespace std;


void GameBoard::notify(Subject<vector<string>> &notifier) {
	vector<string> arr = notifier.getData();
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		cout << *it << endl;
	}
}


GameBoard::GameBoard(TextDisplay *td)
:rowList{}, lastTurnScore{0} {
	for (int i = 0; i < 18; i++) {
		rowList.emplace_back(); // Makes a new Row object
		for (int j = 0; j < 11; j++) {
			Cell c{i, j};
			rowList.back().emplaceCell(c);
			rowList.back().getCellAt(j).attach(td);
		}
	}
}



void GameBoard::updateScore(ScoreBoard &sb) {
	sb.updateScore(lastTurnScore);
}


