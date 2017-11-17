#include "str_blob.h"

#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream in("In_me_past_present_future_meet.txt");
  StrBlob sb;
  for (std::string str; std::getline(in, str); )
    sb.push_back(str);
  for (auto ptr = sb.cbegin(); ptr != sb.cend(); ptr.incr())
    std::cout << ptr.deref() << std::endl;

  return 0;
}
