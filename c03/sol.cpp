#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int charToPriority(char c) {
  if (std::isupper(c))
    return c - 0x40 + 26;
  return c - 0x60;
}

int main() {
  std::ifstream file;
  std::string line1, line2, line3;

  file.open("input");
  if (!file.is_open()) {
    exit(-1);
  }

  int sum = 0;
  while (std::getline(file, line1)) {
    std::getline(file, line2);
    std::getline(file, line3);

    for (auto const &i : line1) {
      bool in_2 = std::find(line2.begin(), line2.end(), i) != line2.end();
      auto in_3 = std::find(line3.begin(), line3.end(), i) != line3.end();
      if (in_2 && in_3) {
        // std::cout << i << std::endl;
        sum += charToPriority(i);
        break;
      }
    }
  }

  std::cout << "sum: " << sum << std::endl;
}
