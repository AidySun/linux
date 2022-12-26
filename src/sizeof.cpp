#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::cout;
using std::endl;

struct S {};
struct SS: S { int a; };
struct SSS: SS { char c; };

void p() {
	cout << "sizeof char:" << sizeof(char) << endl;
	cout << "sizeof bool:" << sizeof(bool) << endl;

	cout << "sizeof short:" << sizeof(short) << endl;
	cout << "sizeof int:" << sizeof(int) << endl;
	cout << "sizeof float:" << sizeof(float) << endl << endl;

	cout << "sizeof long:" << sizeof(long) << endl;
	cout << "sizeof double:" << sizeof(double) << endl;
	cout << "sizeof intptr_t:" << sizeof(intptr_t) << endl;
	cout << "sizeof ptrdiff_t:" << sizeof(ptrdiff_t) << endl;
	cout << "sizeof pointer:" << sizeof(void*) << endl;
	cout << "size of long long: " << sizeof(long long) << endl;
	cout << "size of long double: " << sizeof(long double) << endl;
	cout << "INT_MAX = " << INT_MAX << ", SIZE_MAX = " << SIZE_MAX << ", PTRDIFF_MAX = " << PTRDIFF_MAX << endl;
	cout << "LONG MAX = " << LONG_MAX << endl ;
	cout << endl;
}

//#pragma pack(2)
struct sa {
	int a;
	char b;
	short c;
};
//#pragma pack(4)
struct sb {
	char b;
	int a;
	short c;
};
struct sc {
	short c;
	char b;
	int a;
};
struct st {
	int b;
	short c;
	int* d;
	long a;
};
struct sd {
   int b;            // 4 bytes
   char d;           // 1 byte
   short c;          // 2 bytes
   char _pad1[1];    // padding to make sizeof(x_) multiple of 4
} bar[3];
struct se {
   int b;            // 4 bytes
   char d;           // 1 byte , aligned to short c
   short c;          // 2 bytes, start from [6], which align char d to be 2 bytes
   char _pad1[1];    // 1 , 
};
struct sf {
	char c; int i;
};
int main() {
  p();
  cout << "sa:" << sizeof(sa) << endl;
  cout << "sb:" << sizeof(sb) << endl;
  cout << "sc:" << sizeof(sc) << endl;
  cout << "sd:" << sizeof(sd) << endl;
  cout << "se:" << sizeof(se) << endl;
  cout << "sf:" << sizeof(sf) << endl;
  cout << "st:" << sizeof(st) << endl;
  return 0;
}


int main1() {

	S s;
	SS ss;
	SSS sss;

	cout << "sizeof S: " << sizeof(S) << endl;
	cout << "sizeof ss: " << (sizeof ss) << endl;
	cout << "sizeof sss: " << (sizeof sss) << endl;

	cout << "sizeof size_t: " << sizeof(size_t)  << ", typid():" << typeid(size_t).name() << endl;
	std::string str = "hello";
	char ch[] = "world";

	cout << "size of string : " << sizeof(str) << ", length(): " << str.length() << endl;
	cout << "size of ch : " << sizeof(ch) << ", strlen: " << strlen(ch) << endl;

	return 0;
}
int main0() {
  vector<int> v {0, 1, 2, 3, 4, 5};

  auto i = v.begin();
  advance(i, 3);
  cout << "i = " << *i << endl;

  for (auto n : v) {
    cout << n << " ";
  }
  return 0;
}
