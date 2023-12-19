#include "../include/VirtualBank.hpp"
#include <iostream>

VirtualBank::VirtualBank(REAL startingBalance) {
  this->totalBalance = startingBalance;
}

bool VirtualBank::bankCredit(REAL amount) {
  this->totalBalance += amount;
  return true;
}

bool VirtualBank::bankCanDebit(REAL amount) {

  if (this->totalBalance >= amount) {
    return true;
  }

  return false;
}

bool VirtualBank::bankDebit(REAL amount) {

  if (this->totalBalance >= amount) {
    this->totalBalance -= amount;
    return true;
  }

  return false;
}

REAL VirtualBank::getBankBalance() { return this->totalBalance; }