#pragma once

#include <vector>

#include "Tick.hpp"
#include "Trade.hpp"

class TradeManager {
public:
  int quantity;
  std::vector<Trade> trades;
  int performTrade(Trade trade);

  virtual int performBuy(Trade trade) = 0;
  virtual int performSell(Trade trade) = 0;
  virtual bool canBuy(Trade trade) = 0;
  virtual bool canSell(Trade trade) = 0;
  virtual bool squareOff(Tick last_tick) = 0;

  int performBuyInternal(Trade trade);
  int performSellInternal(Trade trade);
  void dumpTrades();
};
