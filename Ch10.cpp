// Ch10.cpp
// Generic Algorithm

#include <bits/stdc++.h>

void _10_1_1_find_algorithm();
void _10_1_2_find_in_any_container();
void _10_1_3_find_in_built_in_arrays();
void _10_1_4_find_in_subrange();
// read algorithms
void _10_2_1_sum_of_integer_sequence();
void _10_2_2_sum_of_string();
void _10_2_3_equal();
// write algorithms
void _10_2_4_fill();
void _10_2_5_fill_n();
void _10_2_6_back_inserter();
void _10_2_7_copy();
void _10_2_8_replace();
void _10_2_9_repalce_copy();
void _10_2_10_sort();
void _10_2_11_unique();
// customizing operation
bool is_shorter(const std::string &s1, const std::string &s2);
void _10_3_1_sort_with_predicate();
void _10_3_2_stable_sort();

int main() {
  _10_3_2_stable_sort();
}

void _10_1_1_find_algorithm() {
  std::vector<int> vec = {41, 42, 43, 44, 45};
  int val = 42; // value we'll look for
  // result will donate the element we want if it's in vec,
  // or vec.cend() if not
  auto result = std::find(vec.cbegin(), vec.cend(), val);
  // report the result
  std::cout << "The value " << val
       << (result == vec.cend()?
           " is not present" : " is present") << std::endl;
}

void _10_1_2_find_in_any_container() {
  std::list<std::string> lst;
  std::string val = "a value"; // value we'll look for
  // this call to find looks through string elements in a list
  auto result = std::find(lst.cbegin(), lst.cend(), val);
}

void _10_1_3_find_in_built_in_arrays() {
  int ia[] = {27, 210, 12, 47, 109, 83};
  int val = 83;
  int *result = std::find(std::begin(ia), std::end(ia), val);
}

void _10_1_4_find_in_subrange() {
  int ia[] = {27, 210, 12, 47, 109, 83};
  int val = 83;
  // search the elements starting from ia[1] up to
  // but not including ia[4]
  auto result = std::find(ia + 1, ia + 4, val);
}

void _10_2_1_sum_of_integer_sequence() {
  // sum the elements in vec starting the summation with the value 0
  std::vector<int> vec = {27, 210, 12, 47, 109, 83};
  int sum = std::accumulate(vec.cbegin(), vec.cend(), 0);
  std::cout << "sum is " << sum << std::endl;
}

void _10_2_2_sum_of_string() {
  std::vector<std::string> v = {"Hello", " World", " Cpp"};
  // can't convert std::string to std::const char*
  std::string str = std::accumulate(v.cbegin(),
                                    v.cend(), std::string(""));
  std::cout << str << std::endl;
}

void _10_2_3_equal() {
  std::vector<std::string> vec = {"Hello", "World", "Cpp"};
  std::list<const char*> lst = {"Hello", "World", "Cpp"};
  bool same = std::equal(vec.cbegin(),
                         vec.cend(), lst.cbegin());
  std::cout << (same? "same" : "not same") << std::endl;
}

void _10_2_4_fill() {
  std::vector<int> vec = {27, 210, 12, 47, 109, 83};
  std::fill(vec.begin(), vec.end(), 0); // reset each element to 0
  // set a subsequence of the container to 10
  std::fill(vec.begin(), vec.begin() + vec.size()/2, 10);
}

void _10_2_5_fill_n() {
  std::vector<int> vec = {27, 210, 12, 47, 109, 83};
  std::fill_n(vec.begin(), vec.size(), 0);
}

void _10_2_6_back_inserter() {
  std::vector<int> vec; // empty vector
  auto it = back_inserter(vec); // assigning through it adds element to vec
  *it = 42; // vec now has one element with value 42
  // ok: back_inserter creates an insert iterator that adds elements to vec
  std::fill_n(back_inserter(vec), 10, 0); // appends ten elements to vec
}

void _10_2_7_copy() {
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int a2[sizeof(a1)/sizeof(*a1)]; // a2 has the same size as a1
  // ret points just past the last element copied into a2
  auto ret = std::copy(std::begin(a1), std::end(a1), a2); // copy a1 into a2
}

void _10_2_8_replace() {
  std::list<int> ilst = {1, 2, 3, 0, 0, 0};
  // replace any element with the element with the value 0 with 42
  std::replace(ilst.begin(), ilst.end(), 0, 42);
  for (auto& elem: ilst) std::cout << elem << ' ';
  std::cout << std::endl;
}

void _10_2_9_repalce_copy() {
  std::list<int> ilst = {1, 2, 3, 0, 0, 0};
  std::vector<int> ivec;
  // use back_inserter to grow destination as needed
  replace_copy(ilst.cbegin(), ilst.cend(),
  back_inserter(ivec), 0, 42);
}

void _10_2_10_sort() {
  std::vector<std::string> words = {"Hello", "World", "Cpp", "Primer"};
  std::sort(words.begin(), words.end());
  for (auto& elem: words) std::cout << elem << ' ';
  std::cout << std::endl;
}

void _10_2_11_unique() {
  std::vector<std::string> words = {"Hello", "World", "Cpp", "Primer",
                                    "Hello", "World", "Python"};
  std::sort(words.begin(), words.end());
  // unique reorders the input range so that each word appears once in the front
  // portion of the range and returns an iterator one past the unique range
  std::vector<std::string>::iterator end_unique =
    std::unique(words.begin(), words.end());
  // erase uses a vector operation to remove the nonunique elements
  words.erase(end_unique, words.end());
  for (auto& elem: words) std::cout << elem << ' ';
  std::cout << std::endl;
}

bool is_shorter(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}

void _10_3_1_sort_with_predicate() {
  std::vector<std::string> words = {"One", "Two", "Three",
                                    "four", "five", "six"};
  std::sort(words.begin(), words.end(), is_shorter);
  for (auto &elem: words) std::cout << elem << ' ';
  std::cout << std::endl;
}

void _10_3_2_stable_sort() {
  std::vector<std::string> words = {"Hello", "World", "Cpp", "Primer",
                                    "Hello", "World", "Python", "one",
                                    "two", "three", "four"};
  std::sort(words.begin(), words.end());
  std::vector<std::string>::iterator
    end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());

  std::stable_sort(words.begin(), words.end(), is_shorter);
  for (auto &e: words) std::cout << e << ' ';
  std::cout << std::endl;
}





