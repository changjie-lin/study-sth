## 6.31
When is it valid to return a reference?
When the reference is refering a preexisting object.

A reference to const?
The const is a preexisting object. And the returned object is no longer Lvalue.

## 6.36

string (&func())[10]

## 6.37

// 1. type alias
typedef string arrT[10];
// using arrT = string[10];

arrT &func();

// 2. trailing return
auto func() -> string (&)[10];


// 3. decltype
string str[10];
decltype(str) &func();


// I prefer the trailing return format, which is so similar to the return format of Python type hint. It is clear to identify the return parameters.


## 6.39

(a)

    int calc(int, int);
    int calc(const int, const int);  // Same with first line, top-level `const` are ignored

(b)

    int get();
    double get();  // Error, differ only on return types

(c)

    int *reset(int *);
    double *reset(double *);  // OK, define an overloaded function


## 6.46

No, a `constexpr` function may only contains statements that generate no actions at run time, but the member method `size()` must be called at run time, thus the function can not be a `constexpr` function.

<!---
A function like below can be `constexpr` function:

    constexpr bool isSameStr(const std::string &s1, const std::string &s2) {
      return &s1 == &s2;
    }

--->
