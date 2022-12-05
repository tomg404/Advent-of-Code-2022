// Copyright 2022 Tom Gaimann

// Often used libraries
#include <algorithm>
#include <array>
#include <cstdint>
#include <deque>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

#define NUMBER_OF_CRATES 9

// note: intended no pointer to crates as the copy is wanted
void print_crates(std::array<std::deque<char>, NUMBER_OF_CRATES> *crates) {
  for (uint64_t i = 0; i < crates->size(); ++i) {
    std::cout << "crate " << i + 1
              << ", front elem: " << (int)(*crates)[i].front()
              << ", back elem: " << (*crates)[i].back()
              << ", size: " << crates->size() << std::endl;
    for (uint64_t i = 0; i < crates->size(); ++i) {
      //
    }
  }
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

  // Phase 1 - read image
  std::array<std::deque<char>, NUMBER_OF_CRATES> crates;
  crates.fill(std::deque<char>{});
  while (std::getline(file, line)) {
    // break out of loop if end of image is reached
    if (line[1] == '1')
      break;

    // push characters into deque back
    char buf;
    for (uint64_t i = 0; i < crates.size(); ++i) {
      buf = line[i * 4 + 1];
      if (buf != ' ')
        crates[i].push_back(buf);
    }
  }

  // skip blank line
  std::getline(file, line);

  // Phase 2 - move stuff
  int containers_to_move, from_id, to_id;
  while (std::getline(file, line)) {
    std::sscanf(line.c_str(), "move %d from %d to %d", &containers_to_move,
                &from_id, &to_id);

    from_id -= 1;
    to_id -= 1;

    std::vector<char> tmp;
    for (int i = 0; i < containers_to_move; ++i) {
      tmp.push_back(crates[from_id].front());
      crates[from_id].pop_front();
    }

    for (auto i = tmp.rbegin(); i != tmp.rend(); ++i) {
      crates[to_id].push_front(*i);
    }
    // print_crates(&crates);
    // std::cout << "next movement" << std::endl;
  }

  for (uint64_t i = 0; i < crates.size(); ++i) {
    std::cout << crates[i].front();
  }
  std::cout << std::endl;
}
