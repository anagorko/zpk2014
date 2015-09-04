#ifndef TETROMINO_H
#define TETROMINO_H

#include <array>
#include <functional>

#include "BlockValue.h"

class TetrisModel;

class Tetromino
{
  typedef std::array<std::pair<int,int>, 4> BlocksArray;

  public:
    Tetromino();

    BlockValue getColor() const;
    bool isAlive() const;
    void moveDown(TetrisModel* model);
    BlocksArray getBlocksArray();
  private:
    bool alive_;
    BlocksArray blocks_;
    BlockValue color_;
};

#endif // TETROMINO_H
