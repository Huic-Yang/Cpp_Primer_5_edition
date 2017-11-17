#include <iostream>
#include <vector>

void print_elements(std::vector<int> *p_vec) {
  for (const auto &e: *p_vec)
    std::cout << e << ' ';
  std::cout << std::endl;
  delete p_vec;
}

std::vector<int>* set_elements(std::vector<int> *p_vec) {
  for (auto &e: *p_vec)
    std::cin >> e;
  return p_vec;
}

std::vector<int>* creat_vector(std::vector<int>::size_type sz) {
  std::vector<int> *p_vec = new std::vector<int>(sz);
  return p_vec;
}

int main() {
  print_elements(set_elements(creat_vector(10)));

  return 0;
}
