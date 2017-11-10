#include <vector>
#include <list>
#include <map>

using std::vector;
using std::list;
using std::map;

int main() {
  map<list<int>::const_iterator, int> mp_lst;
  map<vector<int>::const_iterator, int> mp_vec;
  list<int> lst = {1, 2, 3, 4, 5, 6, 7};
  vector<int> vec(lst.cbegin(), lst.cend());
  // mp_lst[lst.cbegin()] = 0;
  // mp_lst[lst.cend()] = 6;
  mp_vec[vec.cbegin()] = 0;
  mp_vec[vec.cend()] = 6;
}
