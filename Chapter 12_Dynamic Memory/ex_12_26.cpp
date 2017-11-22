#include <iostream>
#include <string>
#include <memory>
using namespace std;

void allocator_for_string() {
  cout << "Enter the size: ";
  size_t sz; cin >> sz;

  allocator<string> a;
  string *p = a.allocate(sz);
  const size_t c_sz = sz;

  string str;
  auto q = p;
  while (cin >> str && q != p + c_sz)
    a.construct(q++, str);

  for (auto r = p; r != q; ++r)
    cout << *r << ' ';
  cout << endl;

  while (q != p)
    a.destroy(--q);
  a.deallocate(p, c_sz);
}

int main() {
  allocator_for_string();

  return 0;
}
