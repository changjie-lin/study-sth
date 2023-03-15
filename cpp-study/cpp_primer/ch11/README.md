# Chapter 11. Associative Containers

## 11.1

A _map_ is a collection of key-value pairs, i.e. associative container. We can get a value **lookup by key** efficiently.

A _vector_ is a sequential container. Every element has an **index**, which is always an unsigned size type.

## 11.2

list: linked-list
vector: most scenarios to use a seqential container
deque: queue
map: dictionary
set: stores a collection of the unique data when initialization

## 11.5

A _map_ is a collection of key-value pairs. When we want a container acting like a dictionary, we should choose _map_.

A _set_ is a collection of keys. When we need to check if some values are present, we can choose _set_.

## 11.6

A _set_ is an associative container while a _list_ is a sequential one. The elements in a typical _set_ are unique and ordered while element in a _list_ are not. When we expect to quickly access unique, ordered elements, use set.


## 11.15

- `mapped_type` : `vector<int>`
- `key_type` : `int`
- `value_type` : `std::pair<const int, vector<int>>`

## 11.18

`std::map<std::string, size_t>::const_iterator`

## 11.21

If the word is in the map, the insertion does not happen and the origina count gets increased by 1.

If the word is not in, the word with count 0 gets inserted. Then the count increases 1.

## 11.22

```cpp
// argument
std::pair<std::string, std::vector<int>>

// return
std::pair<std::map<std::string, std::vector<int>>::iterator, bool>

```

## 11.27

I would use count to deal with multimap or multiset, since the elements can be repetive.

The find will be applied if I only want to know whether an element presents.

## 11.29

`lower_bound` and `upper_bound` return the iterator that refers to the first point at which this key can be inserted  while preserving the element order within the container.

`equal_range` returns a pair of iteratros that are both c.end().


## 11.30

`cout << pos.first->second << ednl;`

pos			a pair of iterators
pos.first		the iterator refering to the first element with the matching key
`pos.first->second`	the value part of the key-value pair of the element


## 11.34

When we use subscript operator instead of `find`, it will malfunction for the words that are not in the map.

If a word is not in the map, the subscript operator will insert it into the map and then value initialized the corresponding value to empty string. We finally got a empty string returned for all words that are not in the map.

## 11.35

- with subscript operator: if a keyword appears multiple times, the buildMap will finally put the **last** transformation value into the map.

- with `insert`: if a keyword appears multiple times, the buildMap will keep the **first** transformation value into the map.

## 11.36

Since the `value.size() > 1` is false in this situation, buildMap throws the `runtime_error`.

## 11.37

Luse an unordered container if the key type is inherently unordered or if performance testing reveals problems that hashing might solve.

Advantages:

- unordered: hashing gives better average case performance in principle.

- ordered: fulfil most of the scenarios, easy to use (no need to compose an effective hashing function).


## 11.38

Since the library supplies versions of the hash template for the built-in types, including pointers. We can directly defined unordered container whose key is one of the built-in types.




