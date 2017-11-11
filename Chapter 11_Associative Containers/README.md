# Chapter 11

## Exercise 11.1
> Map is a Associactive Container and vector is a Sequential Container.
> A map is a collection of key-value pairs.
> Map uses the key as subscript and return the corresponding value.
> Vector uses the rank as subscript and return the element in that position.

## Exercise 11.2
`list`: Joseph Problem
`map`: phone number list

## [Exercise 11.3](ex_11_3.cpp)

## [Exercise 11.4](ex_11_4.cpp)

## Exercise 11.5
`std::set`s contains only the key while `std::map`s contain key associated with
 value.

`std::set`s were used mostly in those tasks saving elements once.

`std::map`s were used mostly in those tasks associating one thing to another
 thing.

## [Exercise 11.6](https://stackoverflow.com/questions/2302681/c-stl-list-vs-set)

## [Exercise 11.7](https://github.com/Mooophy/Cpp-Primer/blob/master/ch11/ex11_7.cpp)

[The same file](ex_11_7.cpp)

## [Exercise 11.8](ex_11_8.cpp)

## [Exercise 11.9](ex_11_9.cpp)

## [Exercise 11.10](ex_11_10.cpp)
Because `std::list<T>::iterator` has no operation `<`, it can't be the key of a
map. `std::vector<T>::iterator` can do that because it has `<` operation.

## Exercise 11.11
Pass.

## [Exercise 11.12](ex_11_12.cpp)

## [Exercise 11.13]
`std::pair<FirstType, SecondType> p(first, second);`
`std::pair<FirstType, SecondType> p = make_pair(first, second);`
`std::pair<FirstType, SecondType> p = {first, second};`
`return {first, second}`

## [Exercise 11.14](ex_11_14.cpp)

## Exercise 11.15
> What are the mapped_type, key_type, and value_type of a map
from int to vector<int>?

`mapped_type`: vector<int>

`key_type`: int

`value_type`: map<const int, vector<int> >

## Exercise 11.16
>Using a map iterator write an expression that assigns a value to an
element.

```Cpp
map<string, int> numbers = {{"one", 1}, {"two", 2}, {"three", 3}};
for (auto it = numbers.begin(); it != numbers.end(); ++it)
  it->second = 0;
```

## [Exercise 11.17](ex_11_17.cpp)
>Assuming c is a multiset of strings and v is a vector of
strings, explain the following calls. Indicate whether each call is legal:

```Cpp
copy(v.begin(), v.end(), inserter(c, c.end()));
copy(v.begin(), v.end(), back_inserter(c)); // set has no member `push_back`
copy(c.begin(), c.end(), inserter(v, v.end()));
copy(c.begin(), c.end(), back_inserter(v));
```
## [Exercise 11.18](ex_11_18.cpp)

## Exercise 11.19
Pass.

## Exercise 11.20
```cpp
map<string, size_t> words;
for (string word; cin >> word; ) {
  pair<map<string, size_t>::iterator, bool> res = words.insert(make_pair(word, 1));
  if (!res.second)
    ++res.first->second;
}
for (const auto &w: words)
  cout << w.first << ' ' << w.second << endl;
```

## Exercise 11.22
If the word is contained in the keys, insertion will not be excuted and the corresponding value will be increased. If the word is not contained in it,
insertion will be excuted and the value is zero. after the `++` operation, the
value will be 1.

## Exercise 11.22
`std::pair<std::string, std::vector<int> >`
`std::pair<std::map<std::string, std::vector<int> >::iterator, bool>`

## [Exercise 11.23](ex_11_23.cpp)

## Exercise 11.24
>What does the following program do?
```cpp  
  map<int, int> m;
  m[0] = 1;
```
>* m is searched for the element whose key is zeor, and the element is not found.
>* A new key-value pair is inserted into m. The key is a const int -- 0, and the
value is value initialized which is zero too.
>* The new inserted element is fetched and is given the value 1.

## Exercise 11.25
>Contrast the following program with the one in the previous exercise
```cpp
  vector<int> v;
  v[0] = 1;
```
It will be error because v is empth and we can't access element with the subscript-0.

## Exercise 11.26
subscipt: the key type. \\
return: `std::map<K, V>::maped_type` \\
example:
```cpp
  std::map<std::string, size_t> words;
  std::string str; std::cin >> str; // subscipt type: std::string;
  words[str] = 1; // return type: size_t
```
