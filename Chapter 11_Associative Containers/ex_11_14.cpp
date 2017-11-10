#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::pair;
using Families = map<string, vector<pair<string, string>> >;

auto make_families()
{
    Families families;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn, bd; cout << "|-Children's names and birthday:\n",
        cin >> cn && cn != "@q" && cin >> bd && bd != "@q";)
            families[ln].push_back({cn, bd});
    return families;
}

auto print(Families const& families)
{
    for (auto const& family : families)
    {
        cout << family.first << ":\n";
        for (auto const& child : family.second)
            cout << child.first << " " << child.second << '\n';
        cout << "\n";
    }
}

int main()
{
    print(make_families());
    return 0;
}
