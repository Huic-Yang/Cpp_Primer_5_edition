#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

auto make_multimap() {
  std::multimap<std::string, std::string> authors = {
    {"Yale N. Patt", "Introduction to computer System"},
    {"Stanley B Lippman", "CPP Primer"}
  };
  authors.insert({"Donald E. Knuth", "Concrete Mathematics"});
  authors.insert({"Douglas B. West", "Introduction to Graph Theory"});
  return authors;
}

void erase_book(std::multimap<std::string, std::string> &authors) {
  std::string author_1 = "Issac Newton";
  std::string book_1 = "Mathematical Principles of Natural Philosophy";
  std::string author_2 = "Yale N. Patt";
  std::string book_2 = "Introduction to Computer System";
  auto fnd = authors.find(author_1);
  auto cnt = authors.count(author_1);
  while(cnt--) {
    if (fnd->second == book_1)
      authors.erase(fnd);
    ++fnd;
  }
  fnd = authors.find(author_2);
  cnt = authors.count(author_2);
  while(cnt--) {
    if (fnd->second == book_2)
      authors.erase(fnd);
    ++fnd;
  }
}
