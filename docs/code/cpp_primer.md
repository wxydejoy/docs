<!--
 * @Author: weiekko weiekko@gmail.com
 * @Date: 2023-05-29 22:33:22
 * @LastEditors: weiekko weiekko@gmail.com
 * @LastEditTime: 2023-05-31 14:18:47
 * @FilePath: \docs\docs\code\cpp_primer.md
 * @Description: 
 * 
 * Copyright (c) 2023 by weiekko weiekko@gmail.com, All Rights Reserved. 
-->
<!-- docs/code/cpp_primer.md -->


链接: https://pan.baidu.com/s/1FQ4rQ7ZBb5CY5P8_NL0mMQ?pwd=j4yv

前言 之前有看过cpp primer plus 但看的不是很认真  所以 我又来了 换一本 可能会好一点


因为有一些基础 这里跳过一些章节,只看一遍
# C++ Primer


## Start

跳过

## 2 变量和基本类型

顶层const 与 底层const

顶层const表示指针本身是个常量，底层const表示指针所指的对象是一个常量。

```cpp
int i = 0;
int *const p1 = &i; // 不能改变p1的值，即p1总是指向i
const int ci = 42; // 不能改变ci的值
const int *p2 = &ci; // 允许改变p2的值，即p2可以指向别的对象
const int *const p3 = p2; // 靠右的const是顶层const，靠左的是底层const
const int &r = ci; // 用于声明引用的const都是底层const
```

还是无法理解


constexpr 和常量表达式
    
```cpp
const int max_files = 20; // max_files是常量表达式
const int limit = max_files + 1; // limit是常量表达式
int staff_size = 27; // staff_size不是常量表达式
const int sz = get_size(); // sz不是常量表达式
```

```cpp
constexpr int mf = 20; // 20是常量表达式
constexpr int limit = mf + 1; // mf + 1是常量表达式
constexpr int sz = size(); // 只有当size()是constexpr函数时sz才是正确的声明
```

constexpr 定义的对象为顶层const



类型别名

```cpp
typedef double wages; // wages是double的同义词
typedef wages base, *p; // base是double的同义词，p是double*的同义词
```
别名声明

```cpp
using SI = Sales_item; // SI是Sales_item的同义词
```

auto
    
```cpp
auto i = 0, *p = &i; // 正确：i是整数，p是整型指针
auto sz = 0, pi = 3.14; // 错误：sz和pi的类型不一致
```

decltype

通过表达式推断出要定义的变量的类型，但是不想用该表达式的值初始化变量，而是希望变量的类型就是该表达式的类型。

```cpp

decltype(f()) sum = x; // sum的类型就是函数f的返回类型
```

编写自己的头文件
```cpp
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif
```

## 3 字符串、向量和数组

命名空间

```cpp
using namespace std;

using namespace::name;
```

头文件不应该包含using声明

string

```cpp
string s1; // 默认初始化，s1是一个空串
string s2(s1); // s2是s1的副本
string s2 = s1; // 等价于s2(s1)
string s3("value"); // s3是字面值"value"的副本，除了字面值最后的那个空字符外
string s3 = "value"; // 等价于s3("value")
string s4(n, 'c'); // 把s4初始化为由连续n个字符c组成的串
string s5 = "hiya"; // 等价于s5("hiya")
```

直接初始化和拷贝初始化

```cpp
string s1 = "hiya"; // 拷贝初始化
string s2("hiya"); // 直接初始化
string s3(10, 'c'); // 直接初始化
string s4 = string(10, 'c'); // 拷贝初始化
```

string对象上的操作

```cpp
os << s; // 将s写到输出流os当中，返回os
is >> s; // 从is中读取字符串赋给s，字符串以空白分隔，返回is
getline(is, s); // 从is中读取一行赋给s，返回is
s.empty(); // 如果s为空则返回true，否则返回false
s.size(); // 返回s中字符的个数
s[n]; // 返回s中第n个字符的引用
s1 + s2; // 返回s1和s2连接后的结果
s1 = s2; // 将s2的值赋给s1
s1 == s2; // 如果s1和s2的值相等则返回true，否则返回false
s1 != s2; // 如果s1和s2的值不相等则返回true，否则返回false
<, <=, >, >=; // 利用字符在字典中的顺序进行比较比较
```



基于范围的for语句

```cpp
for (declaration : expression)
    statement
```

```cpp
for (auto &c : s) // 对于s中的每个字符（注意c是引用）
    c = toupper(c); // c是一个引用，因此赋值语句将改变s中字符的值
```

只处理一部分元素

```cpp
if (!s.empty())
    s[0] = toupper(s[0]);
```

使用下标运算符的循环

```cpp
for (decltype(s.size()) index = 0; 
    index != s.size() && !isspace(s[index]); ++index)
    s[index] = toupper(s[index]);
```



vector

集合

```cpp
#include <vector>
using std::vector;
```

```cpp

vector<T> v1; // v1是一个空的vector，它潜在的元素是T类型的，执行默认初始化
vector<T> v2(v1); // v2中包含有v1所有元素的副本
vector<T> v2 = v1; // 等价于v2(v1)
vector<T> v3(n, val); // v3包含了n个重复的元素，每个元素的值都是val
vector<T> v4(n); // v4包含了n个重复执行了值初始化的对象
vector<T> v5{a, b, c...}; // v5包含了初始值个数的元素，每个元素被赋予相应的初始值
vector<T> v5 = {a, b, c...}; // 等价于v5{a, b, c...}

//注意区分圆括号和花括号
```

**注意 for 循环不应该用于改变容器的大小**

其他操作

```cpp
v.empty(); // 如果v中没有元素则返回true，否则返回false
v.size(); // 返回v中元素的个数
v.push_back(t); // 在v的末尾添加一个值为t的元素
v[n]; // 返回v中第n个位置上的元素的引用
v1 = v2; // 用v2中元素的副本替换v1中的元素
v1 = {a, b, c...}; // 用列表中元素的副本替换v1中的元素
v1 == v2; // 如果v1和v2中的元素相同（个数和值都相同）则返回true，否则返回false
v1 != v2; // 如果v1和v2中的元素不同则返回true，否则返回false
<, <=, >, >=; // 利用元素的字典顺序进行比较
```


迭代器

```cpp
auto b = v.begin(), e = v.end(); // b和e分别指向v的第一个元素和尾元素之后的位置
```

迭代器类型

```cpp
vector<int>::iterator it; // it能读写vector<int>的元素
string::iterator it2; // it2能读写string对象中的字符
vector<int>::const_iterator it3; // it3只能读元素，不能写元素
string::const_iterator it4; // it4只能读字符，不能写字符

// cbegin 和 cend

auto it = v.cbegin(); // it的类型是vector<int>::const_iterator
auto it2 = v.begin(); // it2的类型是vector<int>::iterator
```

-> 运算符

```cpp
(*it).empty(); // 解引用it，然后获取返回的string的empty成员
it->empty(); // 等价于(*it).empty() 这个在qt中经常用到

```

迭代器运算

```cpp
auto mid = v.begin() + v.size() / 2; // mid指向v的中间元素
```

迭代器的比较运算

```cpp
vector<int> v = {1, 3, 5, 7, 9, 12};
auto beg = v.begin(), end = v.end();
auto mid = v.begin() + (end - beg) / 2; // 初始状态下mid指向v的第一个元素
int sought = 7;
while (mid != end && *mid != sought) {
    if (sought < *mid) // 如果要找的元素在前半部分
        end = mid; // 调整搜索范围使得忽略掉后半部分
    else // 如果要找的元素在后半部分
        beg = mid + 1; // 调整搜索范围使得忽略掉前半部分
    mid = beg + (end - beg) / 2; // 新的中间点
}
```



## 4 表达式

sizeof运算符

```cpp
sizeof (type)
sizeof expr
```

sizeof返回一条表达式或一个类型名字所占的字节数

```cpp
sizeof (int)
sizeof (Sales_data)
```



类型转换

隐式转换
```cpp
bool b = 42; // b为true
int i = b; // i的值为1
i = 3.14; // i的值为3
double pi = i; // pi的值为3.0
unsigned char c = -1; // 假设char占8比特，c的值为255
signed char c2 = 256; // 假设char占8比特，c2的值是未定义的
```

显式转换

```cpp
bool b = 42; // b为true
int i = b; // i的值为1
i = static_cast<int>(3.14); // i的值为3

//指针
int *ip;
char *pc = reinterpret_cast<char*>(ip); // 将指针ip的值转换成char*类型
```

static_cast 具有明确定义的类型转换 只要不包含底层const 都可以使用
```cpp
double slope = static_cast<double>(j) / i;
```

dynamic_cast 通常用于将基类的指针或引用安全地转换成派生类的指针或引用
```cpp
if (Base *bp = dynamic_cast<Base*>(p))
    bp->f();
else
    // 处理dynamic_cast失败的情况
```

const_cast 只能改变运算对象的底层const
```cpp
const char *pc;
char *p = const_cast<char*>(pc); // 正确：但是通过p写值是未定义的
```

reinterpret_cast 通常为运算对象的位模式提供较低层次上的重新解释
```cpp
int *ip;
char *pc = reinterpret_cast<char*>(ip); // 将指针ip的值转换成char*类型
```


**建议不用强制类型转换**

## 5 语句

try

```cpp
try {
    program-statements
} catch (exception-declaration) {
    handler-statements
} catch (exception-declaration) {
    handler-statements
} catch (exception-declaration) {
    handler-statements
}
```

标准异常

```cpp
exception // 最常见的异常，没有提供任何额外信息
runtime_error // 可以在运行时检测出的错误
range_error // 当使用一个超出有效范围的值时会被检测出来
overflow_error // 当发生上溢时会被检测出来
underflow_error // 当发生下溢时会被检测出来
logic_error // 程序逻辑错误
domain_error // 当使用了一个无效的参数时会被检测出来
invalid_argument // 当使用了一个无效的参数时会被检测出来
length_error // 当创建了一个超出该类型最大长度的对象时会被检测出来
out_of_range // 当使用了一个超出有效范围的值时会被检测出来
```



## 6 函数

main 处理命令行选项

```cpp
int main(int argc, char *argv[]) {
    // ...
}
```

argc 是一个整数，用于表示在命令行中输入的参数的数目

argv 是一个数组，每个元素都是一个字符指针，指向一个以空字符结尾的字符数组，其中的字符数组表示一个C风格字符串

含有可变形参的函数



```cpp
void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}
```

省略符形参

```cpp

void foo(parm_list, ...) {
    // ...
}
```


**不要返回局部对象的引用或指针**


列表初始化返回值

```cpp
vector<string> process() {
    // ...
    if (expected.empty())
        return {}; // 返回一个空的vector
    else if (expected == actual)
        return {"functionX", "okay"}; // 返回一个有两个元素的vector
    else
        return {"functionX", expected, actual}; // 返回一个有三个元素的vector
}
```


主函数main的返回值

```cpp
int main() {
    // ...
    return 0; // 表示成功
    return -1; // 表示失败
}
```

```cpp
int main(int argc, char *argv[]) {
    // ...
    return EXIT_SUCCESS; // 表示成功
    return EXIT_FAILURE; // 表示失败
}
```


递归

调用自身的函数

```cpp
int factorial(int val) {
    if (val > 1)
        return factorial(val - 1) * val;
    return 1;
}
```

返回数组指针的函数

```cpp
// 返回数组指针的函数
Type (*function(parameter_list))[dimension] {
    // ...
}
```

```cpp


int (*func(int i))[10]; // func是一个函数，该函数接受一个int形参，返回一个指针，该指针指向含有10个整数的数组
```


尾置返回类型

```cpp
auto func(int i) -> int(*)[10]; // 等价于上面的func
```

使用decltype

```cpp
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even; // 返回一个指向数组的指针
}
```

函数重载

```cpp
// 重载的函数必须在形参数量或形参类型上有所区别
// 不能仅通过返回类型区分
Record lookup(const Account&);
Record lookup(const Phone&);
Record lookup(const Person&);
```

const_cast 与重载

const_cast 只能改变运算对象的底层const  

```cpp
// 重载的函数不能仅通过返回类型区分
const string &shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}
string &shorterString(string &s1, string &s2) {
    auto &r = shorterString(const_cast<const string&>(s1),
                            const_cast<const string&>(s2));
    return const_cast<string&>(r);
}
```


特殊用途语言特性

默认实参

```cpp
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
```

默认实参只能在函数声明中出现一次


内联函数

```cpp
inline const string &shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}
```


constexpr函数

constexpr函数是指能用于常量表达式的函数

```cpp
constexpr int new_sz() { return 42; }

```
调试帮助

```cpp
assert(expr);
// 如果expr为假，则终止程序的执行
```

NDEBUG

assert宏定义在cassert头文件中，该头文件定义了一个名为NDEBUG的预处理变量，如果定义了NDEBUG，则assert什么也不做

```cpp
#ifndef NDEBUG
    cerr << __func__ << ": array size is " << size << endl;
#endif
```

其中
```cpp
__func__  // 是一个局部静态变量，存放着当前函数的名字
__FILE__  // 是一个字符串字面值，存放着当前文件的名字
__LINE__  // 是一个整型常量，存放着当前行的行号
__TIME__  // 是一个字符串字面值，存放着文件被编译的时间
__DATE__  // 是一个字符串字面值，存放着文件被编译的日期
```


函数指针

```cpp
bool lengthCompare(const string &, const string &);
bool (*pf)(const string &, const string &); // 未初始化
pf = lengthCompare; // pf现在指向名为lengthCompare的函数
pf = &lengthCompare; // 等价的赋值语句
```

## 7 类

构造函数初始值列表

```cpp
Sales_data::Sales_data(std::istream &is) : bookNo("0"), units_sold(0), revenue(0.0) {
    is >> *this;
}
```
其中 bookNo("0") 是一个构造函数初始值列表，用于为新创建的对象的一个或几个数据成员赋初值


访问控制与封装

```cpp
class Sales_data {
public: // 接口：成员函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private: // 实现：数据成员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

友元 

```cpp
class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
public:

    // constructors
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &is) { read(is, *this); }

    // operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    
private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
```

友元的声明仅仅指定了访问权限，而非一个通常意义上的函数声明

友元与public 的区别

1. public访问权限：
   - public是C++中的一种访问修饰符，用于指定类的成员对外部是可见和可访问的。
   - public成员可以在类的内部和外部的任何地方被访问，包括类的成员函数、类的对象以及类的派生类等。
   - public成员在类的外部可以被其他类或函数直接访问和使用。

2. 友元关系：
   - 友元关系是C++中一种特殊的关系，允许其他类或函数在类的成员访问权限之外访问该类的私有成员。
   - 友元关系通过在类的定义中使用关键字friend来声明。友元可以是另一个类、一个函数或一个函数模板。
   - 友元关系破坏了封装性，因为它允许其他实体直接访问类的私有成员，而不经过类的公共接口。

区别：
- 访问权限：public是控制类成员的访问权限的一种修饰符，而友元关系是一种特殊的授权机制，用于授予其他实体对类的私有成员的访问权限。
- 范围：public成员可以在类的内部和外部被访问，而友元可以是其他类或函数，通过友元关系可以在类的成员访问权限之外访问私有成员。
- 影响封装性：友元关系破坏了封装性，因为它允许其他实体直接访问类的私有成员，而public成员只是指定了成员的访问权限，并没有破坏封装性。


委托构造函数

```cpp
class Sales_data {
public:
    //非委托构造函数
    Sales_data(std::string s, unsigned cnt, double price) :
               bookNo(s), units_sold(cnt), revenue(cnt * price) { }
    //其余构造函数全部委托给另一个构造函数
    Sales_data() : Sales_data("", 0, 0) { }
    Sales_data(std::string s) : Sales_data(s, 0, 0) { }
    Sales_data(std::istream &is) : Sales_data() { read(is, *this); }
    // ...
};
```

类 类型转换


只允许一步类类型转换



类 类型转换不是总能成功


explicit 构造函数


聚合类

字面值常量类

```cpp
class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { hw = b; }
private:
    bool hw; // 硬件错误
    bool io; // IO错误
    bool other; // 其他错误
};
```

```cpp
constexpr Debug io_sub(false, true, false); // 错误状态中只有io是真
if (io_sub.any()) // 如果有任何错误发生
    cerr << "print appropriate error messages" << endl;
constexpr Debug prod(false); // prod的所有错误状态都是假的
if (prod.any()) // 如果有任何错误发生
    cerr << "print an error message" << endl;
```

类的静态成员

```cpp
class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

double Account::interestRate = initRate();
```

```cpp
double r;
r = Account::rate(); // 访问静态成员
a.rate(); // 通过对象访问静态成员
```

静态成员存在于任何对象之外，所以即使类的对象不存在，类的静态成员也可以被访问
静态成员也不与任何对象绑定在一起，所以不存在this指针   静态成员函数不能声明成const的 也不能在函数体内使用this指针


## 第二部分 C++标准库

## 8 IO库