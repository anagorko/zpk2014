#include <iostream>

#include "TetrisModel.h"

using std::cout;
using std::endl;

namespace {
int coord(int x, int y) {
  return y * TetrisModel::tetrion_width_ + x;
}
}

void printTetrion(TetrisModel::Tetrion tetrion) {
  for(int y = 0; y < TetrisModel::tetrion_height_; ++y) {
    for(int x = 0; x < TetrisModel::tetrion_width_; ++x) {
      std::cout << (tetrion[coord(x,y)] == BlockValue::EMPTY ? 0 : 1);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main()
{
  TetrisModel tetris_model;
  tetris_model.runGame();
  printTetrion(tetris_model.getTetrionSnapshot());
  tetris_model.gameTick();
  printTetrion(tetris_model.getTetrionSnapshot());
  tetris_model.gameTick();
  printTetrion(tetris_model.getTetrionSnapshot());
  tetris_model.gameTick();
  printTetrion(tetris_model.getTetrionSnapshot());
  return 0;
}
