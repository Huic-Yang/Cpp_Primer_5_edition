#include <iostream>

bool b1() {
  int *p = new int;
  return p;
}

bool b2() {
  int *p = new int;
  delete p; p = nullptr;
  return p;
}

int main() {
  std::cout << (b1()? "true" : "false") << std::endl;
  std::cout << (b2()? "true" : "false") << std::endl;

  return 0;
}
