#ifndef DEFINE_ASSOCIATIVE_CONTAINER_H_
#define DEFINE_ASSOCIATIVE_CONTAINER_H_

#include <set>
#include <map>

std::set<std::string> empty_string_set;

std::set<std::string> exclude = {
  "the", "but", "and", "or", "an", "a",
  "The", "But", "And", "Or", "An", "A"
};

std::map<std::string, std::string> authors = {
  {"Joyce", "James"},
  {"Austen", "Jane"},
  {"Dickens", "Charles"}
};

#endif // DEFINE_ASSOCIATIVE_CONTAINER_H_
