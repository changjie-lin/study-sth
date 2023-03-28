# Chapter 13. Copy Control

## 13.1

A constructor is the copy constructor if its first parameter is a **reference** to the class type and any additional parameters have **default values**.

When copy initialization happens and that copy initialization requires either the copy constructor or the move constructor.

- Define variables using an `=`
- Pass an object as an argument to a parameter of non-reference type
- Return an object from a function that has a non-reference return type.
- Brace initialize the elements in an array or the members of an aggregate class.
- Some class types also use copy initialization for the objects they allocate.

## 13.2

The parameter of the copy constructor must be a reference, or the call would never succeed -- to call the copy constructor, we'd need to use the copy constructor to copy the argument, but to copy the argument, we'd need to call the copy constructor, and so on indefinitely.

## 13.3

When copying a `StrBlob`, the use `use_count` of the `shared_ptr` adds 1.

When copying a `StrBlobPtr`, the `use_count` of the `weak_ptr` does not change.

## 13.4

```cpp
Pointer global;
Point foobar(Point arg)  // 1
{
	Point local = arg, *heap = new Point(global); // 2, 3
	*heap = local;
	Point pa[ 4 ] = {local, *heap}; // 4, 5
	return *heap; // 6
}
```

## 13.6

> What is a copy-assignment operator?

A copy-assignment operator is the `=` operator for a class to control how its objects are assigned.

> When is this operator used?

It is used when an assignment to the class objects happens.

> What does the synthesized copy-assignment operator do?

It can disallow assignment for some classes. Otherwise, it assigns each nonstatic memember of the right-hand object to the corresponding member of the left-hand object using the copy-assignment operator for the type of that member.

> When is it synthesized?

The compiler synthesizes a copy-assignment operator if the class does not define its own.

## 13.7

In both cases, shallow copy happen. All the pointers point to the same address. The `use_count` behaves the same as 13.3.

## 13.9

> What is a destructor?

The destructor is a member function with the name of the class prefixed by a tilde. It has no return value and takes no parameters. 

The destrubtor operate inversely to the constructor. Destructor do whatever work is needed to free the resources used by an object and destroy the nonstatic data members of the object.

> What does the synthesized destructor do?

As with the copy constructro and copy-assignment operator, for some classes, the synthesized destructor is defined to disallow objects of the type from being destroyed. Otherwise, the synthesized destructor has an empty function body.

> When is a destructor synthesized?

The compiler defines a synthesized destructor for any class that does not define its own destructor.


## 13.10

The smart pointers are class types and have destructors. As a result, unlike ordinary pointers, members that are smart pointers are automatically destroyed during the destruction phase.

When a `StrBlob` is destroyed, the reference count of the shared pointer decreases by 1. If it reaches zero, the object it points to will be freed.

When a `StrBlobPtr` is destroyed, the weak pointer member gets destroyed. It has no impact on the object it points to.

## 13.12

3 times when destructing `accum`, `item1` and `item2`.

## 13.14

Three identical serial numbers.

## 13.15

Yes, the output will change. Because our defined copy constructro will generate a new seiral number for each copy.

## 13.16

Passing by reference will not call copy constructor. The results are the same as passing each object to f.

## 13.20

- copy

The data members (built-in type, class type, smart pointer and container) of the class is copied.

- Assign

The data members are copied. The reference count of left operand increased by 1, while the count of right operand decreased by 1.

- Destroy

The data members are destroyed. The smart pointers decrease reference count. If refcount went to zero, the objects they pointed to get destroyed.


## 13.21

No. The synthesized versions already meet all requirements.

## 13.24

If `HasPtr` didn't define a destructor, memory leak will happen.

If `HasPtr` didn't define the copy constructor, shallow copy occurs which is not we expect.

## 13.25

The copy constructor and the copy-assignment operator need to dynamically allocate a new vector for the underlying vector, rather than only to copy the shared pointer.

The smart pointers will manage the dynamically allocated memory. The synthesized destructor is enough.

## [13.26](StrBlob.h)

## 13.29

Because the two inside statements which call swap() are acutally calling:

- `swap(std::string*, std::string*)`
- `swap(int, int)`

The swaps are std::swap() calls, rather than HasPtr::swap().

## 13.32

No. Because all the data members of pointer-like version of HasPtr are built-in types (int, pointer) and they would be swapped efficently with std::swap().

## 13.33

Because these member functions will update the Folder argument.

## 13.35

The synthesized versions of the copy-control members simply copy the data member. They will not update the corresponding Folder objects.

## 13.38

The copy and swap is an elegant way when working with dynamically allocated memory. In the Message class, nothing is allocated dynamically. Thus using the idiom does not make sense.

In this case, swap() clears two Message objects' folders, then swap members and add themselves to each folder. But Message assignment operator just clear itself, copy the members and add itself to each folder. The `rhs` does not need to clear and copy the members.

## 13.41

Because the position that `first_free` pointed to is exactly where we want to append the first element. The postfix operator evaluate firstly then do the increment. That is what we want.

## 13.43

The lambda function version is better. Because it doesn't need to worry about the order  and out of range issue. It is safer.

## 13.45

> Distinguish between an rvalue reference and an lvalue reference?

Generally speaking, an lvalue expression refers to an object's identity where an rvalue expression refers to an object's value.

An **rvalue reference** is a reference that must be bounded to an rvalue. It may be bound only to an object that is about to be destroyed. Rvalues are ephemeral.

An **lvalue reference** (regular reference) is a reference that must be bound to an lvalue or **const to an rvalue**. It refers to an object's **identity**. Lvalue are persistent.

- lvalue: functions that return lvalue references, assignment, subscript, dereference and prefix increment/decrement operators, are all expressions that return lvalues.

- rvalue: functions that return a nonreference type, along with the arithmetic, relational, bitwise, postfix increment/decrement operators, all yield rvalues.


## 13.46

```cpp
int f();
vector<int> vi(100);
int&& r1 = f();
int& r2 = vi[0];
int &r3 = r1;
int&& r4 = vi[0] * f();
```

## 13.50

The question is about when the move constructor or move assignment operator is called.

## 13.51

Because the function `clone` returns a rvalue. The compiler knows that the returned object is about to be destroyed. So that when constructing a new object from the returned value or assigning the returned value to an object, it calls the move constructor the the `move_assignment` operator. Thus there is no copy make.

## 13.52

`hp = hp2`

hp2 is an lvalue; copy constructor used to copy hp2

1. the data memeber of hp2 are copied
2. data members of hp are deleted
3. assign the data members of hp2 to hp

`hp = std::move(hp2)`

1. `std::move()` return the rvalue reference to hp2
2. the data members of hp2 are moved

In the first assignment, the right-hand operand is an lvalue, so the move constructor is not viable. The copy constructor will be used to initialize rhs. The copy constructor will allocate a new string and copy the string to which hp2 points.

In the second assignment, we invoke std::move to bind an rvalue reference  to hp2. In this case, both the copy constructor and the move constructor are viable. However, because the argument is an rvalue reference, it is an exact mathc for the move constructor. The move constructor copies the pointer from hp2. It does not allocate any memory.


## 13.54

```sh
error: ambiguous overload for 'operator=' (operand types are 'HasPtr' and 'std::remove_reference<HasPtr&>::type {aka HasPtr}')
```

## 13.56

It recursively calls the lvalue version sort and stack overflows at last.

Because the local variable "ret" is an "lvalue". When calling `ret.sorted()`, it acutally calls the lvalue version.


## 13.57

It calls the rvalue version inside. Thus it run successfully.




