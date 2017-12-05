#include <iostream>
#include "graphicsdisplay.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay():
 gridSize{20}, winSize{500}, xw{500, 500} {
  xw.fillRectangle(0, 0, winSize, winSize, Xwindow::White);
}

void GraphicsDisplay::notify(Subject<ScoreBoardData> &notifier) {
  ScoreBoardData sbData = notifier.getData();
  currentLevel = sbData.level;
  currentScore = sbData.currentScore;
  hiScore = sbData.hiScore;
  nextBlockLetter = sbData.nextBlockLetter;
  gameOver = sbData.gameOver;
}


void GraphicsDisplay::notify(Subject<CellData> &notifier) {
  CellData cd = notifier.getData();
  int i = cd.position.y;
  int j = cd.position.x;
  int cellSize = winSize / gridSize;


  xw.drawString(0, 0, string("Level:   " + to_string(currentLevel)));
  xw.drawString(0, 10, string("Score:   " + to_string(currentScore)));
  xw.drawString(0, 20, string("Hi Score:   " + to_string(hiScore)));
  if(cd.blockType == 'I') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Orange);
  } else if(cd.blockType == 'J') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Magenta);
  } else if(cd.blockType == 'L') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Red);
  } else if(cd.blockType == 'O') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Green);
  } else if(cd.blockType == 'S') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Cyan);
  } else if(cd.blockType == 'T') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Yellow);
  } else if(cd.blockType == '*') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Brown);
  } else if(cd.blockType == '?') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Black);
  } else if (cd.blockType == 'Z') {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Blue);
  } else {
    xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::White);
  }
  xw.drawString(0, 100, string("Next Block:"));
  if (nextBlockLetter == 'I') {
    xw.drawString(0, 101, string("IIII"));
  } else if (nextBlockLetter == 'J') {
    xw.drawString(0, 105, string("J"));
    xw.drawString(0, 110, string("JJJ"));
  } else if (nextBlockLetter == 'L') {
    xw.drawString(0, 105, string("LLL"));
    xw.drawString(0, 110, string("L"));
  } else if (nextBlockLetter == 'O') {
    xw.drawString(0, 105, string("OO"));
    xw.drawString(0, 110, string("OO"));
  } else if (nextBlockLetter == 'S') {
    xw.drawString(0, 105, string(" SS"));
    xw.drawString(0, 110, string("SS"));
  } else if (nextBlockLetter == 'T') {
    xw.drawString(0, 105, string("TTT"));
    xw.drawString(0, 110, string(" T"));
  } else if (nextBlockLetter == 'Z') {
    xw.drawString(0, 105, string("ZZ"));
    xw.drawString(0, 110, string(" ZZ"));
  }
}

  