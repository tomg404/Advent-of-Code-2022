// Copyright 2022 Tom Gaimann

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

void fillVectorWithRange(int start, int end, std::vector<int> *vec) {
  for (; start <= end; ++start) {
    vec->push_back(start);
  }
}

int main() {
  std::ifstream file;
  std::string line;

  file.open("input");
  if (!file.is_open()) {
    exit(-1);
  }

  int sum = 0;
  while (std::getline(file, line)) {
    // parse intervals
    int elf_1_start, elf_1_end, elf_2_start, elf_2_end;
    std::sscanf(line.c_str(), "%d-%d,%d-%d", &elf_1_start, &elf_1_end,
                &elf_2_start, &elf_2_end);

    // create vectors
    std::vector<int> v1;
    fillVectorWithRange(elf_1_start, elf_1_end, &v1);
    std::vector<int> v2;
    fillVectorWithRange(elf_2_start, elf_2_end, &v2);

    // check for inclusion
    if (std::ranges::includes(v1, v2) || std::ranges::includes(v2, v1)) {
      sum += 1;
    }
  }

  std::cout << sum << std::endl;
}
