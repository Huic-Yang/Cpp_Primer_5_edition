#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::ifstream;
using std::istringstream;

auto make_transform_map(string map_file) {
  ifstream in(map_file);
  map<string, string> transform_map;
  string word, transformed_word;
  while (in >> word >> transformed_word)
    transform_map[word] = transformed_word;
  return transform_map;
}

void transform(const map<string, string> &trans_map, string input_file) {
  ifstream in(input_file);
  for (string text, word; getline(in, text); ) {
    istringstream ss(text);
    bool first_word = true;
    while (ss >> word) {
      if (first_word)
        first_word = false;
      else
        cout << " ";
      auto it = trans_map.find(word);
      cout << (it == trans_map.end()? word : it->second);
    }
    cout << endl;
  }
}

int main(int argc, char* argv[]) {
  transform(make_transform_map(argv[1]), argv[2]);
  return 0;
}
