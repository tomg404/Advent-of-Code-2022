#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string line;
  std::ifstream file;
  std::array<int, 3> maxArray{0, 0, 0};

  file.open("input");
  if (!file.is_open()) {
    exit(-1);
  }

  int sum = 0;
  while (std::getline(file, line)) {
    if (line.empty()) {
      auto min_in_array = *std::min_element(maxArray.begin(), maxArray.end());
      auto idx_of_min = std::distance(
          maxArray.begin(),
          std::find(maxArray.begin(), maxArray.end(), min_in_array));

      if (sum > min_in_array) {
        maxArray.at(idx_of_min) = sum;
      }

      sum = 0;
      continue;
    }
    sum += stoi(line);
  }

  int total;
  for (auto const &t : maxArray)
    total += t;

  std::cout << total << std::endl;
}
