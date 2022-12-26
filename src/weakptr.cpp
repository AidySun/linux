#include <iostream>
#include <memory>

using std::cout;
using std::endl;

std::weak_ptr<int> wp;

void observe() {
  cout << "wp.use_count = " << wp.use_count() << endl;
  if (auto sp = wp.lock()) {
    {
    cout << "wp . val = " << *sp << endl;
    cout << "in lock. wp.use_count = " << sp.use_count() << endl;
    }

  } else {
    cout << "wp is expired\n";
    return;
  }

    cout << "out lock. wp.use_count = " << wp.use_count() << endl;
}

int main() {
  {
    auto sp = std::make_shared<int>(100);
    cout << "new shard_ptr coutn = " << sp.use_count() << endl;
    wp = sp;
    observe();
  }

  cout << " out scope \n";
    observe();

  cout << wp.lock() <<  "\ndone \n";
  if(wp.lock() == nullptr) cout << "nullptr\n";
  else cout << "is not nullptr\n";
  return 0;
}
