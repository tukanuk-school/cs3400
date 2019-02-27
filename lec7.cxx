// For use below...

struct A {};
struct B {};
struct C {};


struct NAME :
	A, 			// struct inheritence in public by default
	private B, 	// B is inhetited privately 
	C			// struct ingeritence is public by default
{
	/* all members are public by default */
	int q;		// q is public wrt to scope

	protected:
		int i; 	// i is protected with respect to scope

	private:
		int r;	// r is private wrt to scope
};

class NAME2 :
	A,			// struct inheritence in PRIVATE by default
	public B	// B is inherited publically
{
	/* all members are PRIVATE by default */
};


class Derived1 :
	public NAME // no members/functions are demoted in scope
{
};

class Derived2 :
	protected NAME	// all public members are demoted to protected
{
};

class Derived3 :
	private NAME	// All public and protected members are demoted 
					// to private scope
{
};


