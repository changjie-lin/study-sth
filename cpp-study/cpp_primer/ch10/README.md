## 10.8

Because the `back_inserter` is an **insert iterator**. The iterator adapter generates an iterator that **uses a container operation** to add elements to a given contianer.

The algorithms do not change the container size. The iterator changes it via container operations.

## 10.10

Because the library algorithms operate on **iterators**. Thus, the algorithms **can not (directly)** add or remove elements.


## 10.23

The `bind` takes N+1 number of arguments. N is the number of arguments of the original callable. The additional one is the original callable itself.

## 10.26

`back_inserter` creates an iterator that uses `push_back`.

`front_inserter` creates an iterator that uses `push_front`.

`inserter` creates an iterator that uses `insert`.


## 10.38

Iterator Category	| Supported Operations
------------------------|----------------------
input iterator		| `==`, `!=`, `++`, `*`(dereference, only on rhs), `->`, single-pass

output iterator		| `++`, `*` (dereferce, only on lhs), single-pass

forward iterator	| all operation of input and output iterators, multi-pass

bidirectional iterator	| operations of forward iterator, `--`

random-access iterator	| all operations of bidirectional operations, `<`, `<=`, `>`, `>=`, `+`, `+=`, `-`(distance between two iterators), `-=`, `[]`


Iterator Category Hierachy

		input / output iterator
			|
		forward iterator
			|
		bidirectional iterator
			|
		random-access iterator


## 10.39

list: bidirectional iterator
vector: random-access iterator

## 10.40

`copy()`: The first two requires to be input iterator, the third should be output one.
`reverse()`: bidirectional iterator.
`unique()`: forward iterator

## 10.41

	replace(beg, end, old_val, new_val)

Replace elements whose value is equal to `old_val` with `new_val` in iterator range.

	replace_if(beg, end, pred, new_val)

Replace elements whose return value is non-zero when calling predicate with new value witin range.

	replace_copy(beg, end, dest, old_val, new_val)

Copy elements in iterator range to dest, and replace elements whose values are `old_val` with `new_val`.

	replace_copy_if(beg, end, dest, pred, new_val)

Copy elements in iterator range to dest, replace elements whose return value is non-zero when calling predicate.






