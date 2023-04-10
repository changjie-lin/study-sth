# Chapter 15. Object-Oriented Programming

## 15.1

> What is a virtual member?

A Virtual memberis a function that the base class expects its derived classes to override. When we call a virtual function through a pointer or reference, the call will be dynamically bound. Depending on the type of the object to which the reference or pointer is bound, the version in the base class or in one of its derived classes will be executed.

## 15.2

> How does the _protected_ access specifier differ from private?

Differ by access scope:

- `private`: base class itself and friends can access
- `protected`: base class itself, friends and derived classes can access

## 15.3

[code](ex15_03_Quote.cpp)

## 15.4

- (a) Incorrect. It cannot derive a class from itself.
- (b) correct.
- (c) Incorrect. A derived class is declared like any other class. The declaration contains the class name but does not include its derivation list.

## 15.5

[code](ex15_03_Quote.cpp)

## 15.6

[code](ex15_03_Quote.cpp)

## 15.8

> Define static type and dynamic type.

- Static type: it is the ytpe with which a variable is declared or that an expression yields. The static type of an expression is always known at compile time.

- Dynamic type is the type of the object in memory that the variable or expression represents. The dynamic type may not be known until run time.

## 15.9

> When is it possible for an expressin's static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.

A pointer or reference to a base class can refer to a derived class object. But we can only access base class members with that pointer or reference.

In those cases the static type is the base class, while the dynamic type is the derived class.

```cpp
	class Base { /* ... */ };
    	class Derived : public Base { /* ... */ };

	Derived d;
	Base *bp = &d;
	Base &br = d;
	Derived *dp = &d;
	Base *bp2 = dp;
```

`bp2`, `bp` and `br` have different static type and dynamic type.

## 15.10

The `ifstream` class is inherited from `istream`, which means `ifstream` **is a** `istream`. 

The parameter of read() is a reference to base type `istream`, the automatic derive-to-base conversion applies when we pass a derived type `ifstream` to that function. Inside read(), we can access the `istream` subpart of the `ifstream` object through the reference.

## 15.12

Yes. It means to override the corresponding virtual function in its direct base and to preclude its derived class from overriding this virtual function at the same time.

## 15.13

The `derived::print()` intends to call the print() in base class. But the scope specifier was ommited, resulting in an infinite recursion.


Fix:

```cpp
void print(ostream &os) { base::print(os); os << " " << i; }
```

## 15.14

```cpp
(a) bobj.print();	// base::print()
(b) dobj.print();	// derived::print()
(c) bp1->name();	// base::name()
(d) bp2->name();	// base::name()
(e) br1.print();	// base::print()
(f) br2.print();	// derived::print()


```

## 15.16

[code](ex15_15_Quote.cpp)


## 15.24

Virtual destructors are useful when you might potentially delete an instance of a derived class through a pointer to base class.

## 15.25

Error message:
```sh
ex15_25.cpp:51:9: note: ‘Bulk_quote::Bulk_quote()’ is implicitly deleted because the default definition would be ill-formed:
   51 |         Bulk_quote() = default;
      |         ^~~~~~~~~~
```

Because we have defined a constructor which takes four parameters, which prevents the compiler from generating a synthesized default constructor. As a result, the default constructor of any derived class would be defined as deleted. 

## 15.29

[code](ex15_29_Quote.cpp)

The net prices are different.

Because derived objects are "sliced down" when assigned to a base-type object.

## 15.31

Each operator creates a Query objects that is bound to its corresponding class (derived from base class) and Query generates a WordQuery object. (p. 638)

Operator precedence follows the built-in operator precedence. (p.635)

(a) `Query(s1) | Query(s2) & ~ Query(s3);`

Query --> OrQuery --+--> WordQuery(s1)
                    |
		    +--> AndQuery-------+--> WordQuery(s2)
		                        |
					+--> NotQuery -----> WordQuery(s3)

This expression creates 1 OrQuery object, 1 AndQuery object, 1 NotQuery object and 3 WordQuery objects.

(b) `Query(s1) | (Query(s2) & ~ Query(s3));`

Query --> OrQuery ----+--> WordQuery(s1)
                      |
		      +--> AndQuery -----+--> WordQuery(s2)
		                         |
					 +--> NotQuery -----> NotQuery --> WordQuery(s3)

This expression creates 1 OrQuery, 1 AndQuery, 1 NotQuery and 3 WordQuery objects.

(c) `(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)) )`

equals to 

`Query(s1) & Query(s2) | ( Query(s3) & Query(s4) )`

Query --> AndQuery ---+--> OrQuery  --> WordQuery(s1), WordQuery(s2)
                      |
		      +---> AndQuery --> WordQuery(s3), WordQuery(s4)

It creates 4 WordQueries, 2 AndQuery, and 1 OrQuery objects.

## 15.32

- Copy: the smart pointer object is copied. Both the new and the old pointers point to the same object. The reference count increases by 1.

- Move: the smart pointer is moved. The new pointer points to the object and the old one is destroyed. The reference count remains the same.

- Assign: the smart pointer transfers the ownership from the right-hand side to the left-hand side. The reference count of the rhs decreases, while the lhs increases.

- Destroy: the smart pointer is destroyed. The referece count decreases. If it reaches zero, the object is destroyed.

## 15.33

The `Query_base` class is an abstract base class without data members. It provides the common interface to its derived classes. We cannot create objects from it directly, let alone copying, moving, assigning or destroying its objects.

## 15.34

> Query q = Query("fiery") & Query("bird") | Query("Wind");

(a) List the constructors executed in processing that expression.

```
WordQuery(cosnt std::string &) * 2
	| 	// WordQuery("fiery"), WordQuery("bird")
Qurey(const std::string &) * 2
	|
Query(const Query &) or Query(Query &&) * 2 // synthesized version
	|
BinaryQuery(const Query &, const Query &, std::string)
	|
AndQuery(const Query &, const Query &)
	|
Query(std::shared_ptr<Query_base>)	WordQuery(const std::string &)
	|					|  // WordQuery("Wind")
	|					|
	|				Query(const std::string &s)
	|					|
	+---------------------------------------+
	|
	Query(const Query &) or Query(Query &&) * 2
		|
	BinaryQuery(const Query &, const Query &, std::string)
		|
		OrQuery(const Query &, const Query &)
			|
			Query(std::shared_ptr<Query_base>)

```

(b) List the calls to `rep` that are made from `cout << q`

Query::rep	/* q.rep() */
	|
BinaryQuery::rep	/* q->rep() */ /* inherited by OrQuery */
	|
	+------------------------------------+
	Query::rep /* lhs.rep() */	     Query::rep	/* rhs.rep() */
	|					|
	|				WordQuery::rep /* q->rep() */ /* wind */
	|
	BinaryQuery::rep /* q->rep() */ /* inherited by AndQuery */
	|
	+-------------------------------------+
	|				      |
	Query::rep /* lhs.rep() */	     Query::rep /* rhs.rep() */
	|					|
	WordQuery::rep				WordQuery::rep
	/* q->rep() */				/* q->rep() */
	// fiery				/* bird */

(c) List the calls to `eval` made from `q.eval()`

Query::eval	/* q.eval() */
	|
	OrQuery::eval	/* q->eval() */
	|
	+------------------------------------------+
	Query::eval /* lhs.eval() */		Query::eval  /* rhs.eval() */
	|					   |
	AndQuery::eval /* q->eval() */		WordQuery::eval()  /* q->eval() */
	|
	|
	+------------------------------------------+
	|					   |	
	Query::eval /* lhs.eval() */		Query::eval  /* rhs.eval() */
	|					   |
	WordQuery::eval()  /* q->eval() */	 WordQuery::eval()  /* q->eval() */


## 15.37

> What changes would your classes need if the derived classes had members of type `shared_ptr<Query_base>` rather than of type Query?

- (1) The constructors of AndQuery, OrQuery and NotQuery must change the types of their parameters from Query to `shared_ptr<Query_base>`

- (2) The parameters and the return type of the overloaded operators, except <<, must change

- (3) The calls to rep() and eval() must use "->" operator in place of "." operator

- (4) As a result of (3), the virtual function rep() in `Query_base` must be public, otherwise it will not be accessible through dereferencing the smart pointers within the derived classes.

- (5) Same effects on eval() in `Query_base`

- (6) Query class must define a conversion operator (wiht a public access specifier) from Query to `shared_ptr<Query_base>`

- (7) Query's constructor that takes a `shared_ptr` (and the conversion operator) must be pulic in order to be accessible to users. For the same reason of (4).


[code](ex15_37.cpp)


## 15.38

All of them are illegal. BinaryQuery is an Abstract Class. We cannot create object of it. AndQuery and OrQuery do not have public constructors, nor a conversion operator from Query to AndQuery or OrQuery.

## 15.40

> In the OrQuery eval function what would happen if its rhs
member returned an empty set? What if its lhs member did so? What if both rhs
and lhs returned empty sets?

If rhs member returned an empty set:

The right.begin() and right.end() would return the equal iterator, denoting a range of zero. The `lines_insert` operation would have no effect.

If lhs member returned an empty set:

`ret_lines` would be initialized to an empty set by `make_shared`. Since a set can grow dynamically, the operation that follows (`ret_lines->inserts`) would still be safe.

If both members returned an empty set:

Two empty sets merged into an empty set.







