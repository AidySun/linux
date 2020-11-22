# C++

<!-- MarkdownTOC autolink=true -->

- [C++11](#c11)
- [Auto, decltype](#auto-decltype)
- [inline](#inline)
- [Const , Volatile , Mutable](#const--volatile--mutable)
- [Override vs Overwrite vs Overload](#override-vs-overwrite-vs-overload)
- [vfptr](#vfptr)
- [Smart Pointer](#smart-pointer)
- [String](#string)
	- [regex](#regex)
- [thread](#thread)
- [Container](#container)
	- [sort](#sort)
	- [search](#search)
	- [Lib & Tools](#lib--tools)
- [exception](#exception)
- [lambda](#lambda)
- [design pattern](#design-pattern)
- [forward](#forward)
- [C/C++ Memory Alignment 内存对齐](#cc-memory-alignment-%E5%86%85%E5%AD%98%E5%AF%B9%E9%BD%90)
- [General](#general)
- [IPC - inter process communication](#ipc---inter-process-communication)
- [Client-server communication](#client-server-communication)
- [shared_ptr, auto_ptr, unique_ptr](#shared_ptr-auto_ptr-unique_ptr)
- [rvalue , move, std::forward](#rvalue--move-stdforward)
	- [完美转发](#%E5%AE%8C%E7%BE%8E%E8%BD%AC%E5%8F%91)
	- [move constructor / assignment](#move-constructor--assignment)
- [unordered_set with std::pair](#unordered_set-with-stdpair)

<!-- /MarkdownTOC -->


## C++11

http://c.biancheng.net/cplus/11/

## Auto, decltype

- since C++ 11
- “自动类型推导”是给编译器下的指令，是编译阶段的特殊指令。
- auto 总是推导出“值类型”，绝不会是“引用”；auto 可以附加上 const、volatile、*、& 这样的类型修饰符，得到新的类型。
- decltype 使用类似函数调用的形式计算表达式的类型，能够用在任意场合，因为它就是一个编译阶段的类型。decltype 能够推导出表达式的精确类型，但写起来比较麻烦，在初始化时可以采用 decltype(auto) 的简化形式。
- decltype 不仅能够推导出值类型，还能够推导出引用类型，也就是表达式的“原始类型”。

- decltype 会保留 cv 限定符，而 auto 有可能会去掉 cv 限定符。
- 以下是 auto 关键字对 cv 限定符的推导规则：
    - 如果表达式的类型不是指针或者引用，auto 会把 cv 限定符直接抛弃，推导成 non-const 或者 non-volatile 类型。
    - 如果表达式的类型是指针或者引用，auto 将保留 cv 限定符。
- 当表达式的类型为引用时
  - decltype 会保留引用类型，
  - 而 auto 会抛弃引用类型，直接推导出它的原始类型。

## inline

虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
inline virtual 唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 Base::who()），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

## Const , Volatile , Mutable

- volatile 会禁止编译器做优化
  `const volatile int MAX_LEN  = 1024; // MAX_LEN 可被修改`
- mutable它用来修饰成员变量，允许 const 成员函数修改，mutable 变量的变化不影响对象的常量性，但要小心不要误用损坏对象。 

## Override vs Overwrite vs Overload

- In C++ terminology, you have overriding (relating to virtual methods in a class hierarchy) 
- and overloading (related to a function having the same name but taking different parameters). 
- You also have hiding of names (via explicit declaration of the same name in a nested declarative region or scope). 
- The C++ standard does not use the term "overwrite".

## vfptr

https://blog.twofei.com/496/
虚函数, 则查找虚函数表, 并进行后续的调用. 虚函数表在定义一个时, 编译器就为我们创建好了的. 所有的, 同一个类, 共用同一份虚函数表.

## Smart Pointer

```
template<class T, class... Args>              // 可变参数模板
std::unique_ptr<T>                            // 返回智能指针
my_make_unique(Args&&... args)                // 可变参数模板的入口参数
{
    return std::unique_ptr<T>(                // 构造智能指针
            new T(std::forward<Args>(args)...));    // 完美转发
}
```

## String 

我们还会经常遇到与数字互相转换的事情，以前只能用 C 函数 atoi()、atol()，它们的参数是 C 字符串而不是 string，用起来就比较麻烦，于是，C++11 就增加了几个新的转换函数：stoi()、stol()、stoll() 等把字符串转换成整数；stof()、stod() 等把字符串转换成浮点数；to_string() 把整数、浮点数转换成字符串。

```

assert(stoi("42") == 42);          // 字符串转整数
assert(stol("253") == 253L);       // 字符串转长整数
assert(stod("2.0") == 2.0);       // 字符串转浮点数

assert(to_string(1984) == "1984");       // 整数转字符串
```


### regex

C++11 终于在标准库里加入了正则表达式库 regex

C++ 正则表达式主要有两个类。
- regex：表示一个正则表达式，是 basic_regex 的特化形式；
- smatch：表示正则表达式的匹配结果，是 match_results 的特化形式。

C++ 正则匹配有三个算法，注意它们都是“只读”的，不会变动原字符串。
- regex_match()：完全匹配一个字符串；
- regex_search()：在字符串里查找一个正则匹配；
- regex_replace()：正则查找再做替换。


## thread

在 C++ 里，有四个基本的工具：仅调用一次、线程局部存储、原子变量和线程对象。

async() 会返回一个 future 变量，可以认为是代表了执行结果的“期货”，如果任务有返回值，就可以用成员函数 get() 获取。不过要特别注意，get() 只能调一次，再次获取结果会发生错误，抛出异常 std::future_error。

，这里还有一个很隐蔽的“坑”，如果你不显式获取 async() 的返回值（即 future 对象），它就会同步阻塞直至任务完成（由于临时对象的析构函数），于是“async”就变成了“sync”。

join()函数是一个等待线程函数，主线程需等待子线程运行结束后才可以结束（注意不是才可以运行，运行是并行的），如果打算等待对应线程，则需要细心挑选调用join()的位置

detach()函数是子线程的分离函数，当调用该函数后，线程就被分离到后台运行，主线程不需要等待该线程结束才结束

## Container

-  C++11 为容器新增加的 emplace 操作函数，它可以“就地”构造元素，免去了构造后再拷贝、转移的成本，不但高效，而且用起来也很方便：
- `erase` function uses `Iterator` as the paramenter
- `std::remove` won't delete elements, just move matched elements to end

- **顺序容器**就是数据结构里的线性表，一共有 5 种：array、vector、deque、list、forward_list。按照存储结构，这 5 种容器又可以再细分成两组。连续存储的数组：array、vector 和 deque。指针结构的链表：list 和 forward_list。array 和 vector 直接对应 C 的内置数组，内存布局与 C 完全兼容，所以是开销最低、速度最快的容器。

- **有序容器**：set/multiset 和 map/multimap
  - C++ 的有序容器使用的是树结构，通常是红黑树——有着最好查找性能的二叉树
- 

### sort

- 常见问题对应的算法：
  - 要求排序后仍然保持元素的相对顺序，应该用 stable_sort，它是稳定的；
  - 选出前几名（TopN），应该用 partial_sort；
  - 选出前几名，但不要求再排出名次（BestN），应该用 nth_element；中位数（Median）、百分位数（Percentile），还是用 nth_element；
  - 按照某种规则把元素划分成两组，用 partition；
  - 第一名和最后一名，用 minmax_element。

### search

- 想要在已序容器上执行二分查找，要用到一个名字比较怪的算法：`lower_bound`，它返回第一个“大于或等于”值的位置：
- 对于有序容器 set/map，就不需要调用这三个算法了，它们有等价的成员函数 find/lower_bound/upper_bound，效果是一样的。


### Lib & Tools

- libcurl
- cpr 是对 libcurl 的一个 C++11 封装，
- ZMQ/cppzmp - libcurl 和 cpr 处理的都是 HTTP 协议，虽然用起来很方便，但协议自身也有一些限制，比如必须要一来一回，必须点对点直连，在超大数据量通信的时候就不是太合适。还有一点，libcurl 和 cpr 只能充当 HTTP 的客户端，如果你想写服务器端程序，这两个工具就完全派不上用场。所以，我们就需要一个更底层、更灵活的网络通信工具，它应该能够弥补 libcurl 和 cpr 的不足，不仅快速高效，还能同时支持客户端和服务器端编程。

- 使用 C++ 来开发 Python 扩展。其中，我认为最好的一个就是pybind11。pybind11 的功能是双向的，可以互相调用.
- 使用 ffi 唯一要注意的是，它只能识别纯 C 接口，不认识 C++，所以，写 Lua 扩展模块的时候，内部可以用 C++，但对外的接口必须转换成纯 C 函数。

- 性能分析工具 top，可以快速查看进程的 **CPU、内存使用情况**；
- pstack 可以打印出进程的调用栈信息
- pstack 显示的只是进程的一个“静态截面”，信息量还是有点少，而 strace 可以显示出进程的正在运行的系统调用，实时查看进程与系统内核交换了哪些信息：
- perf 可以说是 pstack 和 strace 的“高级版”，它按照固定的频率去“采样”，相当于连续执行多次的 pstack，然后再统计函数的调用次数，算出百分比。我常用的 perf 命令是“perf top -K -p xxx”，按 CPU 使用率排序，只看用户空间的调用，这样很容易就能找出最耗费 CPU 的函数。
- Google Performance Tools，一般简称为 gperftools。它是一个 C++ 工具集，里面包含了几个专门的性能分析工具（还有一个高效的内存分配器 tcmalloc），
   ```
	apt-get install google-perftools
	apt-get install libgoogle-perftools-dev
   ```

## exception

noexcept 的含义是请编译器优化消除异常的成本，不能禁止异常的发生

## lambda

- lambda expression is variable, not funcion. They can be invoked like a function.

## design pattern

它们被通称为“设计原则”。最常用有 5 个原则，也就是常说的“SOLID”。
- SRP，单一职责（Single ResponsibilityPrinciple）；
- OCP，开闭（Open Closed Principle）；
- LSP，里氏替换（Liskov Substitution Principle）；
- ISP，接口隔离（Interface-Segregation Principle）；
- DIP，依赖反转，有的时候也叫依赖倒置（Dependency Inversion Principle）。

- 关于单件模式，一个“老生常谈”的话题是“双重检查锁定”，你可能也有所了解，它可以用来避免在多线程环境里多次初始化单件，写起来特别繁琐。使用第 14 讲里提到的 call_once，可以很轻松地解决这个问题，但如果你想要更省事的话，其实在 C++ 里还有一种方法（C++ 11 之后），就是直接使用函数内部的 static 静态变量。C++ 语言会保证静态变量的初始化是线程安全的，绝对不会有线程冲突


## forward

在定义模板函数时，我们采用右值引用的语法格式定义参数类型，由此该函数既可以接收外界传入的左值，也可以接收右值；其次，还需要使用 C++11 标准库提供的 forword() 模板函数修饰被调用函数中需要维持左、右值属性的参数。由此即可轻松实现函数模板中参数的完美转发。 

```
//重载被调用函数，查看完美转发的效果
void otherdef(int & t) {cout << "lvalue\n"; }
void otherdef(const int & t) {cout << "rvalue\n"; }
//实现完美转发的函数模板
template <typename T> void function(T&& t) {
    otherdef(forward<T>(t));
}
```

## C/C++ Memory Alignment 内存对齐

- `offsetof(type, member)` shows the offset of member.
- `alignof(type)` shows alignment value
- `#pragma pack(2)` sets the alignment

- 对齐规则如下：
  - 如果设置了内存对齐为 i 字节，类中最大成员对齐字节数为j，那么整体对齐字节n = min(i, j)  （某个成员的对齐字节数定义：如果该成员是c++自带类型如int、char、double等，那么其对齐字节数=该类型在内存中所占的字节数；如果该成员是自定义类型如某个class或者struct，那个它的对齐字节数 = 该类型内最大的成员对齐字节数《详见实例4》）
  - 每个成员对齐规则：类中第一个数据成员放在offset为0的位置；对于其他的数据成员（假设该数据成员对齐字节数为k），他们放置的起始位置offset应该是 min(k, n) 的整数倍
  - 整体对齐规则：最后整个类的大小应该是n的整数倍
  - 当设置的对齐字节数大于类中最大成员对齐字节数时，这个设置实际上不产生任何效果（实例2）；当设置对齐字节数为1时，类的大小就是简单的把所有成员大小相加

- summary:
  - each member should starts from the address of the times of its alignment/size
    ```
    struct x {
        char c; int i;
    };
    ```
    - `sizeof(x)==8`, since `c`'s address is `0`, `i` size is 4, it needs to starts at the address of times of 4, here it is `4`, then `char` aligns 3 bits more.
  - entire struct size should be the times of max(member_alignment)
    ```
	struct x {
	   int b;            // 4 bytes
	   char d;           // 1 byte , aligned to short c
	   short c;          // 2 bytes, start from [6], which align char d to be 2 bytes
	   char _pad1[1];    // 1 , 
	};
    ```
    - total size is 9 after alignment, but it's not times of max(member_alignment), here is `4` of `int b`, then `sizeof(x)==12`.




## General

- sizeof vs strlen
  - sizeof is an operator while strlen is a function
  - sizeof(char*) whould count the ending null char, strlen won't

- nullptr vs NULL
  - `nullptr` is a keyword; `NULL` is a macro def.
  - easier to express int 0 and pointer, especially for template programming. Since NULL is a macro defined as 0. 
    ```
    void func(void*) { ... }
    void func(int) { ... }

    func(NULL); // this calls func(int) which was meant to be func(void*);
    ```

## IPC - inter process communication

- Shared file
- Shared memory
- Message queue
  - bidirectional, any order, can has priority
  - in kernel
  - no lock
  - no limit for parent/child processes
  - `msgsnd, msgget, msgrcv, msgctl, ftok`
- unix pipe
  - unidirectional, FIFO, one to one (end to end)
  - `pipe()`

## Client-server communication

Pipe
Socket
Remote Procedural calls (RPCs)


## shared_ptr, auto_ptr, unique_ptr

- auto_ptr has assignment constructor, unique_ptr must use std::move().
- unique_ptr supports array (delete []), auto_ptr does not. `unique_ptr<int[]> pa`
- std::make_unique(40); // since C++14

- Since **c++17**, `shared_ptr` supports array. Prior C++17, a customized deletar is needed:
  ```
  template <class T>
  struct array_deletar {
  	void operator() (T const * p) {
  		delete[] p;
  	}
  };
  std::shared_ptr<int> sp(new int[10], array_deletar<int>());
  // or
  std::shared_ptr<int> sp1(new int[10], std::default_deleter<int[]>());
  std::shared_ptr<int> sp2(new int[10], [](int *p) { delete[] p; });
  ```
- unique_ptr could work with array
  ```
  unique_ptr<int[]> up(new int[10]);
  ```

## rvalue , move, std::forward

### 完美转发

讲了这么多左值右值和move语义，C++11正是利用它们解决了C++98解决不了的完美转发(perfect forwarding)问题，即实参被传入到函数中，当它被再传到另一个函数中，它依然是一个左值或右值，我们来看一个例子:
```
template <class T>
void f2(T t){
  cout<<"f2"<<endl;
}

template <class T>
void f1(T t){
  cout<<"f1"<<endl;
  f2(t);  //如果t是右值，我们希望传入f2也是右值
}         //如果t是左值，我们希望传入f2也是左值

//在main函数里:
int a = 2;
f1(3); //传入右值
f1(a); //传入左值
```
C++11之前的情况是怎么样的呢？当我们从f1调用f2的时候，不管传入f1的是右值还是左值，因为t是一个变量名，传入f2的时候都变成了左值，这就会造成因为调用T的拷贝构造函数而生成不必要的拷贝浪费大量资源，我们来看C++11如何解决这个问题：
```
template <class T>
void f2(T t){
  cout<<"f2"<<endl;
}

template <class T>
void f1(T&& t){    //这是通用引用，而不是右值引用
  cout<"f1"<<endl;
  f2(std::forward<T>(t));  //std::forward<T>(t)用来把t转发为左值或右值，决定于T
}
```
这样当从f1调用f2的时候，调用的就是移动构造函数而不是拷贝构造函数，实现了完美转发，减少了资源浪费。

### move constructor / assignment

```
class A {
  A();
  ~A();
  A(const A& a);
  A& operator=(const A& a);
  A(A&& a);
  A& operator=(A&& a);
}
```

## unordered_set with std::pair

```
#include <uordered_set>
#include <utility>

struct pair_hash {
	template<class T, class P>
	size_t operator()(std::pair<T, P> p) const {
		size_t h1 = std::hash<T>()(p.first);
		size_t h2 = std::hash<P>()(p.second);
		return h1 ^ h2;
	}
};

unordered_set<pair<int, int>, pair_hash> s;

```



















