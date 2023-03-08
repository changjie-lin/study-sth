# Chapter 9. Sequential Containers

## 9.1

- a) List. Since inserting items in the middle would be the frequent operation.

- b) deque. The container needs to support insert/delete in the front and back effeciently.

- c) vector. The most versatile sequential containers which supports random access efficiently.

## 9.3

"begin" and "end" forms the iterator range. The constraints:

- They refer to elements of the same container.
- "end" must not precede "begin".

## 9.6

The iterator of "list" does not support iterator arithmetic, including the ">" "<" comparisons.

```cpp

while(iter1 != iter2)
```

## 9.7

`vector<int> size_type`

## 9.8

```
// read
list<string>::iterator || list<string>::const_iterator

// write
list<string>::iterator
```

## 9.9

`cbegin` returns the **const_iterator** type
`begin` returns the **iterator** type


## 9.10

it1 and it2 have different types. Thus they need to be separated into two statements.

it1 is of type `vector<int>::iterator`

it2, it3, it4  are all of type `vector<int>::const_iterator`

## 9.11

```
vector<int> v1{0, 1, 2, 3};

vector<int> v2(4); // {0, 0, 0, 0}

vector<int> v3 = v1;

vector<int> v4(v1);

vector<int> v5(4, -1);

vector<int> v6(v1.begin(), v1.end());
```

## 9.12

To create a container as a copy of another container, the container and element types must match. When we pass iterators, there is no requirement that the container types be identical. Moreover, the element types in the new an original contianers can differ as long as it is possible to convert the elements we're copying to the element type of the container we are initializing.

## 9.17

1. They must have the same container type and element type.
2. The "<" operator must have been defined for the element type. 


## 9.21

Same effect, different cost. Vector has higher cost, since all elements will be moved rightwards for each insertion.

## 9.23

Same value that equal to the only element.

## 9.29 

`vec.resize(100)` will add 75 value initialized elements to the back of the vector.

`vec.resize(10)` will erase 90 elements from the back of the vector.

## 9.30

If the container holds elements of a class type and "resize" adds elements, we must supply an initializer or the element type must have a default constructor.

## 9.32

Not legal. Becase "the order of evaluation of arguments is unspecified." 

## 9.35

The "capacity" of a vector is how many elements the vector **can hold**.

The "size" of a vector is how many element the vector **already hold**.

## 9.36

No, it cannot.

## 9.37

"list" does store elements separately, rather than contiguously, in memory. Thus no need to preallocate memory. So "capacity" member is not needed.

"array" has a fixed size. It is not allowed to add new items.

## 9.39

Reserve space for 1024 elments at first. Read words from standard input. If there are more than 1024 words, the vector's capacity will grow automatically.

The resize() will add another "svec.size()/2" space.

## 9.40

256 / 1024
512 / 1024
1000 / 2048
1048 / 2048

## 9.42

Use `str.reserve(120)` to preallocate teh space.

## 9.48

string::npos



