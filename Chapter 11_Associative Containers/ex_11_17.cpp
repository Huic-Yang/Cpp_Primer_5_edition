#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>
using namespace std;

auto get_vector() {
  vector<string> vec = {"one", "two", "three", "four", "five",
                      "one", "two", "three", "four", "five"};
  return vec;
}

auto get_set() {
  set<string> c = {"one", "two", "three", "four", "five",
                   "one", "two", "three", "four", "five"};
  return c;
}

auto copy_1(const vector<string> &vec) {
  set<string> c;
  copy(vec.begin(), vec.end(), inserter(c, c.end()));
  return c;
}

/*
auto copy_2(const vector<string> &vec) {
  set<string> c;
  copy(vec.begin(), vec.end(), back_inserter(c));
  return c;
}
*/

auto copy_3(const set<string> &c) {
  vector<string> vec;
  copy(c.begin(), c.end(), inserter(vec, vec.end()));
  return vec;
}

auto copy_4(const set<string> &c) {
  vector<string> vec;
  copy(c.begin(), c.end(), back_inserter(vec));
  return vec;
}

template<typename Container>
void print(const Container &c) {
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    cout << *it << ' ';
  cout << endl;
}

int main() {
  print(copy_1(get_vector()));
  // print(copy_2(get_vector())); // set has no member `push_back`
  print(copy_3(get_set()));
  print(copy_4(get_set()));
}
