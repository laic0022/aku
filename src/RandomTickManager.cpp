#include "../include/RandomTickManager.hpp"
#include <cstdlib>
#include <iostream>
#include <random>

int RandomTickManager::genRandomInt() {
  // srand(time(NULL));
  return distribution_int(generator);
}

float RandomTickManager::genRandomFloat() {
  // float r = static_cast<float>(rand());
  return distribution_double(generator);
}

Tick RandomTickManager::getNextTick(Tick last_tick) {
  Tick random_tick;
  random_tick.open = genRandomFloat();
  random_tick.close = genRandomFloat();
  random_tick.high = genRandomFloat();
  random_tick.adjust_close = genRandomFloat();
  random_tick.volume = genRandomInt();
  random_tick.time = genRandomInt();
  return random_tick;
}

Tick RandomTickManager::getNextTick() {
  Tick random_tick;
  random_tick.open = genRandomFloat();
  random_tick.close = genRandomFloat();
  random_tick.high = genRandomFloat();
  random_tick.adjust_close = genRandomFloat();
  random_tick.volume = genRandomInt();
  random_tick.time = genRandomInt();
  return random_tick;
}
