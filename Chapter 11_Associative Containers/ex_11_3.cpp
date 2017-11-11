#include "print.h"

#include <iostream>
#include <string>
#include <map>
#include <set>

void count() {
  std::map<std::string, size_t> mp;
  for (std::string w; std::cin >> w; ++mp[w]) {}
  std::cout << mp << std::endl;
}

int main() {
  count();
}
