#ifndef STRBLOB_H_
#define STRBLOB_H_


#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // add and remove elements
  void push_back(const std::string &t) {data->push_back(t);}
  void pop_back();
  // element access
  std::string& front();
  std::string& back();
  const std::string& front() const;
  const std::string& back() const;
  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr cbegin();
  ConstStrBlobPtr cend();
private:
  std::shared_ptr<std::vector<std::string>> data;
  // throws msg if data[i] isn’t valid
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
  StrBlobPtr() : curr(0) {} // generates a null StrBlobPtr
  StrBlobPtr(StrBlob &a, std::size_t sz = 0) :
    wptr(a.data), curr(sz) {}
  StrBlobPtr(const StrBlobPtr &sbp) :
    wptr(sbp.wptr.lock()), curr(sbp.curr) {}
  std::string& deref() const;
  StrBlobPtr& incr(); // prefix version
  bool operator!= (const StrBlobPtr &sbp) {
    return wptr.lock() != sbp.wptr.lock() || curr != sbp.curr;
  }
private:
  // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string> > check(
    std::size_t, const std::string &) const ;
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<std::string> > wptr;
  std::size_t curr; // current position within the array
};

class ConstStrBlobPtr {
public:
  ConstStrBlobPtr() : curr(0) {} // generates a null StrBlobPtr
  ConstStrBlobPtr(StrBlob &a, std::size_t sz = 0) :
    wptr(a.data), curr(sz) {}
  ConstStrBlobPtr(const ConstStrBlobPtr &sbp) :
    wptr(sbp.wptr.lock()), curr(sbp.curr) {}
  const std::string& deref() const {
    return (*check(curr, "dereference past end"))[curr];
  }
  ConstStrBlobPtr& incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  }
  bool operator!= (const ConstStrBlobPtr &sbp) {
    return wptr.lock() != sbp.wptr.lock() || curr != sbp.curr;
  }
private:
  // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string> > check(
    std::size_t, const std::string &) const ;
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<std::string> > wptr;
  std::size_t curr; // current position within the array
};

StrBlobPtr StrBlob::begin() {
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
  return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() { return ConstStrBlobPtr(*this, data->size()); }

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string> >()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
  : data(std::make_shared<std::vector<std::string> >(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (data->size() <= i)
    throw std::out_of_range(msg);
}

std::string& StrBlob::front() {
  check(0, "font on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

// It will be called only if the instance of StrBlob is a const object.
const std::string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

// It will be called only if the instance of StrBlob is a const object.
const std::string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

std::shared_ptr<std::vector<std::string> > StrBlobPtr::check(
    std::size_t index, const std::string &msg) const {
  auto ret = wptr.lock(); // is the vector sill around?
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  else if (ret->size() <= index)
    throw std::out_of_range(msg);

  return ret; // otherwise, return a shared_ptr to the vector
}

std::string& StrBlobPtr::deref() const {
  std::shared_ptr<std::vector<std::string> >
  sp = check(curr, "dereference past end");
  return (*sp)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
  // if curr already points the end of the container, can't increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

std::shared_ptr<std::vector<std::string> > ConstStrBlobPtr::check(
    std::size_t index, const std::string &msg) const {
  auto ret = wptr.lock(); // is the vector sill around?
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  else if (ret->size() <= index)
    throw std::out_of_range(msg);

  return ret; // otherwise, return a shared_ptr to the vector
}

#endif // STRBLOB_H_
