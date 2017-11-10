#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  // get an iterator positioned on the first element
  map<string, size_t>::const_iterator map_it = word_count.cbegin();
  // compare the current iterator to the off-the-end iterator
  while (map_it != word_count.cend()) {
  // dereference the iterator to print the element key--value pairs
  cout << map_it->first << " occurs "
       << map_it->second << " times" << endl;
  ++map_it; // increment the iterator to denote the next element
}
}
