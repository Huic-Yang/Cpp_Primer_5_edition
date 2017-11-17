#include "str_blob.h"
// #include "str_blob_ptr.h"

#include <iostream>

int main() {
  StrBlob sb{"a", "b", "c"};

  auto beg = sb.begin();
  std::cout << beg.deref() << std::endl;

  return 0;
}
