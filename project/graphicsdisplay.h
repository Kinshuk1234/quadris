#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "gameboard.h"
#include "gameboarddata.h"
#include "window.h"
class Cell;

class GraphicsDisplay: public Observer<GameBoardData> {
  const int gridSize, winSize;
  Xwindow xw;
  std::vector<std::vector<char>> grid;
  int hiScore;
  int currentScore;
  int currentLevel;
 public:
  GraphicsDisplay(int gridSize, int winSize);

  void notify(Subject<GameBoardData> &notifier) override;
};
#endif
