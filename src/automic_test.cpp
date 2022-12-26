#include <iostream>
#include <atomic>
#include <thread>

using std::cout;
using std::endl;

std::atomic<int> f(0);

void setf(int x) {
  std::cout<<std::this_thread::get_id() << endl;
  std::cout << "set f to be " << x << endl;
//  f = x;
  f.store(x, std::memory_order_relaxed);
}

void printvf() {
  std::cout<<std::this_thread::get_id() << endl;
  int x = 0;
  do {
    x = f.load(std::memory_order_relaxed);
    cout << "load\n";
  } while (x == 0);

  f.store(11, std::memory_order_relaxed);

  std::cout << "x != 0 , x = " << x << endl;

}

int main() {
  cout << "th1\n";
  std::thread th1(printvf);
  cout << "th2\n";
  std::thread th2(setf, 20);
  cout << "join th1\n";
  th1.join();
  cout << "join th2\n";
  //th2.join();

  while (f != 11) {
    cout<<"waiting 11\n";
  }
  
  cout << "end main\n";
  return 0;
}

