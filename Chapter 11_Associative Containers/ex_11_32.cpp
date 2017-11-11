#include "ex_11_31.cpp"

#include <iostream>
#include <string>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::multimap;
using std::string;
using std::endl;
using std::map;
using std::set;

void print_authors_alphabetically(const multimap<string, string> &authors) {
  map<string, multiset<string> > ordered_authors;
  for (const auto &author: authors)
    ordered_authors[author.first].insert(author.second);
  for (auto it = ordered_authors.cbegin(); it != ordered_authors.cend(); ++it) {
    cout << it->first << ": ";
    for (const auto &book: it->second)
      cout << book << ' ';
    cout << endl;
  }
}

int main() {
  print_authors_alphabetically(make_multimap());
  return 0;
}
