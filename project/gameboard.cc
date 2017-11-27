#include <memory>
#include "gameboard.h"
#include "scoreboard.h"
#include "textdisplay.h"


using namespace std;

GameBoard::GameBoard(shared_ptr<TextDisplay> &td)
:rowList{}, lastTurnScore{0} {
	for (int i = 0; i < 18; i++) {
		rowList.emplace_back(); // Makes a new Row object
		for (int j = 0; j < 11; j++) {
			Cell c{i, j};
			// c.attach(td); // TODO
			rowList.back().add_cell(c);
		}
	}
}



void GameBoard::updateScore(ScoreBoard &sb) {
	sb.updateScore(lastTurnScore);
}


