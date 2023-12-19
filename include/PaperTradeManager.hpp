#pragma once

#include "TradeManager.hpp"
#include "VirtualBank.hpp"

class PaperTradeManager : public TradeManager {
public:
  int holdQuantity;
  VirtualBank *virtual_bank;
  PaperTradeManager(VirtualBank *virtual_bank);
  int performBuy(Trade trade);
  int performSell(Trade trade);
  bool canBuy(Trade trade);
  bool canSell(Trade trade);
  bool squareOff(Tick last_tick);
};
