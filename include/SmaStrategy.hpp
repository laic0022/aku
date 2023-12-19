#pragma once

#include "Strategy.hpp"

class SmaStrategy : public Strategy {
public:
  // vector<Tick> tickBuffer;
  bool isPosition = false;
  int tickCount;
  REAL totalClosingPrice;
  REAL lastBoughtPrice;
  Trade processTick(Tick t);
};