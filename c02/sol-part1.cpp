#include <fstream>
#include <iostream>
#include <variant>

int DRAW_VALUE = 3;
int WIN_VALUE = 6;
int LOOSE_VALUE = 0;

struct Rock {
  int value = 1;
} rock;
struct Paper {
  int value = 2;
} paper;
struct Scissor {
  int value = 3;
} scissor;
struct Win {};
struct Draw {};
struct Loose {};

using Shape = std::variant<Rock, Paper, Scissor>;

int eval(Rock, Shape *s) {
  if (std::holds_alternative<Rock>(*s))
    return DRAW_VALUE + rock.value;
  if (std::holds_alternative<Paper>(*s))
    return WIN_VALUE + paper.value;
  return LOOSE_VALUE + scissor.value;
}

int eval(Paper, Shape *s) {
  if (std::holds_alternative<Rock>(*s))
    return LOOSE_VALUE + rock.value;
  if (std::holds_alternative<Paper>(*s))
    return DRAW_VALUE + paper.value;
  return WIN_VALUE + scissor.value;
}

int eval(Scissor, Shape *s) {
  if (std::holds_alternative<Rock>(*s))
    return WIN_VALUE + rock.value;
  if (std::holds_alternative<Paper>(*s))
    return LOOSE_VALUE + paper.value;
  return DRAW_VALUE + scissor.value;
}

void getShape(char c, Shape *v) {
  if (c == 'A' || c == 'X')
    *v = rock;
  else if (c == 'B' || c == 'Y')
    *v = paper;
  else if (c == 'C' || c == 'Z')
    *v = scissor;
}

struct ShapeVisitor {
  int operator()(Rock, Shape p2) const { return eval(Rock{}, &p2); }
  int operator()(Paper, Shape p2) const { return eval(Paper{}, &p2); }
  int operator()(Scissor, Shape p2) const { return eval(Scissor{}, &p2); }
};

int main() {
  std::ifstream file;
  std::string line;

  file.open("input");
  if (!file.is_open()) {
    exit(-1);
  }

  Shape p1;
  Shape p2;
  int sum = 0;
  while (std::getline(file, line)) {
    getShape(line[0], &p1);
    getShape(line[2], &p2);
    int a = std::visit(ShapeVisitor{}, p1, p2);
    sum += a;
    // std::cout << a << std::endl;
  }

  std::cout << sum << std::endl;
}
