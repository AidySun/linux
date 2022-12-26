#include <iostream>

using namespace std;

class A {
	int a;
public:
	A(): a(100) { }
	virtual ~A() {}

	A(const A& _a): a(_a.a) {
		cout << "A(const A& _a)" << endl;
	}

	A& operator=(const A& _a) {
		a = _a.a;
		cout << "A& operator=(const A& _a)" << endl;
		return *this;
	}

	virtual void hello() {
		cout << "this is A, int: " << a << endl;
	}

};

class B: public A {
	int b;
public:
	B(): A(), b(200) {}
	~B() {}

	virtual void hello() {
		cout << "this is B, int: " << b << endl;
	}

	B(const B& _b): b(_b.b) {
		cout << "B(const B& _b)" << endl;
	}
	
	B& operator=(const B& _b) {
		b = _b.b;
		cout << "B& operator=(const b& _b)" << endl;
		return *this;
	}
};

int main() {
	{
		cout << "\n A* a \n";
		A* a = new A();
		B* b = new B();


		a->hello();
		b->hello();

		cout << " ==== 	a = static_cast<A*>(b);\n";
		a = static_cast<A*>(b);
		a->hello();
		b->hello();

		cout << " ==== 	b = static_cast<B*>(a);\n";
		b = static_cast<B*>(a);
		a->hello();
		b->hello();
	}
	cout << "\n A a \n";
	A a;
	B b;


	a.hello();
	b.hello();

	cout << " ==== 	a = static_cast<A&>(b);\n";
	a = static_cast<A&>(b);
	a.hello();
	b.hello();

	cout << " ==== 	b = static_cast<B&>(a);\n";
	b = static_cast<B&>(a);
	a.hello();
	b.hello();


	return 0;
}

