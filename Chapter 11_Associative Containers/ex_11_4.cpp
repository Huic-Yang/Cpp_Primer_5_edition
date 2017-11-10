#include "print.h"

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

auto tolower_and_strip(std::string &s) -> const std::string & {
  std::transform(s.begin(), s.end(), s.begin(), tolower);
  s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
  return s;
}

auto count() {
  std::map<std::string, size_t> mp;
  for (std::string w; std::cin >> w; ++mp[tolower_and_strip(w)]) {}
  print_map(mp);
}

int main() {
  count();
}
