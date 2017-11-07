// Ch10.cpp
// Generic Algorithm

#include <bits/stdc++.h>
using namespace std;

void _10_1_1_find_algorithm();
void _10_1_2_find_in_any_container();
void _10_1_3_find_in_built_in_arrays();
void _10_1_4_find_in_subrange();
// read algorithms
void _10_2_1_sum_of_integer_sequence();
void _10_2_2_sum_of_string();
void _10_2_3_equal();

int main() {
  _10_2_3_equal();
}

void _10_1_1_find_algorithm() {
  vector<int> vec = {41, 42, 43, 44, 45};
  int val = 42; // value we'll look for
  // result will donate the element we want if it's in vec, or vec.cend() if not
  auto result = find(vec.cbegin(), vec.cend(), val);
  // report the result
  cout << "The value " << val
       << (result == vec.cend()?
           " is not present" : " is present") << endl;
}

void _10_1_2_find_in_any_container() {
  list<string> lst;
  string val = "a value"; // value we'll look for
  // this call to find looks through string elements in a list
  auto result = find(lst.cbegin(), lst.cend(), val);
}

void _10_1_3_find_in_built_in_arrays() {
  int ia[] = {27, 210, 12, 47, 109, 83};
  int val = 83;
  int *result = find(begin(ia), end(ia), val);
}

void _10_1_4_find_in_subrange() {
  int ia[] = {27, 210, 12, 47, 109, 83};
  int val = 83;
  // search the elements starting from ia[1] up to but not including ia[4]
  auto result = find(ia + 1, ia + 4, val);
}

void _10_2_1_sum_of_integer_sequence() {
  // sum the elements in vec starting the summation with the value 0
  vector<int> vec = {27, 210, 12, 47, 109, 83};
  int sum = accumulate(vec.cbegin(), vec.cend(), 0);
  cout << "sum is " << sum << endl;
}

void _10_2_2_sum_of_string() {
  vector<string> v = {"Hello", " World", " Cpp"};
  string str = accumulate(v.cbegin(), v.cend(), string("")); // can't convert std::string to std::const char*
  cout << str << endl;
}

void _10_2_3_equal() {
  vector<string> vec = {"Hello", "World", "Cpp"};
  list<const char*> lst = {"Hello", "World", "Cpp"};
  bool same = equal(vec.cbegin(), vec.cend(), lst.cbegin());
  cout << (same? "same" : "not same") << endl;
}
