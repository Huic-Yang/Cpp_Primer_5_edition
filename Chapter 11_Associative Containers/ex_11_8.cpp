#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using std::vector;
using std::string;
using std::set;
using std::cin;
using std::cout;

bool check_in(vector<string> words, string word) {
  return find(words.cbegin(), words.cend(), word) != words.cend();
}

void test() {
  vector<string> words = {
    "the", "but", "and", "or", "an", "a",
    "The", "But", "And", "Or", "An", "A"
  };
  for (string word; cin >> word; )
    cout << (check_in(words, word)? "In\n" : "Not in\n");
}

int main() {
  test();
}
