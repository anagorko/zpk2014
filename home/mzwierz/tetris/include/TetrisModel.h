#ifndef TETRISMODEL_H
#define TETRISMODEL_H

#include <array>
#include <memory>
#include <vector>

#include "BlockValue.h"
#include "Tetromino.h"

class TetrisModel {

public:
  static const int tetrion_height_ = 20;
  static const int tetrion_width_ = 10;
  typedef std::array<BlockValue, tetrion_width_ * tetrion_height_> Tetrion;

  enum GameStatus {
    READY,
    RUNNING,
    GAME_OVER,
    PAUSED
  };

  TetrisModel();

  void gameTick();
  Tetrion getTetrionSnapshot();
  bool isBlockEmpty(int x, int y);
  void resetGame();
  void runGame();

private:

  bool collisionCheck(Tetromino* tetromino);
  void drawTetromino(Tetromino* tetromino);
  BlockValue getBlockValue(int x, int y) const;
  Tetromino* getNewTetromino();
  void setBlockValue(int x, int y, BlockValue value);
  void sweepLines();

  std::unique_ptr<Tetromino> alive_tetromino_;
  int score_;
  GameStatus status_;
  Tetrion tetrion_;
  std::vector<std::unique_ptr<Tetromino>> tetrominos_;
};

#endif // TETRISMODEL_H
