#pragma once

#include "TickManager.hpp"
#include <cstdlib>
#include <iostream>
#include <random>

/* Example Tick Manager */

/* Following Manager is only for testing purpose
Do not use this manager in prod */

class RandomTickManager : public TickManager {
  std::seed_seq seed;
  std::mt19937 generator;
  std::uniform_int_distribution<int> distribution_int;
  std::uniform_real_distribution<double> distribution_double;

public:
  RandomTickManager() : seed{43}, generator(seed) {
    std::cout << distribution_int(generator) << std::endl;
    std::cout << distribution_int(generator) << std::endl;
    std::cout << distribution_int(generator) << std::endl;
    std::cout << distribution_int(generator) << std::endl;
  }
  Tick getNextTick(Tick last_tick);
  Tick getNextTick();

private:
  int genRandomInt();
  float genRandomFloat();
};