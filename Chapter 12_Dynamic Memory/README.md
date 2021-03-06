## Exercise 12.1
> How many elements do b1 and b2 have at the end of this code?

```cpp
StrBlob b1;
{
StrBlob b2 = {"a", "an", "the"};
b1 = b2;
b2.push_back("about");
}
```
`b1` has four elements

`b2` was destroyed

## [Exercise 12.2](str_blob.h)
> Write your own version of the StrBlob class including the const ver-
sions of front and back.

## Exercise 12.3
>Does this class need const versions of push_back and pop_back? If
so, add them. If not, why aren’t they needed?

See [stack overflow](https://stackoverflow.com/questions/20725190/operating-on-dynamic-memory-is-it-meaningful-to-overload-a-const-memeber-functi)

## Exercise 12.4
> In our check function we didn’t check whether i was greater than
zero. Why is it okay to omit that check?

Because `std::vector<std::string>::size_type` is an unsigned type,  `i` will
convert to a number greater than 0 when it passed into the `check` function.

## Exercise 12.5
>We did not make the constructor that takes an initializer_list
explicit (§ 7.5.4, p. 296). Discuss the pros and cons of this design choice.

In some cases, we can write the code easier by using the automatic conversion
but sometimes it would make some unexpected troubles.

## [Exercise 12.6](ex_12_6.cpp)
>Write a function that returns a dynamically allocated vector of ints.
Pass that vector to another function that reads the standard input to give values to
the elements. Pass the vector to another function to print the values that were read.
Remember to delete the vector at the appropriate time.

## [Exercise 12.7](ex_12.7.cpp)
> Redo the previous exercise, this time using shared_ptr.

## [Exercise 12.8](ex_12_8.cpp)
> Explain what if anything is wrong with the following function.

```cpp
bool b() {
  int * p = new int;
  // . . .
  return p;
}
```
It will return true because p is not a nullptr.

## [Exercise 12.9](ex_12_9.cpp)
>Explain what happens in the following code:

```cpp
int *q = new int(42), *r = new int(100);
r = q;
```
The object to which `r` pointed previously is not freed.

```cpp
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```
The reference count of object to which `r2` pointed reduce to 0 and the memory
is freed safely.

## Exercise 12.10
>Explain whether the following call to the [process](Notes.md) function defined
on page 464 is correct. If not, how would you correct the call?

correct.
```cpp
shared_ptr<int> p(new int(42)); // reference count: 1
process(shared_ptr<int>(p)); // in the process function reference count is 2
                             // after the function reference count is 1
                             // which means the object is not freed in this function.
```

## Exercise 12.11
>What would happen if we called process as follows?

```cpp
process(shared_ptr<int>(p.get()));
```
`p.get()`: return a built-in pointer to the object to which p points.

`shared_ptr<int>(p.get())`: return a shared_ptr of the object which has its own
reference count(1);

`process(...)`: after this function, the object is freed, and p becomes a
dangling pointer. It is dangerous to use p.

After this scope exits, the smart_ptr p will free the memory having already
been freed in the process, so it is dangerous.

## Exercise 12.12
>Using the declarations of p and sp explain each of the following calls
to process. If the call is legal, explain what it does. If the call is illegal, explain why:

```cpp
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```
`(a)`: legal. When sp is passed to process as a parameter, it is copied and its
reference count is incremented. It wounld not be freed in the process function.
So it can work.

`(b)`: illeagl. Because a plain pointer can not convert to a smart_ptr
automatically. A error will be raised.

`(c)`: illeagal. This one is the same as above.

`(d)`: It can work but it may be dangerous if we free p outside the process
function. The memory to which p points is freed in the process. We shouldn't
free it again outside the process.

## Exercise 12.13
>What happens if we execute the following code?

```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```
When we call `sp.get()`, we get a built-in pointer pointing to the same memory
to which sp points. After this scope, the smart_ptr sp will free the memory
having already been freed after `delete p` called and this is undefined.

## Exercise 12.14
> Write your own versionof a function that uses a shared_ptrto man-
age a connection.

Pass.

## Exercise 12.15
> Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388) in place of
the end_connection function.

Pass.

## [Exercise 12.16](ex_12_16.cpp)
> Compilers don’t always give easy-to-understand error messages if we
attempt to copy or assign a unique_ptr. Write a program that contains these errors
to see how your compiler diagnoses them.

## [Exercise 12.17](ex_12_17.cpp)
> Which of the following unique_ptr declarations are illegal or likely
to result in subsequent program error? Explain what the problem is with each one.

```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;

(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048));
(f) IntP p5(p2.get());
```
## Exercise 12.18
> Why doesn’t shared_ptr have a release member?

Because one object can be held by more than one shared_ptr while only one
unique_ptr. It is not necessary to provide the member.

## [Exercise 12.19](str_blob.h)
> Define your own version of StrBlobPtr and update your StrBlob
class with the appropriate friend declaration and begin and end members.

## [Exercise 12.20](ex_12_21.cpp)

## Exercise 12.21
>  We could have written StrBlobPtr’s deref member as follows:

```cpp
std::string& deref() const
{ return ( * check(curr, "dereference past end"))[curr]; }
```
>Which version do you think is better and why?

The previous one is more readable so it is better.

## [Exercise 12.22](ex_12_22.CPP)
> Write a program to concatenate two string literals, putting the result
in a dynamically allocated array of char. Write a program to concatenate two library
strings that have the same value as the literals used in the first program.

## [Exercise 12.23](ex_12_23.cpp)
> Write a program that reads a string from the standard input into a
dynamically allocated character array. Describe how your program handles varying
size inputs. Test your program by giving it a string of data that is longer than the array size you’ve allocated.

## [Exercise 12.24](ex_12_24.cpp)
>  Given the following new expression, how would you delete pa?

```CPP
int *pa = new int[10];
```

```CPP
delete [] pa;
```

## [Exercise 12.26](ex_12_26.cpp)
> Rewrite the program on page 481 using an allocator.

## [Exercise 12.27](ex_12_27.cpp)
>  The TextQuery and QueryResult classes use only capabilities that
we have already covered. Without looking ahead, write your own versions of these
classes.

## [Exercise 12.28](ex_12_28.cpp)
> Write a program to implement text queries without defining classes to
manage the data. Your program should take a file and interact with a user to query for words in that file. Use vector, map, and set containers to hold the data for the file and to generate the results for the queries.

## [Exercise 12.29](ex_12_29.coo)
>  We could have written the loop to manage the interaction with the
user as a do while (§ 5.4.4, p. 189) loop. Rewrite the loop to use a do while. Explain which version you prefer and why.
