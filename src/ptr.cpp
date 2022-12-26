#include <iostream>
//#include <shared_ptr>
using namespace std;

int main() {

  shared_ptr<int> a(new int(10));
  cout << sizeof(a) << endl;

  return 0;
}

