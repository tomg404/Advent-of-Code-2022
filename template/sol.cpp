// Copyright 2022 Tom Gaimann

// Often used libraries
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  std::ifstream file;
  std::string line;

  // Check for input file
  if (argc < 2) {
    std::cerr << "No file specified!" << std::endl;
    exit(-1);
  }
  file.open(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Could not open file '" << argv[1] << "'!" << std::endl;
    exit(-1);
  }

  while (std::getline(file, line)) {
    //
  }
}
