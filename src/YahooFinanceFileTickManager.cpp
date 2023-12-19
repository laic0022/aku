#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using std::string;

#include "../include/CurrencyConversions.hpp"
#include "../include/YahooFinanceFileTickManager.hpp"

YahooFinanceFileTickManager::YahooFinanceFileTickManager(string file_path) {

  // if (DEBUG_FLAG) {
  //   std::cout
  //       << "Running with YahooFinanceFileTickManager as default TickManager"
  //       << std::endl;
  // }

  std::ifstream input_file(file_path);
  int first_line = 0;
  for (string line; std::getline(input_file, line);) {
    // ignore first line as it contains table headings
    if (first_line == 0) {
      first_line++;
      continue;
    }

    // Yahoo finance have null candles , ignore them.
    if (line.find("null") != string::npos) {

      // if (DEBUG_FLAG) {
      //   std::cout << "Null candle found, ignoring line - " << line << std::endl;
      // }

      continue;
    }

    // if (DEBUG_FLAG) {
    //   std::cout << "Trying to parse line - " << line << std::endl;
    // }

    this->tick_store.push_back(parseTickFromString(line));
  }
}

INT YahooFinanceFileTickManager::parseDateFromString(string line) {
  // int date;
  line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
  return std::stol(line);
}

Tick YahooFinanceFileTickManager::parseTickFromString(string line) {
  Tick parsed_tick;
  std::vector<string> tokens;
  std::stringstream string_stream(line);
  string token;
  int col = 0; // will keep a check on csv columns

  while (std::getline(string_stream, token, ',')) {

    if (col == 0) {
      // column 0 is date
      parsed_tick.time = parseDateFromString(token);
    } else if (col == 1) {
      // col 1 is opening price
      CurrencyConversions::removeCommasFromCurrency(token);
      parsed_tick.open = std::stold(token);
    } else if (col == 2) {
      // col 2 is day high
      CurrencyConversions::removeCommasFromCurrency(token);
      parsed_tick.high = std::stold(token);
    } else if (col == 3) {
      // col 3 is day Low
      CurrencyConversions::removeCommasFromCurrency(token);
      parsed_tick.low = std::stold(token);
    } else if (col == 4) {
      // col 4 is day Close
      CurrencyConversions::removeCommasFromCurrency(token);
      parsed_tick.close = std::stold(token);
    } else if (col == 5) {
      // col 5 is Adj Close
      CurrencyConversions::removeCommasFromCurrency(token);
      parsed_tick.adjust_close = std::stold(token);
    } else {
      // col 6 is volume
      CurrencyConversions::removeCommasFromCurrency(token);
      parsed_tick.volume = std::stol(token);
    }

    col++;
  }

  return parsed_tick;
}

Tick YahooFinanceFileTickManager::getNextTick() {
  int idx = this->tick_counter;
  this->tick_counter++;
  return this->tick_store[idx];
}

Tick YahooFinanceFileTickManager::getNextTick(Tick last_tick) {
  int idx = this->tick_counter;
  this->tick_counter++;
  return this->tick_store[idx];
}

bool YahooFinanceFileTickManager::hasNextTick() {
  if (this->tick_counter < static_cast<int>(this->tick_store.size()))
    return true;

  return false;
}