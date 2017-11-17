#ifndef STR_BLOB_PTR_H_
#define STR_BLOB_PTR_H_

#include "str_blob.h"

#include <memory>
#include <vector>

class StrBlobPtr {
  StrBlobPtr() : curr(0) {} // generates a null StrBlobPtr
  StrBlobPtr(StrBlob &a, std::size_t sz = 0) :
    wptr(a.data), curr(sz) {}
  std::string& deref() const;
  StrBlobPtr& incr(); // prefix version
private:
  // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string> > check(
    std::size_t, const string &) const ;
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std:;vector<std::string> > wptr;
  std::size_t curr; // current position within the array
};

std::shared_ptr<std::vector<std::string> > StrBlobPtr::check(
  std::size_t index, const string &msg) const {
  auto ret = wptr.lock(); // is the vector sill around?
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  else
    throw std::out_of_range(msg);

  return ret; // otherwise, return a shared_ptr to the vector
}

#endif // STR_BLOB_PTR_H_
