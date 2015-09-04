#include "Tetromino.h"

#include <algorithm>

#include "TetrisModel.h"

Tetromino::Tetromino() :
  alive_(true),
  blocks_(),
  color_(BlockValue::FULL) {
    blocks_[0] = std::make_pair(0, 0);
    blocks_[1] = std::make_pair(1, 0);
    blocks_[2] = std::make_pair(0, 1);
    blocks_[3] = std::make_pair(1, 1);
}

BlockValue Tetromino::getColor() const {
  return color_;
}

bool Tetromino::isAlive() const {
  return alive_;
}

void Tetromino::moveDown(TetrisModel* model) {
  bool canMove = true;
  for (const auto& block : blocks_) {
    if(!model->isBlockEmpty(block.first, block.second+1)) {
      canMove = false;
      break;
    }
  }
  if(!canMove) {
    alive_ = false;
    return;
  }
  for (auto& block : blocks_) {
    block.second += 1;
  }
}

Tetromino::BlocksArray Tetromino::getBlocksArray() {
  return blocks_;
}
