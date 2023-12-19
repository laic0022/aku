#include "../include/RandomBuySellStrategy.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "../include/Trade.hpp"

using Move = Trade::Move;

Trade RandomBuySellStrategy::processTick(Tick tick) {

  // static std::random_device rd;
  // static std::mt19937 mt(rd());

  static std::seed_seq seed{43};
  static std::mt19937 mt(seed);
  int randomMove;

  int quantity = 10;
  Trade::Move mv;

  // srand((unsigned int)time(NULL));
  // randomMove = min + (rand() % static_cast<int>(max - min + 1));

  std::uniform_int_distribution<int> dist(1, 3);
  randomMove = dist(mt);

  if (randomMove == 1) {
    mv = Move::BUY;
    // if (DEBUG_FLAG) {
    //   std::cout << "RandomBuySellStrategy: BUY SIGNAL generated" << std::endl;
    // }
  }

  if (randomMove == 2) {
    mv = Move::SELL;
    // if (DEBUG_FLAG) {
    //   std::cout << "RandomBuySellStrategy: SELL SIGNAL generated" << std::endl;
    // }
  }

  if (randomMove == 3) {
    mv = Move::PASS;
    // if (DEBUG_FLAG) {
    //   std::cout << "RandomBuySellStrategy: PASS SIGNAL generated" << std::endl;
    // }
  }

  // mv = Move::BUY;

  return Trade(mv, quantity, tick);
}