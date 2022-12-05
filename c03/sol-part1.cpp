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
  std::string line;

  file.open("input");
  if (!file.is_open()) {
    exit(-1);
  }

  int sum = 0;
  int string_length = 0;
  std::string s1;
  std::string s2;
  std::vector<char> already_used;
  while (std::getline(file, line)) {
    std::cout << line << "\n";
    string_length = line.length();
    s1 = line.substr(0, string_length / 2);
    s2 = line.substr(string_length / 2, string_length);

    for (auto i = s1.begin(); i != s1.end(); ++i) {
      if (std::find(s2.begin(), s2.end(), *i) != s2.end() &&
          std::find(already_used.begin(), already_used.end(), *i) ==
              already_used.end()) {
        sum += charToPriority(*i);
        already_used.push_back(*i);
      }
    }
    already_used.clear();
  }

  std::cout << "sum: " << sum << std::endl;
}
