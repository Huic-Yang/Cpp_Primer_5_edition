#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void func_1() {
  const char *str1 = "hello ";
  const char *str2 = "world";

  char *p_char = new char[strlen(str1) + strlen(str2) + 1];

  strcpy(p_char, str1);
  strcpy(p_char + strlen(str1), str2);

  cout << p_char << endl;
}

void func_2() {
  string str1 = "hello ";
  string str2 = "world";

  char *p_char = new char[str1.size() + str2.size() + 1];

  str1.copy(p_char, str1.size(), 0);
  str2.copy(p_char + str1.size(), str2.size(), 0);

  cout << p_char << endl;
}


int main() {
  func_1();
  func_2();
}
