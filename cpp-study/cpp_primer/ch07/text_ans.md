## 7.10

The condition reads data1 and data2 consecutively and checks the reading is successful or not.

## 7.14

```
Sales_data() : units_sold(0), revenue(0.0) { }
```

## 7.16

There is not restriction on where and how often an access specifier may appear inside a class definition. A class may contain zero or more access specifiers. Any kind of access specifiers can appears multiple times. And there is no constraint on sequences as well.

The constructors and member functions that are part of the interface should be defined after a "public" specifier.

The data members and member functions that are part of the implementation should be defined after a "private" specifier.

## 7.17

The only difference between struct and class is the default access level.

The memebers defined before the first access specifier are "public" in struct, while those are "private" in class.

## 7.18

Encapsulation enforces the separation between interface and implementation in a class via access specifiers.

Encapsulation provides some advantages:

- user code cannot inadvertently corrupt the state of an encapsulated object.

- The implementation of an encapsulated class can change over time without requiring changes in user-level code.

## 7.19

- Constructors which are part of the interface should be public
- member methods (getName(), getAddress()) which are part of interface are public
- data memebers which are part of the implementation should be private


## 7.20

A class can allow another calss or function to access its nonpublic members by making that class or function a **friend**.

Pros:
- It provides a flexible mechanism.

Cons:
- It is kind of a harm to encapsulations and maintainence.


## 7.25

Yes. `Screen` can safely rely on the default versions of copy and assignment, refering to *Section 7.1.5*:

> ...the synthesized versions are unlikely to work correctly for classes that allocate resources that reside outside the class objects themselves.
>
> Moreover, the synthesized versions for copy, assignment, and destruction work correctly for classes that have **vector or string members**.

## 7.28
These methods would return a new Screen object with the changes. The original Screen remains unchangd.

## 7.30
Python does it this way. According to the Zen of Python: "Explict is better than implicit".

Pro:
- explicit usage is more clear to read.
- The member functions can use the same name as data members as the function parameters

Con:
- More typing
- redundant

## 7.33

The return type `pos` is a member `typedef` of class Screen. So it needs class scope prefix as `Screen::pos`.

## 7.34

Error: unknown type name

## 7.37

> A constructor that supplies default arguments for all its parameters also define the default constructor.

```
Sales_data first_item(cin);  // Sales_data(std::istream &is);
    int main() {
      Sales_data next;  // Sales_data(std::string s = "");
      Sales_data last("9-999-99999-9");  // Sales_data(std::string s = "");
    }
```

## 7.38

```
Sales_data(std::istream &is = std::cin) { read(is, *this); } 
```

## 7.39

illegal. cause the call of overloaded `Sales_data()` is ambiguous.

## 7.40

```
using std::string;

class Tree {
public:
	Tree(string i = "00000") : ID(i) { }  // default constructor
	Tree(string i, string s, string d) : ID(i), species(s), plant_date(d) { }
	Tree(std::istream &is);
private:
	string ID, species, plant_date;
};
```

## 7.42

```
using std::string;

class Tree {
public:
        Tree(string i, string s, string d) : ID(i), species(s), plant_date(d) { }
        Tree(string i = "00000") : Tree(i, "", "") { } 
        Tree(std::istream &is);
private:
        string ID, species, plant_date;
};
```

## 7.46
a) Untrue. If programmers do not provide any constructor, the compiler will generate one which is called "synthesized default constructor".

b) Untrue. A constructor which provides default values to all its parameters also defines a default constructor.

c) Untrue. In practice, it is almost always right to provide a default constructor if other constructors are being defined. In this regard, it is also OK to provide.

d) Untrue. Only when a class does not define **any constructors**, the compiler will generate teh synthesized default constructor.

## 7.47
It should be "explicit". Otherwise, users could write such code `item.combine("1123-342")` which harms the readability.

Benefits:
- prevent the use of a constructor in a context that requires an implicit conversion
- we can define a constructor which is used only with the direct form of initialization

Drawbacks:
- more typing

## 7.48

Behaves the same.

## 7.49

a) OK. It firstly converts "s" to a `Sales_data` object, then copies that temporary.

b) Erorr. It firstly converts "s" to a `Sales_data` object, then pass the reference to that temporary into the parameter of "combine()". But passing a reference to a temporary object causes error.

c) OK. Because _combine_'s parameter is a reference to _const_, we can pass a temporary to that parameter.

## 7.51

Semantically speaking, a number is different from a vector, while a char array is the same as a string.

## 7.54

No. Bcause a constexpr function must contain exactly one return statement.

## 7.55

No. Because `std::string` is not a literal type.

## 7.56

A _static_ class memeber is a member that is associated with the class, rather than with the individual objects of the class.

Advantages (differences regarding ordinary members):

- Objects no need to store the common data
- If a _static_ memeber changes, each object of the class will use the new value.
- A _static_ data member can have the incomplete type.
- A _static_ member (either a data member or a member function) can be used as a default argument.
