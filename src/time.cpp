#include <iostream>
#include <ctime>
#include <unistd.h>
#include <random>

using std::cout;
using std::endl;

int main() {
  cout << "INT_MAX = " << INT_MAX << endl;
  cout << "RAND_MAX = " << RAND_MAX << endl;
  time_t t;
  t = time(0);
  srand(t);
  //srand(i*100/5 + i*20/30 + 20 );

  for (int i = 0; i < 30; i++) {
    cout << rand() << endl;
  }


  cout << "\nRandom\n";

  std::default_random_engine e;
  for (int i = 0; i < 30; i++) {
    cout << e() << endl;
  }
  cout << "MIN = " << e.min() << endl;
  cout << "MAX = " << e.max() << endl;
  return 1;
}
