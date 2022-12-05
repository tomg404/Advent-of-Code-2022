#include <fstream>
#include <iostream>
#include <variant>

enum shapes {
  rock = 1,
  paper = 2,
  scissor = 3,
};

enum outcome {
  loose = 0,
  draw = 3,
  win = 6,
};

int require_win(int s) {
  switch (s) {
  case rock:
    return paper;
  case paper:
    return scissor;
  case scissor:
    return rock;
  }
  return -99999;
}

int require_draw(int s) { return s; }

int require_loose(int s) {
  switch (s) {
  case rock:
    return scissor;
  case paper:
    return rock;
  case scissor:
    return paper;
  }
  return -99999;
}

int evaluate(int s, int o) {
  switch (o) {
  case win:
    return require_win(s) + 6;
  case draw:
    return require_draw(s) + 3;
  case loose:
    return require_loose(s) + 0;
  }
  return -99999;
}

int getEnum(char c) {
  switch (c) {
  case 'A':
    return rock;
  case 'B':
    return paper;
  case 'C':
    return scissor;
  case 'X':
    return loose;
  case 'Y':
    return draw;
  case 'Z':
    return win;
  }
  return -99999;
}

int main() {
  std::ifstream file;
  std::string line;

  file.open("input");
  if (!file.is_open()) {
    throw std::runtime_error{"could not open file"};
  }

  int sum = 0;
  while (std::getline(file, line)) {
    sum += evaluate(getEnum(line[0]), getEnum(line[2]));
  }

  std::cout << sum << std::endl;
}
