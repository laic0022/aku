#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "../include/CurrencyConversions.hpp"

void CurrencyConversions::removeCommasFromCurrency(std::string &str) {
  str.erase(std::remove(str.begin(), str.end(), ','), str.end());
}

REAL CurrencyConversions::readWithPrecision(std::string const &str,
                                         std::size_t const p) {
  std::stringstream sstream;
  sstream << std::setprecision(p) << std::fixed << str << std::endl;

  REAL d;
  sstream >> d;

  return d;
}
