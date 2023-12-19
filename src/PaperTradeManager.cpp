#include "../include/PaperTradeManager.hpp"
#include "../include/Trade.hpp"
#include <iostream>

/*PaperTradeManager::PaperTradeManager(VirtualBank * bank){
        this->virutal_bank
}*/

PaperTradeManager::PaperTradeManager(VirtualBank *v_bank) {
  this->virtual_bank = v_bank;
  this->holdQuantity = 0;
}

int PaperTradeManager::performBuy(Trade trade) {
  std::cout << "Paper trade buy" << std::endl;
  this->virtual_bank->bankDebit(trade.quantity * trade.tick.close);
  this->holdQuantity += trade.quantity;
  return 1;
}

int PaperTradeManager::performSell(Trade trade) {
  std::cout << "Paper trade sell" << std::endl;
  this->virtual_bank->bankCredit(trade.quantity * trade.tick.close);
  this->holdQuantity -= trade.quantity;
  return 1;
}

bool PaperTradeManager::canBuy(Trade trade) {
  if (this->virtual_bank->bankCanDebit(trade.quantity * trade.tick.close)) {
    return true;
  }

  // if (DEBUG_FLAG) {
  //   std::cout << "Could not perform a BUY signal, probably insufficient funds!"
  //             << std::endl;
  // }

  return false;
}

bool PaperTradeManager::canSell(Trade trade) {
  if (trade.quantity <= this->holdQuantity) {
    return true;
  }

  // if (DEBUG_FLAG) {
  //   std::cout
  //       << "Could not perform a SELL signal, you cant sell what you dont have"
  //       << std::endl;
  // }

  return false;
}

bool PaperTradeManager::squareOff(Tick last_tick) {
  using Move = Trade::Move;
  if (this->holdQuantity > 0) {
    Trade squareoff_trade(Move::SELL, this->holdQuantity, last_tick);
    this->performTrade(squareoff_trade);
  }
  return false;
}