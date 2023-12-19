#include "../include/SmaStrategy.hpp"
#include "../include/Trade.hpp"
#include <iostream>

using Move = Trade::Move;

Trade SmaStrategy::processTick(Tick tick) {
  int quantity = 10;
  int smaDayRange = 5;
  // int differenceTolerance = 100;
  Trade::Move mv;

  this->tickCount += 1;
  this->totalClosingPrice += tick.close;

  // following block will ensure that if we are making good profit exit
  // position.
  if (this->lastBoughtPrice != 0 && (tick.close - this->lastBoughtPrice) > 10) {
    mv = Move::SELL;
    // if (DEBUG_FLAG) {
    //   std::cout << "SmaStrategy: Safe SELL SIGNAL generated" << std::endl;
    // }
    return Trade(mv, quantity, tick);
  }

  if (this->tickCount >= smaDayRange) {
    REAL ma = this->totalClosingPrice / smaDayRange;
    this->tickCount = 0;
    this->totalClosingPrice = 0;

    if (tick.close > ma) {
      this->isPosition = true;
      mv = Move::BUY;
      this->lastBoughtPrice = tick.close;
      // if (DEBUG_FLAG) {
      //   std::cout << "SmaStrategy: BUY SIGNAL generated" << std::endl;
      // }
    } else {
      mv = Move::PASS;
      // if (DEBUG_FLAG) {
      //   std::cout << "SmaStrategy: PASS SIGNAL generated" << std::endl;
      // }
    }

  } else {
    mv = Move::PASS;
    // if (DEBUG_FLAG) {
    //   std::cout << "SmaStrategy: PASS SIGNAL generated" << std::endl;
    // }
  }

  return Trade(mv, quantity, tick);
}