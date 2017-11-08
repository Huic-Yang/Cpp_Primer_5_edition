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
void _10_3_3_lambda_expression();
void _10_3_4_find_if();
void _10_3_5_for_each();
void _10_3_6_lambda_capture_by_value();
void _10_3_7_lambda_capture_by_reference();
void _10_3_8_lambda_capture_iostream(std::ostream &os = std::cout);
void _10_3_9_lambda_implicit_captures();
void _10_3_10_lambda_mix_implicit_captures(std::ostream &os = std::cout);
void _10_3_11_lambda_mutable();
void _10_3_12_transform();
void _10_3_13_lambda_specify_return_type();
bool _10_3_14_check_size(const std::string &s, std::string::size_type sz);
void _10_3_15_bind();
void _10_3_16_bind_rearrange_parameters();
void _10_3_17_bind_reference();
void _10_4_1_istream_iterator();
void _10_4_2_ostream_iterator();
void _10_4_3_reverse_iterator();

int main() {
  _10_4_3_reverse_iterator();
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

void _10_3_3_lambda_expression() {
  int sz = 5;
  auto f = [sz](const std::string &str) { return str.size() >= sz; };
}

void _10_3_4_find_if() {
  std::vector<std::string> words = {
    "a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg"
  };
  int sz = 5;
  auto f = [sz](const std::string &s) { return s.size() >= sz; };
  std::sort(words.begin(), words.end(), is_shorter);
  std::vector<std::string>::iterator iter = std::find_if(words.begin(),
                                                         words.end(),
                                                         f);
  decltype(words)::difference_type count = words.end() - iter;
  std::cout << count << std::endl;
}

void _10_3_5_for_each() {
  std::vector<std::string> words = {
    "a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg"
  };
  std::for_each(words.begin(), words.end(),
                [](const std::string &s){ std::cout << s << ' '; });
  std::cout << std::endl;
}

void _10_3_6_lambda_capture_by_value() {
  size_t v1 = 42; // local variable
  // copies v1 into the callable object named f
  auto f = [v1] { return v1; };
  v1 = 0;
  auto j = f(); // j is 42 ; f stored a copy of v1 when we created it
}

void _10_3_7_lambda_capture_by_reference() {
  size_t v1 = 42; // local variable
  // the object f2 contains a reference to v1
  auto f2 = [&v1] { return v1; };
  v1 = 0;
  auto j = f2(); // j is 0 ; f2 refers to v1 ; it doesn¡¯t store it
}

void _10_3_8_lambda_capture_iostream(std::ostream &os) {
  std::vector<std::string> words = {
    "a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg"
  };
  auto print = [&os](const std::string &s){ os << s << ' '; };
  std::for_each(words.begin(), words.end(), print);
}

void _10_3_9_lambda_implicit_captures() {
  std::vector<std::string> words = {
    "a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg"
  };
  int sz = 5;
  auto wc = find_if(words.begin(), words.end(),
                    [=](const std::string &s){ return s.size() >= sz; });
}

void _10_3_10_lambda_mix_implicit_captures(std::ostream &os) {
  std::vector<std::string> words = {
    "a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg"
  };
  int sz = 5;
  auto print = [=, &os](const std::string &s) {
    if (s.size() >= sz) os << s << ' ';
  };
  std::for_each(words.begin(), words.end(), print);
}

void _10_3_11_lambda_mutable() {
  size_t v1 = 42;
  // f can change the value of the variables it captures
  auto f = [v1] () mutable { return ++v1; };
  v1 = 0;
  auto j = f(); // j is 43
}

void _10_3_12_transform() {
  std::vector<int> vec = {1, -1, 2, -2, 3, -3};
  std::transform(vec.begin(), vec.end(), vec.begin(),
                 [](int i) { return i > 0? i : -i; });
  for (auto &e: vec) std::cout << e << ' ';
  std::cout << std::endl;
}

void _10_3_13_lambda_specify_return_type() {
  std::vector<int> vec = {1, -1, 2, -2, 3, -3};
  std::transform(vec.begin(), vec.end(), vec.begin(),
                 [](int i) -> int { if (i > 0) return i; else return -i; });
  for (auto &e: vec) std::cout << e << ' ';
  std::cout << std::endl;
}

bool _10_3_14_check_size(const std::string &s, std::string::size_type sz) {
  return s.size() >= sz;
}

void _10_3_15_bind() {
  // check6 is a callable object that takes one argument of type string
  // and calls check_size on its given string and the value 6
  auto check6 = std::bind(_10_3_14_check_size, std::placeholders::_1, 6);
  if (!check6("Hello")) std::cout << "Hello has 5 characters" << std::endl;
  if (check6("Primer")) std::cout << "Primer has 6 characters" << std::endl;
}

void _10_3_16_bind_rearrange_parameters() {
  auto f = [](char a, char b, char c, char d, char e) {
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << std::endl;
  };
  auto g = std::bind(f, 'a', 'b', std::placeholders::_2,
                     'd', std::placeholders::_1);
  g('e', 'c');
}

void _10_3_17_bind_reference() {
  std::vector<std::string> words = {
    "a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg"
  };
  auto print = [](std::ostream &os, const std::string &s, char c) {
    os << s << c;
  };
  std::for_each(words.begin(), words.end(),
                std::bind(print, ref(std::cout), std::placeholders::_1, ' '));
}

void _10_4_1_istream_iterator() {
  std::vector<int> vec;
  std::istream_iterator<int> in_iter(std::cin); // read ints from cin
  std::istream_iterator<int> eof; // istream ‘‘end’’ iterator
  while (in_iter != eof) // while there’s valid input to read
  // postfix increment reads the stream and returns the old value of the iterator
  // we dereference that iterator to get the previous value read from the stream
    vec.push_back( * in_iter++);
}

void _10_4_2_ostream_iterator() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::ostream_iterator<int> out_iter(std::cout, " ");
  for (auto e : vec)
    * out_iter++ = e;
  // the assignment writes this element to cout
  std::cout << std::endl;
}

void _10_4_3_reverse_iterator() {
  std::string line = "Hello, my name is Huichen Yang";
  std::string::reverse_iterator r_white_space = std::find(line.crbegin(),
                                                          line.crend(), " ");
  std::cout << std::string(r_white_space.base(), line.cend()) << std::endl;
}






