#include <iostream>

using namespace std;

struct A 
{ 
	A()
	{
		cout << "A::A() " << this << "\n"
	}
	~A()
	{
		cout << "A::A() " << this << "\n"
	}

	A(A const& a)
	{
		cout << "A::A(COPY: " << &a << ") " << this << "\n"
	}

	A& operator = (A const& a)
	{
		cout << "A& : " << &a << ") " << this << "\n"
	}

};

struct B { };

struct Foo
{
	A a;
	B b;

	Foo()
	{
		a = A();
		b = B();
	}
};

int main()
{

}
