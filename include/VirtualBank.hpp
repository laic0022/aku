#pragma once

#include "common.h"

class VirtualBank {
public:
  REAL totalBalance;
  bool bankCredit(REAL);
  bool bankDebit(REAL);
  bool bankCanDebit(REAL);
  VirtualBank(REAL);
  REAL getBankBalance();
};
