#pragma once

#include "common.h"

struct Tick {
  REAL open;
  REAL low;
  REAL close;
  REAL high;
  REAL adjust_close;
  INT volume;
  INT time;

  void dump();
};
