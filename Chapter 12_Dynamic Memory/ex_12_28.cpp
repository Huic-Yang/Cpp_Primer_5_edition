#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <map>
#include <algorithm>
#include <set>
#include <vector>

using std::vector;
using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;
using std::remove_if;

void query(const string &file_name) {
  map<const string, set<size_t> > _lines_of;
  vector<string> _text;
  _text.push_back("");

  ifstream _input(file_name);
  string str;
  for (size_t _line_number = 1; getline(_input, str); ++_line_number) {
    _text.push_back(str);
    stringstream ss(str);
    while (ss >> str) {
      str.erase(remove_if(str.begin(), str.end(),
                          [](char &ch){ return !isalpha(ch); }), str.end());
      _lines_of[str].insert(_line_number);
    }
  }

  while (1) {
    cout << "Enter the word you want to query: ";
    cin >> str;
    if (str == "q") return;
    auto _fnd = _lines_of.find(str);
    if (_fnd == _lines_of.end())
      cout << "This word \"" << str << "\" is not in the text!" << endl;
    else {
      auto &_lines = _lines_of[str];
      cout << "This word \"" << str << "\" occurs " << _lines.size()
           << ((_lines.size() > 1)? " times." : " time.") << endl;
      for (auto _line = _lines.begin(); _line != _lines.end(); ++_line)
        cout << *_line << ": " << _text[*_line] << endl;
    }
  }
}

int main() {
  query("In_me_past_present_future_meet.txt");

  return 0;
}
