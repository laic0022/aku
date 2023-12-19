#pragma once

#include "Tick.hpp"
#include "TickManager.hpp"
#include <iostream>
#include <vector>

class YahooFinanceFileTickManager : public TickManager {
public:
  YahooFinanceFileTickManager(std::string file_path);
  Tick getNextTick(Tick last_tick);
  Tick getNextTick();
  int tick_counter;
  std::vector<Tick> tick_store;
  Tick parseTickFromString(std::string line);
  INT parseDateFromString(std::string date);
  bool hasNextTick();
};