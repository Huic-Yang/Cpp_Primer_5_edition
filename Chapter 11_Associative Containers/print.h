#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>
#include <map>

template<typename SequentialContainer>
void print_sequence(SequentialContainer &c) {
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;
}

template<typename map>
void print_map(map &mp) {
  for (auto &w: mp)
    std::cout << w.first << ' ' << w.second << std::endl;
}


#endif // PRINT_H_
