#include <iostream>
#include "graphicsdisplay.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay():
 gridSize{20}, winSize{500}, xw{600, 600} {
  xw.fillRectangle(50, 50, winSize-47, winSize-47, Xwindow::White);
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
  int cellSize = winSize/gridSize;

  if(i<=2) {
     return;
  }
  xw.drawString(50, 10, string("Level:   " + to_string(currentLevel)));
  xw.drawString(50, 25, string("Score:   " + to_string(currentScore)));
  xw.drawString(50, 40, string("Hi Score:   " + to_string(hiScore)));
  if(cd.blockType == 'I') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Orange);
  } else if(cd.blockType == 'J') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Magenta);
  } else if(cd.blockType == 'L') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Red);
  } else if(cd.blockType == 'O') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Green);
  } else if(cd.blockType == 'S') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Cyan);
  } else if(cd.blockType == 'T') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Yellow);
  } else if(cd.blockType == '*') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Brown);
  } else if(cd.blockType == '?') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Black);
  } else if (cd.blockType == 'Z') {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::Blue);
  } else {
    xw.fillRectangle(j * cellSize + 47, i * cellSize - 25, 30, 30, Xwindow::White);
  }

  xw.drawString(50, 565, string("Next Block:"));
  if (nextBlockLetter == 'I') {
    xw.drawString(50, 580, string("IIII"));
  } else if (nextBlockLetter == 'J') {
    xw.drawString(50, 600, string("J"));
    xw.drawString(50, 110, string("JJJ"));
  } else if (nextBlockLetter == 'L') {
    xw.drawString(50, 600, string("LLL"));
    xw.drawString(50, 110, string("L"));
  } else if (nextBlockLetter == 'O') {
    xw.drawString(50, 600, string("OO"));
    xw.drawString(50, 110, string("OO"));
  } else if (nextBlockLetter == 'S') {
    xw.drawString(50, 600, string(" SS"));
    xw.drawString(50, 110, string("SS"));
  } else if (nextBlockLetter == 'T') {
    xw.drawString(50, 600, string("TTT"));
    xw.drawString(50, 110, string(" T"));
  } else if (nextBlockLetter == 'Z') {
    xw.drawString(50, 600, string("ZZ"));
    xw.drawString(50, 110, string(" ZZ"));
  }
}



