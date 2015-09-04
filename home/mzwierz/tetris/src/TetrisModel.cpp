#include "tetrisModel.h"

#include "tetromino.h"

namespace {
  int coord(int x, int y) {
    return y * TetrisModel::tetrion_width_ + x;
  }
}

TetrisModel::TetrisModel() :
  alive_tetromino_(nullptr),
  score_(0),
  status_(TetrisModel::READY),
  tetrion_(),
  tetrominos_()
{
  resetGame();
}

void TetrisModel::resetGame() {
  alive_tetromino_.reset(nullptr);
  score_ = 0;
  status_ = TetrisModel::READY;
  tetrion_.fill(BlockValue::EMPTY);
  tetrominos_.clear();
}

void TetrisModel::runGame() {
  if(status_ == TetrisModel::READY) {
    alive_tetromino_.reset(getNewTetromino());
    status_ = TetrisModel::RUNNING;
  }
}

void TetrisModel::gameTick() {
  if(status_ != TetrisModel::RUNNING)
    return;

  if(alive_tetromino_->isAlive()) {
    alive_tetromino_->moveDown(this);
  } else {
    drawTetromino(alive_tetromino_.get());
    sweepLines();
    alive_tetromino_.reset(getNewTetromino());
    if(collisionCheck(alive_tetromino_.get())) {
      status_ = TetrisModel::GAME_OVER;
    }
  }
}

TetrisModel::Tetrion TetrisModel::getTetrionSnapshot() {
  Tetrion temp(tetrion_);
  if(alive_tetromino_) {
    // TODO Same code as in drawTetromino
    auto blocks_array = alive_tetromino_->getBlocksArray();
    for(auto block : blocks_array) {
      temp[coord(block.first, block.second)] = alive_tetromino_->getColor();
    }
  }
  return temp;
}

void TetrisModel::setBlockValue(int x, int y, BlockValue value) {
  tetrion_[y * TetrisModel::tetrion_width_ + x] = value;
}

BlockValue TetrisModel::getBlockValue(int x, int y) const {
  return tetrion_[y * TetrisModel::tetrion_width_ + x];
}

void TetrisModel::drawTetromino(Tetromino* tetromino) {
  auto blocks_array = tetromino->getBlocksArray();
  for(auto block : blocks_array) {
    setBlockValue(block.first, block.second, tetromino->getColor());
  }
}

Tetromino* TetrisModel::getNewTetromino() {
  if(tetrominos_.empty()) {
    tetrominos_.push_back(std::unique_ptr<Tetromino>(new Tetromino()));
    tetrominos_.push_back(std::unique_ptr<Tetromino>(new Tetromino()));
    tetrominos_.push_back(std::unique_ptr<Tetromino>(new Tetromino()));
  }
  Tetromino* result = tetrominos_.back().release();
  tetrominos_.pop_back();
  return result;
}

bool TetrisModel::collisionCheck(Tetromino* tetromino) {
  return false;
}

void TetrisModel::sweepLines() {
}

bool TetrisModel::isBlockEmpty(int x, int y) {
  return (getBlockValue(x,y) == BlockValue::EMPTY);
}
