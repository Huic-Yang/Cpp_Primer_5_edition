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

## [Exercise 12.2](StrBlob.h)
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
The object to which `r` pointed to previously is not freed.

```cpp
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```
The reference count of object to which `r2` pointed reduce to 0 and the memory
is freed safely.
