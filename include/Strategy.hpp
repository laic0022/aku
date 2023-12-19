#pragma once

#include "TradeManager.hpp"

class Strategy {
public:
  virtual Trade processTick(Tick t) = 0;
};
