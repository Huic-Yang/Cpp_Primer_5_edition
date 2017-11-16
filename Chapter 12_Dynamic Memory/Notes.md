## Memory
`static memory`: local static objects, class static data members, and for
variables defined outside any functions. It is created when they are used and
destroyed when the program ends by the compiler.

`stack memory`: used for nonstatic objects defined inside functions. They are
created and destroyed by compiler when the block in which they are defined is
entered and exited.

`heap`: for objects that they dynamically allocate.

## Problem for Free Memory
`memory leak`: forget to free the memory.

`point to the freed memory`: free the memory when there are still memory
pointers referring to that memory (no longer valid).

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
