#pragma once

#include "Tick.hpp"
#include "Trade.hpp"
#include <iostream>

class Trade {
public:
  enum class Move { BUY, SELL, PASS };
  Trade::Move mv;
  int quantity;
  Tick tick;

  Trade(Trade::Move mv, int quantity, Tick tick) {
    this->mv = mv;
    this->quantity = quantity;
    this->tick = tick;
  }

  void dump() {
    std::cout << "Dumping a trade sequence" << std::endl;
    const std::string trade_move = [this]() {
      if (this->mv == Move::BUY)
        return "BUY";
      else if (this->mv == Move::SELL)
        return "SELL";
      else
        return "PASS";
    }();

    std::cout << "TradeMove - " << trade_move << std::endl;
    std::cout << "Trade quantity - " << this->quantity << std::endl;
    std::cout << "Tick Info -- " << std::endl;
    this->tick.dump();
    std::cout << std::endl;
  }
};
