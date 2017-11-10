#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <sstream>

using std::string;
using std::map;
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::istringstream;

auto read_file() {
  ifstream poem("ex_11_9.cpp");
  map<string, list<int> > words;
  string line;
  for (int line_number = 1; getline(poem, line); ++line_number) {
    istringstream istr(line);
    string word;
    auto isnalpha = [](const char ch) { return !isalpha(ch); };
    while (istr >> word) {
      word.erase(std::remove_if(word.begin(), word.end(), isnalpha), word.end());
      if (!word.empty())
        words[word].push_back(line_number);
    }
  }
  return words;
}

void print(map<string, list<int> > words) {
  for (const auto &word: words) {
    cout << "Word: " << word.first << "\nline number: ";
    for (int line_number: word.second)
      cout << line_number << ' ';
    cout << endl;
  }
}

int main() {
  print(read_file());
  return 0;
}
