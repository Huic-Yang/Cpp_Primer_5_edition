// word_count,cpp
#include <iostream>
#include <string>
#include <map>

void word_count() {
  // count the number of times each word occurs in the input
  std::map<std::string, size_t> word_count; // empty map from string to size_t
  std::string word;
  while (std::cin >> word)
    ++word_count[word]; // fetch and increment the count for word

  for (const auto &w: word_count)
    std::cout << w.first << " occurs " << w.second
         << ((w.second > 1)? " times." : " time.") << std::endl;
}

int main() {
  word_count();
}
