# C++

## 自动类型推导

- since C++ 11
- “自动类型推导”是给编译器下的指令，是编译阶段的特殊指令。
- auto 总是推导出“值类型”，绝不会是“引用”；auto 可以附加上 const、volatile、*、& 这样的类型修饰符，得到新的类型。
- auto 用于初始化时的类型推导，总是“值类型”，也可以加上修饰符产生新类型。它的规则比较好理解，用法也简单，应该积极使用。
- decltype 使用类似函数调用的形式计算表达式的类型，能够用在任意场合，因为它就是一个编译阶段的类型。decltype 能够推导出表达式的精确类型，但写起来比较麻烦，在初始化时可以采用 decltype(auto) 的简化形式。
- decltype 不仅能够推导出值类型，还能够推导出引用类型，也就是表达式的“原始类型”。

## Const / Volatile / Mutable

- volatile 会禁止编译器做优化
  `const volatile int MAX_LEN  = 1024; // MAX_LEN 可被修改`
- mutable它用来修饰成员变量，允许 const 成员函数修改，mutable 变量的变化不影响对象的常量性，但要小心不要误用损坏对象。 

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
















