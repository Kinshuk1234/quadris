#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "gameboard.h"
#include "scoreboarddata.h"
#include "celldata.h"
#include "window.h"
class Cell;

class GraphicsDisplay: public Observer<ScoreBoardData>, public Observer<CellData> {
  const int gridSize, winSize;
  Xwindow xw;
  int hiScore;
  int currentScore;
  int currentLevel;
  bool gameOver;
  char nextBlockLetter;
 public:
  GraphicsDisplay();



  void notify(Subject<ScoreBoardData> &notifier) override;
  void notify(Subject<CellData> &notifier) override;
};

#endif


