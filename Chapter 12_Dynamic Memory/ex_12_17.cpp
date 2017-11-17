#include <iostream>
#include <memory>
#include <string>
using namespace std;


int main() {
  int ix = 1024, *pi = &ix, *pi2 = new int(2048);
  typedef unique_ptr<int> IntP;


  /**
   * @brief invalid conversion from 'int' to 'std::unique_ptr<int>::pointer {aka int*}'
   */
  // IntP p0(ix);

  /**
   * @brief when the unique_ptr is out of scope, delete will be called to free
   * the object not allocated using new, which causes a run time error.
   */
  IntP p1(pi);

  /**
   * @brief It causes a dangling pointer at run time.
   */
  IntP p2(pi2);

  /**
   * @brief The same as p1
   */
  IntP p3(&ix);

  /**
   * @brief safely.
   */
  IntP p4(new int(2048));

  /**
   * @brief error: double free
   */
  IntP p5(p2.get());

  return 0;
}
