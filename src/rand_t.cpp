#include <iostream>
#include <time>

using std::cout;
using std::endl;

int main() {
  time_t t(0);
  sand(t);

  cout << "INT_MAX: " << INT_MAX << ", RAND_MAX: " << RAND_MAX << endl;
  for (int i = 0; i < 10; i++) {
    cout << rand() << endl;
  }
  return 0;
}
