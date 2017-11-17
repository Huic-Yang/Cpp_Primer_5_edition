#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> creat_vector(std::vector<int>::size_type sz) {
  return std::make_shared<std::vector<int>>(sz);
}

std::shared_ptr<std::vector<int>> set_elements(
  std::shared_ptr<std::vector<int>> p_vec) {
  for (std::vector<int>::iterator it = p_vec->begin(); it != p_vec->end(); ++it)
    std::cin >> *it;
  return p_vec;
}

void print_elements(std::shared_ptr<std::vector<int>> p_vec) {
  for (std::vector<int>::size_type i = 0; i < p_vec->size(); ++i)
    std::cout << (*p_vec)[i] << ' ';
  std::cout << std::endl;
}

int main() {
  print_elements(set_elements(creat_vector(10)));

  return 0;
}
