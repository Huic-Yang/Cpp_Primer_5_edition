#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

auto make_map() {
  std::map<std::string, std::vector<int> > mp;
  for (std::string w; std::cout << "Enter word: \n", std::cin >> w && w != "@q"; ) {
    for (int i; std::cout << "|-Enter number: \n", std::cin >> i && i != -1; ) {
      mp[w].push_back(i);
    }
  }
  return mp;
}

auto find_word_at(const std::map<std::string, std::vector<int> > mp) {
  for (std::string w; std::cout << "Finding word: \n", std::cin >> w && w != "@q"; ) {
    auto p = mp.find(w);
    if (p == mp.end()) {
      std::cout << "Not found." << std::endl;
      continue;
    }
    for (const auto &e: p->second)
      std::cout << e << ' ';
    std::cout << std::endl;
  }
}

int main() {
  find_word_at(make_map());
  return 0;
}
