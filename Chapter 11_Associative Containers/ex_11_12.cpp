#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

void print_pair_vector(vector<pair<string, int> > pair_vector) {
  for (const auto &p: pair_vector)
    cout << p.first << ' ' << p.second << endl;
}

template<typename K, typename V>
auto get_pair_vector(vector<K> &keys, vector<V> &values) {
  vector<pair<K, V> > pair_vector;
  for (auto it_key = keys.cbegin(), it_value = values.cbegin();
       it_key != keys.cend() && it_value != values.cend();
       ++it_key, ++it_value)
    pair_vector.push_back(make_pair(*it_key, *it_value));
  return pair_vector;
}

int main() {
  vector<string> svec = {"one", "two", "three", "four", "five"};
  vector<int> ivec = {1, 2, 3, 4, 5};
  print_pair_vector(get_pair_vector(svec, ivec));
  return 0;
}
