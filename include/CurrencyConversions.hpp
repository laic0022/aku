#pragma once
#include "common.h"

class CurrencyConversions {
public:
  static void removeCommasFromCurrency(std::string &str);
  static REAL readWithPrecision(std::string const &str, std::size_t const p);
};
