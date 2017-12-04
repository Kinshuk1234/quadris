#include "scoreboard.h"
#include "gameboard.h"

#include <iostream>

using namespace std;

// Big 5 + ctor ---------------------------------

ScoreBoard::ScoreBoard()
: currentLevel{0}, currentScore{0}, hiScore{0}, nextBlockLetter{'-'}, gameOver{false} {/* CTOR BODY */}

void ScoreBoard::updateCurrentScore(int lasTurnScore) {
	currentScore += lasTurnScore;
	if (currentScore > hiScore) {
		hiScore = currentScore;
	}
	notifyAll();
}

void ScoreBoard::setCurrentScore(int newScore) {
	currentScore = newScore;
	notifyAll();
}

void ScoreBoard::updateLevel(int newLevel) {
	currentLevel = newLevel;
	notifyAll();
}


int ScoreBoard::getCurrentScore() {
	return currentScore;
}

int ScoreBoard::getHiScore() {
	return hiScore;
}

ScoreBoardData ScoreBoard::getData() {
	ScoreBoardData sbData;
	sbData.level = currentLevel;
	sbData.currentScore = currentScore;
	sbData.hiScore = hiScore;
	sbData.nextBlockLetter = nextBlockLetter;
	sbData.gameOver = gameOver;
	return sbData;
}


void ScoreBoard::updateNextBlock(char newLetter) {
	nextBlockLetter = newLetter;
	notifyAll();
}

void ScoreBoard::setGameOver(bool gameOver) {
	this->gameOver = gameOver;
	if (gameOver) {
		notifyAll();
	}
}

bool ScoreBoard::getGameOver() const {
	return gameOver;
}
