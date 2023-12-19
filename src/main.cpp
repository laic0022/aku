#include <fstream>
#include <iostream>
#include <random>

#include "../include/staticmsgs.hpp"

#include "../include/Tick.hpp"
#include "../include/TickManager.hpp"

#include "../include/RandomTickManager.hpp"
#include "../include/YahooFinanceFileTickManager.hpp"

#include "../include/RandomBuySellStrategy.hpp"
#include "../include/SmaStrategy.hpp"
#include "../include/Strategy.hpp"

#include "../include/PaperTradeManager.hpp"
#include "../include/TradeManager.hpp"

#include "../include/VirtualBank.hpp"

int main(int argc, char **argv) {
  /* Everything related to command-line options */
  std::string input_file{"../sample_inputs/MARUTI.NS.csv"},
      output_file{"output.csv"}; // path to input file
                                 // path to output file
  /* End everything related to command-line options */

  /* Initialise tick manager*/
  TickManager *tick_manager;
  // tick_manager = new RandomTickManager();
  tick_manager = new YahooFinanceFileTickManager(input_file);

  /* Initialise strategy */
  Strategy *strategy;
  // strategy = new RandomBuySellStrategy();
  strategy = new SmaStrategy();

  /*Initialise a virtual bank*/
  VirtualBank *virtual_bank;
  REAL bank_balance = 100000;
  virtual_bank = new VirtualBank(bank_balance);

  /* Initialise trade manager */
  TradeManager *trade_manager;
  trade_manager = new PaperTradeManager(virtual_bank);

  Tick last_traded_tick;
  /* Start the core event-loop */
  while (tick_manager->hasNextTick()) {
    Tick t = tick_manager->getNextTick();
    last_traded_tick = t;
    // t.dump();

    Trade tr = strategy->processTick(t);
    trade_manager->performTrade(tr);
  }

  trade_manager->squareOff(last_traded_tick);
  trade_manager->dumpTrades();

  std::string final_bank_balance =
      std::to_string(virtual_bank->getBankBalance());
  std::string profit_or_loss =
      std::to_string(virtual_bank->getBankBalance() - bank_balance);

  std::cout << "Total Bank Balance: " << final_bank_balance << std::endl;
  std::cout << "Profit or loss: " << profit_or_loss << std::endl;

  return 0;
}
