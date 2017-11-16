#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <sstream>
using namespace std;

class Fib {
  int f, g;
public:
  Fib(int n) : f(1), g(0) { while (g < n) next(); }
  int get() { return g; }
  int next() { g += f; f = g - f; return g; }
  int prev() { f = g - f; g -= f; return g; }
};

int main() {
  Fib fib(7);
  while (8 < fib.get()) fib.prev();
  cout << fib.get() << endl;
  return 0;
}
