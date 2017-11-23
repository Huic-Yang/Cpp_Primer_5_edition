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

class QueryResult {
  const string _word;
  const size_t _occour_times;
  const set<int> _occour_lines;
  const vector<string> &_text;
public:
  QueryResult(const string &w, size_t ot,
              const set<int> &ol, const vector<string> &t) :
      _word(w), _occour_times(ot), _occour_lines(ol), _text(t) {}

  void print() {
    if (!_occour_times) {
      cout << "The word \"" << _word << "\" is not occurred!" << endl;
      return;
    }

    cout << "The word \"" << _word << "\" occurs " << _occour_times
         << ((_occour_times > 1)? " times." : " time.") << endl;
    cout << "It occurs at the following lines: " << endl;

    for (auto it = _occour_lines.cbegin(); it != _occour_lines.cend(); ++it) {
      cout << *it + 1 << ": ";
      cout << _text[*it] << endl;
    }
  }
};

class TextQuery {
  vector<string> _text;
  map<const string, set<int> > _lines;
public:
  TextQuery(const string &file) {
    ifstream input_file(file);
    size_t line_number = 0;
    for (string str; getline(input_file, str); ++line_number) {
      _text.push_back(str);
      stringstream ss(str);
      while (ss >> str) {
        str.erase(remove_if(str.begin(), str.end(),
                  [](char &ch){ return !isalpha(ch); }), str.end());
        _lines[str].insert(line_number);
      }
    }
  }

  QueryResult query(const string &w) {
    if (_lines.find(w) != _lines.cend())
      return QueryResult(w, _lines[w].size(), _lines[w], _text);
    else
    return QueryResult(w, 0, {}, {});
  }
};

void runQueries(const string &infile) {
  // infile is an ifstream that is the file we want to query
  TextQuery tq(infile); // store the file and build the query map
  // iterate with the user: prompt for a word to find and print results
  while (true) {
    cout << "enter word to look for, or q to quit: ";
    string s;
    // stop if we hit end-of-file on the input or if a ¡¯q¡¯ is entered
    if (!(cin >> s) || s == "q") break;
    // run the query and print the results
   tq.query(s).print();
  }
}

int main() {
  runQueries("In_me_past_present_future_meet.txt");

  return 0;
}
