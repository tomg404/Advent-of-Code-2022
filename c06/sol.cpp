// Copyright 2022 Tom Gaimann8

// Often used libraries
#include <algorithm>
#include <array>
#include <bits/ranges_algo.h>
#include <deque>
#include <fstream>
#include <iostream>
#include <type_traits>
#include <vector>

bool is_marker(std::string_view s, size_t msg_length) {
  if (s.length() < msg_length)
    return false;

  return std::ranges::find_if(s, [&s](auto c) {
           return std::ranges::count(s, c) > 1;
         }) == s.end();
}

void find_marker(std::string_view stream, size_t msg_length) {
  std::string_view cursor;
  auto marker = 0;

  for (auto i = stream.begin(); i != stream.end(); ++i) {
    marker = i - stream.begin();
    cursor = stream.substr(marker, msg_length);
    if (is_marker(cursor, msg_length)) {
      break;
    }
  }

  marker += msg_length;

  std::cout << "Marker found for length " << msg_length << " at position "
            << marker << std::endl;
}

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

  std::getline(file, line);

  find_marker(line, 4);
  find_marker(line, 14);
}
