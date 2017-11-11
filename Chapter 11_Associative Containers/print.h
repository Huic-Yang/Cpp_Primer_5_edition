#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <forward_list>
#include <deque>

template<typename T>
std::ostream& operator<<(std::ostream &os, std::vector<T> c) {
  for (const auto &e: c)
    std::cout << c << ' ';
  std::cout << std::endl;
  return os;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, std::deque<T> c) {
  for (const auto &e: c)
    std::cout << c << ' ';
  std::cout << std::endl;
  return os;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, std::list<T> c) {
  for (const auto &e: c)
    std::cout << c << ' ';
  std::cout << std::endl;
  return os;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, std::forward_list<T> c) {
  for (const auto &e: c)
    std::cout << c << ' ';
  std::cout << std::endl;
  return os;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, std::set<T> c) {
  for (const auto &e: c)
    std::cout << c << ' ';
  std::cout << std::endl;
  return os;
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream &os, std::map<K, V> mp) {
  for (const auto &p: mp)
    std::cout << p.first << ": " << p.second << "; ";
  return os;
}

#endif // PRINT_H_
