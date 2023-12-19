#include "cxxopts.hpp"

int argc_new = 6;
  char *argv_new[] = {(char *)"bin/aku",
                      (char *)"-i",
                      (char *)"sample_inputs/MARUTI.NS.csv",
                      (char *)"-o",
                      (char *)"abc.csv",
                      (char *)"-d",
                      nullptr};
  argv = argv_new;

  auto result = options.parse(argc_new, argv);

  // print help if help specified
  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    exit(0);
  }

  // set debug mode if specified
  // bool debug = result["debug"].as<bool>();

  // check if input file is specified or not.
  // exit if not specified
  if (result.count("input")) {
    input_file = result["input"].as<std::string>();
  } else {
    std::cout << staticmsgs::noinputfile << std::endl;
    std::cout << options.help() << std::endl;
    exit(0);
  }

  // set path to output file
  output_file = result["output"].as<std::string>();

  if (DEBUG_FLAG) {
    std::cout << staticmsgs::printargs << std::endl;
    std::cout << "Path to input file " << input_file << std::endl;
    std::cout << "Path to output file " << output_file << std::endl;
  }
