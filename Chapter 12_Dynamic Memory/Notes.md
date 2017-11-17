## Memory
`static memory`: local static objects, class static data members, and for
variables defined outside any functions. It is created when they are used and
destroyed when the program ends by the compiler.

`stack memory`: used for nonstatic objects defined inside functions. They are
created and destroyed by compiler when the block in which they are defined is
entered and exited.

`heap`: for objects that they dynamically allocate.

## Problem for Free Memory
`memory leak`: forget to free the memory. The memory is never returned to the
free store.

`point to the freed memory`: free the memory when there are still memory
pointers referring to that memory (no longer valid).

`Use an object that it has been deleted`

## Smart Pointers
 `shared_ptr`: allows multiple pointers to refer to the same object.

 `unique_ptr`: "owns" the object to which it points.

 `weak_ptr`: weak reference.

## shared_ptr Class
### make_shared
This function allocates and initializes an objects in dynamic memory and
returns a shared_ptr that points to that object. a call to this function should
pass argument(s) that match one of the constructors.
```cpp
// shared_ptr that points to an int with value 42
shared_ptr<int> p3 = make_shared<int>(42);
// p4 points to a string with value 9999999999
shared_ptr<string> p4 = make_shared<string>(10, ’9’);
// p5 points to an int that is value initialized (§ 3.3.1 (p. 98)) to 0
shared_ptr<int> p5 = make_shared<int>();
```

### Operations Common for shared_ptr and unique_ptr
```cpp
shared_ptr<T> sp // Null smart pointer that can point to objects of type T.
unique_ptr<T> up

p               // Use p as a condition; true if p points to an object.

*p              // Dereference p to get the object to which p points.

p->mem          // Synonym for ( * p).mem.

p.get()         // Returns the pointer in p. Use with caution; the object
                // to which the returned pointer points will disappear
                // when the smart pointer
                // deletes it.

swap(p, q)      // Swaps the pointers in p and q.
p.swap(q)
```

### Operations Specific to shared_ptr
```cpp
make_shared<T>(args) // Returns a shared_ptr pointing to a dynamically allocated
                     // object of type T. Uses args to initialize that object.

shared_ptr<T> p(q)   // p is a copy of the shared_ptr q; increments the count
                     // in q. The pointer in q must be convertible to T*;

p = q                // p and q are shared_ptrs holding pointers that can be
                     // converted to one another. Decrements p’s reference count
                     // and increments q’s count; deletes p’s existing memory
                     // if p’s count goes to 0.

p.unique()           // Returns true if p.use_count() is one; false otherwise.

p.use_count()        // Returns the number of objects sharing with p; may be a
                     // slow operation, intended primarily for debugging
                     // purposes.        

shared_ptr<T> p(q)   // p manages the object to which the built-in pointer q
                     // points; q must point to memory allocated by new and must
                     // be convertible to T * .

shared_ptr<T> p(u)   // p assumes ownership from the unique_ptr u; makes u null.

shared_ptr<T> p(q, d) // p assumes ownership for the object to which the
                      // built-in pointer q points. q must be convertible to
                      // T * (§ 4.11.2, p. 161). p will use the callable object
                      // d (§ 10.3.2, p. 388) in place of delete to free q.

shared_ptr<T> p(p2, d) // p is a copy of the shared_ptr p2 as described in
                       // Table 12.2 except that p uses the callable object d
                       // in place of delete.
p.reset()              // If p is the only shared_ptr pointing at its object,
p.reset(q)             // reset frees p’s existing object. If the optional
p.reset(q, d)          // built-in pointer q is passed, makes p point to q,
                       // otherwise makes p null. If d is supplied,  will call
                       // d to free q otherwise uses delete to free q.                  
```

### Copyint and Assigning shared_ptr
```cpp
auto p = make_shared<int>(42);
auto q(p);
```
**Reference count**:
The reference count is incremented when we copy a shared_ptr.
>* use to initialize another shared_ptr
>* use as the right-hand operand
>* pass it to return from a functions by value

The reference count is decremented when:
>* we assign a new value to the shared_ptr
>* destroyed

Once the shared_ptr's counter goes to zero, the shared_ptr automatically frees
the object that it manages.

### Purposes of Using Dynamic Memory
>* They don’t know how many objects they’ll need
>* They don’t know the precise type of the objects they need
>* They want to share data between several objects

## unique_ptr
```cpp
unique_ptr<T> u1     // Null unique_ptrs that can point to objects of type T. u1
unique_ptr<T, D> u2  // will use delete to free its pointer; u2 will use a
                     // callable object of type D to free its pointer.

 unique_ptr<T, D> u(d) // Null unique_ptr that point to objects of type T that
                       // uses d, which must be an object of type D in place of delete.

u = nullptr           // Deletes the object to which u points; makes u null.

u.release()           // Relinquishes control of the pointer u had held; returns the
                      // pointer u had held and makes u null.

u.reset()             // Deletes the object to which u points; If the built-in
u.reset(q)            // pointer q is supplied,makes u point to that object.
u.reset(nullptr)      // Otherwise makes u null.
```

## Some conventions for Using Smart Pointers
>* Don’t use the same built-in pointer value to initialize (or reset) more than one
smart pointer.
>* Don’t delete the pointer returned from get().
>* Don’t use get() to initialize or reset another smart pointer.
>* If you use a pointer returned by get(), remember that the pointer will become
invalid when the last corresponding smart pointer goes away.
>* If you use a smart pointer to manage a resource other than memory allocated by
new, remember to pass a deleter (§ 12.1.4, p. 468, and § 12.1.5, p. 471).

## Dangerous Examples
```cpp
// ptr is created and initialized when process is called
void process(shared_ptr<int> ptr) {
  // use ptr
} // ptr goes out of scope and is destroyed

int *x(new int(1024)); // dangerous: x is a plain pointer, not a smart pointer
process(x); // error: cannot convert int * to shared_ptr<int>
process(shared_ptr<int>(x)); // legal, but the memory will be deleted!
int j = *x; // undefined: x is a dangling pointer!
```

Don't bind the same built-in pointer to more than one smart pointer. You
shouldn't free the built-in pointer when you want to bind it to a smart pointer.
The function `get()` has the familiar danger.
```cpp
int *p = new int(4);
// the reference count of the object to which p3 and p4 point is 1
std::shared_ptr<int> p3 = std::shared_ptr<int>(p);
std::shared_ptr<int> p4 = std::shared_ptr<int>(p);
```
