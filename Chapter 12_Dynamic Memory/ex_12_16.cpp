#include <iostream>
#include <memory>

void f() {
  std::unique_ptr<int> p(new int(1024));
  auto q = p;
}

int main() {
  f();

  return 0;
}

/**
use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(
const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'
*/
