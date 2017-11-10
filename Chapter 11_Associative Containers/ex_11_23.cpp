#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
using std::multimap;
using std::cin;
using std::cout;
using std::pair;
using Families = multimap<string, vector<string> >;

auto make_families() {
  Families families;
  for (string last_name;
       cout << "Last name: ", cin >> last_name && last_name != "@q"; ) {
    auto res = families.insert(std::make_pair(last_name, vector<string>()));
    for (string child_name;
         cout << "Child name: ", cin >> child_name && child_name != "@q"; )
      res->second.push_back(child_name);
  }
  return families;
}

auto print(Families const& families)
{
    for (auto const& family : families)
    {
        cout << family.first << ":\n";
        for (auto const& child : family.second)
            cout << child << ' ';
        cout << "\n";
    }
}

int main()
{
    print(make_families());
    return 0;
}
