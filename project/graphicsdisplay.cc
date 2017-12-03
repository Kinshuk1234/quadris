#include <iostream>
#include "graphicsdisplay.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay():
 gridSize{100}, winSize{100}, xw{100, 100} {
  xw.fillRectangle(0, 0, winSize, winSize, Xwindow::White);
}


void GraphicsDisplay::notify(Subject<GameBoardData> &notifier) {
  GameBoardData gbData = notifier.getData();
  int cellSize = winSize / gridSize;
  for (int i = 0; i < 18; i++) {
    for (int j = 0; j < 11; j++) {
      if(gbData.cells.at(i).at(j).getLetter() == 'I') {
        xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Orange);
      } else if(gbData.cells.at(i).at(j).getLetter() == 'J') {
        xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Magenta);
      } else if(gbData.cells.at(i).at(j).getLetter() == 'L') {
        xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Red);
      } else if(gbData.cells.at(i).at(j).getLetter() == 'O') {
        xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Green);
      } else if(gbData.cells.at(i).at(j).getLetter() == 'S') {
        xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Cyan);
      } else if(gbData.cells.at(i).at(j).getLetter() == 'T') {
        xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Yellow);
      } else xw.fillRectangle(j * cellSize, i * cellSize, cellSize, cellSize, Xwindow::Blue);
    }
  }
}
  /*currentScore = gbData.currentScore;
  hiScore = gbData.hiScore;
  currentLevel = gbData.currentLevel;*/
