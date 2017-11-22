#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void read_string_in_array() {
  cout << "Enter the size: ";
  size_t sz; cin >> sz;
  char *arr = new char[sz + 1]; // the last one is '\0'
  cin.ignore(1024, '\n');
  cin.get(arr, sz);
  cout << arr << endl;
}


int main() {
  read_string_in_array();

  return 0;
}
