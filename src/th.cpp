// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <string>

using namespace std;
 
void pause_thread(int n) 
{
  std::this_thread::sleep_for (std::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended\n";
}
 
int main() 
{
  int i = 100;
  const int& ci = i;
  const int * pi = &i;
  int & ri = i;
  auto aci = ci;
  auto api = pi;
  auto ari = ri;
  decltype(ci) dci = ci;
  decltype(pi) dpi = pi;
  decltype(ri) dri = ri;

  cout << "\t ci \t\t pi \t\t ri \t\n";
  cout << "\t" << typeid(ci).name() << "\t" << typeid(pi).name() << "\t" << typeid(ri).name() << endl;
  cout << "\t" << typeid(ci) << "\t" << typeid(pi) << "\t" << typeid(ri) << endl;
  cout << "\t" << typeid(aci).name() << "\t" << typeid(api).name() << "\t" << typeid(ari).name() << endl;
  cout << "\t" <<  typeid(dci).name() << "\t" << typeid(dci).name() << "\t" << typeid(dri).name() << endl;


  std::cout << "Spawning 3 threads...\n";
  std::thread t1 (pause_thread,0.5);
  std::thread t2 (pause_thread,2);
  std::thread t3 (pause_thread,3);
  t2.join();
  std::cout << "Done spawning threads. Now waiting for them to join:\n";
  for (int i = 0; i < 10000; i++) {
    int sum = i+ i + 23 -1 / 12;
  }
  t3.join();
  //t1.join();
  std::cout << "All threads joined!\n";

  return 0;
}
