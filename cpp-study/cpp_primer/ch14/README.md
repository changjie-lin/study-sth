# Chapter 14. Overloaded Operations and Conversions

## 14.1

> In what ways does an overloaded operator differ from a built-in operator? In what ways are overloaded operators the same as the built-in operators?

Differ:

- We can also call an overloaded operator function directly in the same way we call an ordinary function.

- A few operators guarantee the order in which operands are evaluated. These guarantees do not apply to overloaded operators. They do not perserve order of evaluation and / or short-circuit evaluation.
> In particular, the operand-evaluation guarantees the logical `AND`, logical `OR`, and comma operators are not preserved. Moreover, overloaded versions of `&&` or `||` operators do not preserve short-circuit evaluation properties of the built-in operators. Both operands are always evaluated.

Same:

- Overloaed operators have the same precedence and associativity as the corresponding built-in operators.

- The definitions are usually consistent with the built-in meaning.

## 14.3

(a) Both operands are of type `const char *`. Thus it is the built-in operator.

(b) string

(c) vector

(d) string


## 14.4

(a) Nonmember. Symmetric operator.

(b) Member. Compound-assignment operator.

(c) Member. Operators that change the state of their object or that are closely tied to their given type - such as increment, decrement, and dereference - usually should be members.

(d) Member. Member access arrow.

(e) Nonmember. IO operators must be nonmember functions.

(f) Nonmember. Symmetric.

(g) Nonmember. Symmetric.

(h) Member. Function call.

## 14.6

see [14.2](##14.2)

## 14.8

See [14.5](##14.5)

## 14.9

see [14.2](##14.2)

## 14.10

(a) correct format
(b) illegal foramt. `units_sold` will be 24 which is converted from 24.95.

## 14.11

If an IO error occurs, the operator does not rest its given object to a consistent state.

(a) read correctly
(b) the state of the object would be inconsistent


## 14.12

See [14.5](##14.5)

## 14.13

No others.

## 14.14

Discussing on [SO](http://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the).

## 14.15

No. For Tree, there is no more logical mapping in built-in arithmetic operators.

## 14.17

Yes. See [14.5](##14.5)

## 14.19

No. There is no single logical definition of <. Thus, it is better for this class not to define < at all. 

## 14.20

See [14.2](##14.2)

## 14.21

```cpp
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	Sales_datq old_data = *this;
	*this = old_data + rhs;
	return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum;
	sum.units_sold = lhs.units_sold + rhs.units_sold;
	sum.revenue = lhs.revenue + rhs.revenue;
	return sum;
}

```

Disadvantages: Both operators use an temporary object.

## 14.24

Not needed. The synthesized ones are enough.

## 14.29

Because increment and decrement operators change the state of the object.

## 14.31

There is not dynamically allocated memory, so the synthesized destructor is enough. All data members can be copied, assigned, destroyed by the synthesized ones.

## 14.33

An overloaded function-call can take as many number of operands as the a function call. The maximum value is 256.

## 14.41

Lambdas are handy to use when you intend to use the function once. It is short and anonymous.  

When the function is fairly complicated and would be used more than once, the function-object class would be better than lambda.

## 14.46

It is a bad idea. Since it is misleading. If have to, it should be "explicit" to prevent implicit conversion.

## 14.47

```cpp
struct Integral {
	operator const int(); // meaningless. The "const" will be ignored by compiler.
	operator int() const; // promise that the conversion will not change the sate of the ojbect.

}
```

## 14.47

No, it should not have conversion to bool. There is not such logical meaning.

## 14.50

- error. Ambiguous. double or float?
- float. Exact match.


## 14.51

The selected viable function is `void calc(int)`. Because the class-type convdersion ranks lowest.

Ranking order:

1. exact match
2. const conversion
3. promotion
4. arithmetic or pointer conversion
5. class-type conversion


## 14.52

Candidate functions

1. built-in operator+
2. LongDouble::operator+(const SmallInt&)
3. operator+(LongDouble&, double)
4. operator+(const SmallInt&, const SmallInt&)

For `ld = si + ld;`

Viable function: built-in operator. There is no best mathch. The following two are equally good.

- built-in operator+(int, double)
- build-in operator+(int, float)

For `ld = ld + si`

The exact match - LongDouble::operator+(const SmallInt&)


## 14.53

Error. Below functions are equally match:

- SmallInt::operator+(const SmallInt&, const SmallInt&)
- built-in operator+(int, double)

Fix:

`double d = s1 + SmallInt(3.14);`


