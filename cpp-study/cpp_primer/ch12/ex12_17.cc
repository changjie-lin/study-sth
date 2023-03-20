#include <memory>

int main() {

	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef std::unique_ptr<int> IntP;
	
	// (a) illegal.
	// IntP p0(ix);

	// (b) illegal. Run time error.
	// The reason is that when the unique_ptr is out of scope, delete will
	// be called to free the memory. But the object is not allocated by new.
	
	//IntP p1(pi);

	/*
	 * (c) Compile. But it causes a dangling pointer (pi2) at run time.
	 * */

	IntP p2(pi2);

	/*
	 * (d) Same as (b)
	 * */
	//IntP p3(&ix);


	/*
	 * (e) Legal and recommended usage.
	 * */
	//IntP p4(new int(2048));

	/*
	 * (f) error double free or corruption at run time
	 * */
	IntP p5(p2.get());

	return 0;
}
