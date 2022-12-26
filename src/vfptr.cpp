#include <iostream>

using namespace std;

class A {
  public:
    int a;
    virtual ~A() {}
};

class B: public A {
  public:
    int b;
    virtual void funb() {}
};

int main() {
  A a;
  B b;
  cout << "sizeof a: " << sizeof(a) << endl;
  cout << "sizeof b: " << sizeof(b) << endl;
  double  d1 = 10.1, d2 = 10.9;
  cout << "d1: " << (int)d1 << ", d2: " << (int)d2 << endl;
  return 0;
}
