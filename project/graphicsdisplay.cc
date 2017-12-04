#include <iostream>
#include "graphicsdisplay.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay():
 gridSize{100}, winSize{100}, xw{100, 100} {

  xw.fillRectangle(0, 0, winSize, winSize, Xwindow::White);
}


// void GraphicsDisplay::graphicsOutput() {
//   // GameBoardData gbData = notifier.getData();
  
  
// }

void GraphicsDisplay::notify(Subject<ScoreBoardData> &notifier) {
  ScoreBoardData sbData = notifier.getData();
  hiScore = sbData.hiScore;
  currentScore = sbData.currentScore;
  currentLevel = sbData.level;
}


void GraphicsDisplay::notify(Subject<CellData> &notifier) {
  CellData cd = notifier.getData();
  grid.at(cd.position.y).at(cd.position.x) = cd.blockType;
  int i = cd.position.y;
  int j = cd.position.x;
  int cellSize = winSize / gridSize;

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
  } else xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Blue);
}


  /*currentScore = gbData.currentScore;
  hiScore = gbData.hiScore;
  currentLevel = gbData.currentLevel;*/

