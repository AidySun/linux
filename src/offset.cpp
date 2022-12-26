#include <stddef.h>
#include <iostream>

using namespace std;

class A {
  public:
    int a;
    char b;
    short s;
    char c;
};

class B {
  public:
    char c;
    double d;
    short s;
    char c2;
};


int main() {

  cout << "sezeof(A) = " << sizeof(A) << ", alignof() = " << alignof(A) << endl;
  cout << "A::int = " << offsetof(class A, a) << endl;
  cout << "A::char = " << offsetof(class A, b) << endl;
  cout << "A::short = " << offsetof(class A, s) << endl;
  cout << "A::char = " << offsetof(class A, c) << endl;

  cout << "sezeof(B) = " << sizeof(B) << ", alignof() = " << alignof(B) << endl;
  cout << "B::char = " << offsetof(class B, c) << endl;
  cout << "B::double = " << offsetof(class B, d) << endl;
  cout << "B::short = " << offsetof(class B, s) << endl;
  cout << "B::char = " << offsetof(class B, c2) << endl;
  return 0;
}

