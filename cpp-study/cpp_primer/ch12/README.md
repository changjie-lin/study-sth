# Chapter 12. Dynamic Memory

## 12.1

At the end of this code, b2 is destroyed. But the elements that the shared pointer points to still exist. The size of the elements are 4.

## 12.3

No. There is not logical reason to do this.

> You can certainly do this if you want to, but there doesn't seem to be any logical reason. The compiler doesn't complain because this doesn't modify data (which is a pointer) but rather the thing data points to, which is perfectly legal to do with a  const pointer.

Discussion over this exercise on [Stack Overflow](http://stackoverflow.com/questions/20725190/operating-on-dynamic-memory-is-it-meaningful-to-overload-a-const-memeber-functi)

## 12.4

The type of "i" is `std::vector<std::string>::size_type` which is an unsigned number. It ensures the value never will be negative.


## 12.5

If we add `explicit` keyword to the constructor that thaes an `initializer_list`, we must explicitly pass an `initializer_list` to the constructor.

The current design saves typing. It is easy to use and understand. 

But the user of the class must know the implementation of this constructor. 


## 12.8

The return type should be `int *`. The return value converts to a bool. The dynamical allocated memory has no chance to be freed. Thus memory leaks.


## 12.9

After `r = q`, memory leaks. Because no pointer points to the object that `r` previously allocated.

After `r2=q2`, the original object that r2 refers to gets destroyed. Both variables points to the same int whose value is 42.


## 12.18

Because other `share_ptr` that points the same object can still delete this object. Thus it's meaningless with this memember.

## 12.21

I prefer the original version since it is easier to understand and debug.

## 12.31

The `vector` will contain duplicate elements. I think `set` is better for the scenario.




