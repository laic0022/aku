#pragma once

#include "Tick.hpp"
#include <iostream>

class TickManager {
public:
  virtual Tick getNextTick(Tick last_tick) = 0;
  virtual Tick getNextTick() = 0;
  virtual bool hasNextTick() = 0;
};
