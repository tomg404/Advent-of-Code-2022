// Copyright 2022 Tom Gaimann

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

void fillVectorWithRange(int start, int end, std::vector<int> *vec) {
  for (; start <= end; ++start) {
    vec->push_back(start);
  }
}

int main(int argc, char **argv) {
  std::ifstream file;
  std::string line;

  if (argc < 2) {
    std::cerr << "No file specified!" << std::endl;
    exit(-1);
  }

  file.open(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Could not open file '" << argv[1] << "'!" << std::endl;
    exit(-1);
  }

  int sum = 0;
  std::vector<int> intersect;
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

    // check for overlap
    std::ranges::set_intersection(v1, v2, std::back_inserter(intersect));
    if (intersect.size() > 0)
      sum += 1;
    intersect.clear();
  }

  std::cout << sum << std::endl;
}
