<!--
 * @Author: weiekko weiekko@gmail.com
 * @Date: 2023-05-29 22:33:22
 * @LastEditors: weiekko weiekko@gmail.com
 * @LastEditTime: 2023-06-20 18:38:28
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

###  auto

```cpp
auto i = 0, *p = &i; // 正确：i是整数，p是整型指针
auto sz = 0, pi = 3.14; // 错误：sz和pi的类型不一致
```

###  decltype

通过表达式推断出要定义的变量的类型，但是不想用该表达式的值初始化变量，而是希望变量的类型就是该表达式的类型。

```cpp

decltype(f()) sum = x; // sum的类型就是函数f的返回类型
```

###  编写自己的头文件
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

##   3 字符串、向量和数组

### 命名空间

```cpp
using namespace std;

using namespace::name;
```

头文件不应该包含using声明

### string

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

###  

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

###  

### vector

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

###  
### 迭代器

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

###  

## 4 表达式

### sizeof运算符

```cpp
sizeof (type)
sizeof expr
```

sizeof返回一条表达式或一个类型名字所占的字节数

```cpp
sizeof (int)
sizeof (Sales_data)
```

###  

### 类型转换

#### 隐式转换

```cpp
bool b = 42; // b为true
int i = b; // i的值为1
i = 3.14; // i的值为3
double pi = i; // pi的值为3.0
unsigned char c = -1; // 假设char占8比特，c的值为255
signed char c2 = 256; // 假设char占8比特，c2的值是未定义的
```

####  显式转换

```cpp
bool b = 42; // b为true
int i = b; // i的值为1
i = static_cast<int>(3.14); // i的值为3

//指针
int *ip;
char *pc = reinterpret_cast<char*>(ip); // 将指针ip的值转换成char*类型
```

####  static_cast 具有明确定义的类型转换 只要不包含底层const 都可以使用
```cpp
double slope = static_cast<double>(j) / i;
```

#####  dynamic_cast 通常用于将基类的指针或引用安全地转换成派生类的指针或引用
```cpp
if (Base *bp = dynamic_cast<Base*>(p))
    bp->f();
else
    // 处理dynamic_cast失败的情况
```

#####  const_cast 只能改变运算对象的底层const
```cpp
const char *pc;
char *p = const_cast<char*>(pc); // 正确：但是通过p写值是未定义的
```

#####  reinterpret_cast 通常为运算对象的位模式提供较低层次上的重新解释
```cpp
int *ip;
char *pc = reinterpret_cast<char*>(ip); // 将指针ip的值转换成char*类型
```

###  
**建议不用强制类型转换**

## 5 语句

### try

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

###  标准异常

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

###  

## 6 函数

### main 处理命令行选项

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

###  省略符形参

```cpp

void foo(parm_list, ...) {
    // ...
}
```

###  
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

###  
### 主函数main的返回值

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

###  
### 递归

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

###  
尾置返回类型

```cpp
auto func(int i) -> int(*)[10]; // 等价于上面的func
```

###  使用decltype

```cpp
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even; // 返回一个指向数组的指针
}
```

###  函数重载

```cpp
// 重载的函数必须在形参数量或形参类型上有所区别
// 不能仅通过返回类型区分
Record lookup(const Account&);
Record lookup(const Phone&);
Record lookup(const Person&);
```

###  const_cast 与重载

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

###  
特殊用途语言特性

### 默认实参

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

###  
constexpr函数

constexpr函数是指能用于常量表达式的函数

```cpp
constexpr int new_sz() { return 42; }

```
### 调试帮助

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

###  
### 函数指针

```cpp
bool lengthCompare(const string &, const string &);
bool (*pf)(const string &, const string &); // 未初始化
pf = lengthCompare; // pf现在指向名为lengthCompare的函数
pf = &lengthCompare; // 等价的赋值语句
```

###  ## 7 类

构造函数初始值列表

```cpp
Sales_data::Sales_data(std::istream &is) : bookNo("0"), units_sold(0), revenue(0.0) {
    is >> *this;
}
```
其中 bookNo("0") 是一个构造函数初始值列表，用于为新创建的对象的一个或几个数据成员赋初值

### 访问控制与封装

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

###  友元 

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

###  类 类型转换


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

没用过但留个印象吧

IO 类


```cpp
#include <iostream> // istream, ostream, cin, cout


#include <fstream> // ifstream, ofstream, fstream

#include <sstream> // istringstream, ostringstream, stringstream
```

IO对象无拷贝或赋值

```cpp
ofstream out1, out2;
out1 = out2; // 错误：不能对流对象赋值
ofstream print(ofstream); // 错误：不能初始化ofstream参数
out2 = print(out2); // 错误：不能拷贝流对象
```

###  条件状态

```cpp
int ival;
while (cin >> ival, !cin.eof()) { // 读取直到遇到文件结束符
    if (cin.bad()) // 系统级错误
        throw runtime_error("IO流错误");
    if (cin.fail()) { // 输入格式错误
        cerr << "数据错误，请重试：" << endl;
        cin.clear(istream::failbit); // 置位failbit
        continue;
    }
    // 正常处理
}
```

###  查询流的状态

管理条件状态

```cpp
cin.clear(); // 使流有效
cin.clear(istream::failbit); // 置位failbit
cin.clear(istream::badbit); // 置位badbit
cin.clear(istream::eofbit); // 置位eofbit
```

```cpp  
// 重置所有条件状态
cin.clear(); // 使流有效
cin.sync(); // 清空输入缓冲区
```

###  
管理输出缓冲区

```cpp
cout << "hi!" << endl; // 输出hi和一个换行，然后刷新缓冲区
cout << "hi!" << flush; // 输出hi，然后刷新缓冲区，不附加任何额外字符
cout << "hi!" << ends; // 输出hi和一个空字符，然后刷新缓冲区
```

###  unitbuf 操纵符

```cpp
cout << unitbuf; // 所有输出操作后都会立即刷新缓冲区
cout << nounitbuf; // 回到正常的缓冲方式
```

###  
WARN: 如果程序异常终止，输出缓冲区不会被刷新，所以输出不会显示出来

关联输入和输出流

```cpp
cin.tie(&cout); // cin和cout关联在一起，cin先刷新缓冲区
ostream *old_tie = cin.tie(nullptr); // cin不再与其他流关联
cin.tie(&cerr); // cin和cerr关联在一起，cin先刷新缓冲区
cin.tie(old_tie); // 重建cin和cout的关联
```
在这段代码中，为了将一个给定的流关联到一个新的输出流，我们将新流的指针传递给了tie。为了彻底解开流的关联，我们传递了一个空指针。每个流同时最多关联到一个流，但多个流可以同时关联到同一个ostream。

文件输入输出

```cpp
#include <fstream>

ifstream in(ifile); // 打开ifile并创建ifstream对象
ofstream out; // 输出文件流，未绑定到任何文件
out.open("file1"); // 打开file1并与out绑定
ofstream out2("file2"); // 打开file2并与out2绑定
```

###  用fstream代替iostream & 

```cpp
ifstream input(argv[1]); // 打开argv[1]指向的文件
ofstream output(argv[2]); // 打开argv[2]指向的文件
Sales_data total; // 保存当前求和结果的变量
if (read(input,total)){ //读取第一条
    Sales_data trans; // 保存下一条交易数据的变量
    while(read(input,total)){  //读取剩余
        if(total.isbn() == trans.isbn())
            total.combine(trans)
        else{
            print(output,total) // 输出结果
            total = trans; // 处理下一本书
        }
    
    }
}
```

###  
### open 和 close

```cpp
ifstream in;
in.open(ifile); // 打开ifile并与in绑定
in.close(); // 关闭in与ifile的关联
```

```cpp
ofstream out;
out.open("file1"); // 打开file1并与out绑定
out.close(); // 关闭out与file1的关联
```

###  自动构造和销毁流对象 python with open

```cpp
for (int i = 1; i < argc; ++i) {
    ifstream input(argv[i]); // 打开当前文件
    // ...
} // input被销毁，文件自动关闭
```

###  
### 文件模式

```cpp
in 以读方式打开
out 以写方式打开
app 追加方式打开
ate 初始位置：文件尾
trunc 截断文件
binary 二进制方式打开
```

###  

WARN : 以写方式打开一个文件时，如果文件不存在，则创建该文件；如果文件存在，则清空该文件
```cpp
ofstream out("file1", ofstream::app); // 打开file1并定位到文件尾
ofstream out2("file2", ofstream::app | ofstream::binary); // 打开file2并定位到文件尾
```

保留被ofstream打开的文件中已有数据的唯一方法是显式指定app或in模式。



### string流

```cpp
#include <sstream>
istringstream line("Hello 123 456");
string word;
while (line >> word)
    cout << word << endl;
```

```cpp
ostringstream os;
os << "hi!" << endl;
cout << os.str() << endl; // 输出hi!和一个换行
```

使用ostringstream 当我们逐步构造输出，希望最后一起打印时，ostringstream是很有用的。


## 9 顺序容器

### 顺序容器

```cpp
vector //  可变大小数组 在尾部之外的位置插入或删除元素可能很慢
deque // 双端队列 支持快速随机访问 在头尾插入/删除速度很快
list // 双向链表 只支持双向顺序访问  任何位置插入/删除速度都很快
forward_list // 单向链表 只支持单向顺序访问 任何位置插入/删除速度都很快
array // 固定大小数组 不能添加或删除元素 支持快速随机访问
string // 与vector相似 但专门用于保存字符 支持对字符的随机访问  在尾部插入/删除速度很快
```

通常使用vector

基本原则

- 除非有很好的理由选择其他容器，否则应使用vector
- 如果程序有很多小的元素，且空间的额外开销很重要，则不要使用list或forward_list
- 如果程序要求随机访问元素，应使用vector或deque
- 如果程序要求在容器的中间位置插入或删除元素，应使用list或forward_list
- 如果程序需要在头尾位置插入或删除元素，但不会在中间位置进行插入或删除操作，则使用deque
- 如果程序只有在读取输入时才需要在容器中间位置插入元素，之后需要随机访问元素，则可以先使用vector读取输入，再使用swap将元素移动到deque中
    - 首先，确定是否真的需要在容器中间位置添加元素。当处理输入数据时，通常可以很容易地向vector追加数据，然后再调用标准库的sort函数重排容器中的元素，从而避免在中间位置添加元素。
    - 如果必须在中间位置插入元素，考虑在输入阶段使用1ist,一旦输入完成，将list中的内容拷贝到一个vector中。


对容器可以保存的元素类型的限制

顺序容器几乎可以保存任何类型的对象，


通用容器操作

```cpp
//类型别名
iterator // 迭代器
const_iterator // 只读迭代器
size_type // 无符号整型，足够保存容器中任意元素的个数
difference_type // 有符号整型，足够保存两个迭代器之间的距离
value_type // 元素类型
reference // 左值引用，可以读写元素
const_reference // const左值引用，只能读元素

//构造函数
C c; // 默认构造函数
C c1(c2); // c1是c2的拷贝
C c(b, e); // c中包含迭代器对b和e所表示范围中的元素
C c{a, b, c...}; // c中包含初始值个数的元素，每个元素被赋予相应的初始值 列表初始化

//赋值和swap
c1 = c2; // c1中的元素被替换成c2中元素的拷贝
c = {a, b, c...}; // c中的元素被替换成列表中元素的拷贝
a.swap(b); // 交换a和b的元素，两个容器必须相同且具有相同的元素类型

//大小

c.size(); // 返回c中元素的个数
c.max_size(); // 返回c能容纳的最大元素数
c.empty(); // 如果c中不含有任何元素，则返回true，否则返回false

//添加和删除元素 不适应于array

c.insert(args); // 将args指定的元素添加到c中，返回指向新添加的元素的迭代器
c.erase(args); // 从c中删除args指定的元素，返回指向最后一个被删除元素之后位置的迭代器
c.clear(); // 删除c中所有元素

//关系运算符
==, !=, <, <=, >, >=; // 利用元素的<运算符进行比较

//获取迭代器
c.begin(); // 返回指向容器中第一个元素的迭代器
c.end(); // 返回指向容器中最后一个元素之后位置的迭代器

//反向容器的额外成员 不支持forward_list
reverse_iterator // 反向迭代器
const_reverse_iterator // 只读反向迭代器
c.rbegin(); // 返回指向最后一个元素的迭代器
c.rend(); // 返回指向第一个元素之前位置的迭代器
c.crbegin(); // 返回指向最后一个元素的const反向迭代器
c.crend(); // 返回指向第一个元素之前位置的const反向迭代器
```

###  迭代器

这里和py差不多

类型别名的使用

```cpp
vector<int>::iterator it; // it能读写vector<int>的元素
string::iterator it2; // it2能读写string对象中的字符
vector<int>::const_iterator it3; // it3只能读元素，不能写元素
string::const_iterator it4; // it4只能读字符，不能写字符
```

虽然现在还有点看不懂 但总会看懂的

ASSIGN

```cpp
list<string> names;
vector<const char*> oldstyle;
names = oldstyle; // 错误：容器类型不匹配
names.assign(oldstyle.cbegin(), oldstyle.cend()); // 正确：可以将const char*指针转换成string
```

顺序容器操作

添加元素

```cpp
// 这些操作会改变容器的大小 不适用于array
// forward_list 有特殊版本的insert和emplace
// forward_list 不支持push_back和emplace_back
// vector 和 string 不支持push_front和emplace_front
c.push_back(t); // 将t添加到c的尾部
c.emplace_back(args); // 使用args在c的尾部创建一个元素
c.push_front(t); // 将t添加到c的头部
c.emplace_front(args); // 使用args在c的头部创建一个元素
c.insert(p, t); // 将t插入到迭代器p指定的元素之前
c.emplace(p, args); // 使用args在迭代器p指定的元素之前创建一个元素
c.insert(p, n, t); // 将t的n个拷贝插入到迭代器p指定的元素之前
c.insert(p, b, e); // 将迭代器b和e指定范围中的元素插入到迭代器p指定的元素之前
c.insert(p, il); // il是一个花括号包围的元素值列表 将初始化列表中的元素插入到迭代器p指定的元素之前
```

访问元素

```cpp
// at和[]只适用于string vector deque array
// back 不适用于forward_list
c.back(); // 返回c中最后一个元素的引用
c.front(); // 返回c中第一个元素的引用
c[n]; // 返回c中第n个元素的引用
c.at(n); // 返回c中第n个元素的引用，执行边界检查，越界抛出out_of_range异常
```

删除元素

```cpp
// 这些操作会改变容器的大小 不适用于array
// forward_list 有特殊版本的erase和pop_front
// vector 和 string 不支持pop_front
c.pop_back(); // 删除c中的尾元素
c.pop_front(); // 删除c中的头元素
c.erase(p); // 删除迭代器p指定的元素
c.erase(b, e); // 删除迭代器b和e指定范围中的元素
c.clear(); // 删除c中的所有元素
```

特殊的forward_list操作

```cpp
// forward_list 不支持size
// forward_list 不支持push_back和emplace_back
// forward_list 不支持pop_back
// forward_list 不支持insert和emplace
// forward_list 不支持resize

lst.before_begin(); // 返回指向首前元素的迭代器
lst.cbefore_begin(); // 返回指向首前元素的const迭代器
lst.insert_after(p, t); // 将t插入到迭代器p指定的元素之后
lst.emplace_after(p, args); // 使用args在迭代器p指定的元素之后创建一个元素
lst.insert_after(p, n, t); // 将t的n个拷贝插入到迭代器p指定的元素之后
lst.insert_after(p, b, e); // 将迭代器b和e指定范围中的元素插入到迭代器p指定的元素之后
lst.insert_after(p, il); // il是一个花括号包围的元素值列表 将初始化列表中的元素插入到迭代器p指定的元素之后

emplace_after(p, args); // 使用args在迭代器p指定的元素之后创建一个元素

lst.erase_after(p); // 删除迭代器p指定的元素之后的元素
lst.erase_after(b, e); // 删除迭代器b和e指定范围中的元素之后的元素
```

改变容器大小

```cpp
// 不适用于array    
c.resize(n); // 将c中的元素个数改变为n，多余的元素被删除
c.resize(n, t); // 将c中的元素个数改变为n，多余的元素被t初始化
```

容器操作可能使迭代器失效

所以不要保存end返回的迭代器

vector 对象是如何增长的

vector 预留空间作为备用

管理容量的成员函数

```cpp
c.capacity(); // 返回c能保存而不必分配新内存的元素总数
c.reserve(n); // 分配至少能容纳n个元素的内存空间
c.shrink_to_fit(); // 要求归还多余的内存 但是不保证一定归还
```

capacity 和 size 的区别

capacity 能装多少

size 装了多少

额外的string操作

构造string的其他方法

```cpp
string s(cp, n); // s是cp指向的数组的前n个字符的拷贝
string s(s2, pos2); // s是s2从pos2开始的字符的拷贝
string s(s2, pos2, len2); // s是s2从pos2开始的len2个字符的拷贝
string s("value"); // s是字面值"value"的拷贝
string s(n, 'c'); // s是由连续n个字符c组成的串
```

substr

```cpp
string s("hello world");
string s2 = s.substr(0, 5); // s2是hello
string s3 = s.substr(6); // s3是world
```

改变string的其他方法

```cpp
s.insert(pos, args); // 在pos位置插入args指定的元素
s.erase(pos, len); // 删除从pos开始的len个字符
s.replace(pos, len, args); // 删除从pos开始的len个字符，然后在pos位置插入args指定的元素
```

append 和 replace

```cpp
s.append(args); // 将args指定的字符追加到s的末尾
s.replace(b, e, args); // 删除迭代器b和e指定范围中的字符，然后在b位置插入args指定的字符
```

assign

```cpp
s.assign(args); // 用args指定的字符替换s中原来的字符
s.assign(b, e); // 用迭代器b和e指定范围中的字符替换s中原来的字符
s.assign(cp, n); // 用cp指向的数组中的前n个字符替换s中原来的字符
s.assign(s2); // 用s2中的字符替换s中原来的字符
s.assign(s2, pos2, len2); // 用s2中从pos2开始的len2个字符替换s中原来的字符
s.assign("value"); // 用字面值"value"中的字符替换s中原来的字符
s.assign(n, 'c'); // 用n个字符c替换s中原来的字符
```

string搜索操作

```cpp
s.find(args); // 在s中查找args指定的字符
s.rfind(args); // 在s中从末尾开始查找args指定的字符
s.find_first_of(args); // 在s中查找args中任意一个字符第一次出现的位置
s.find_last_of(args); // 在s中查找args中任意一个字符最后一次出现的位置
s.find_first_not_of(args); // 在s中查找第一个不在args中的字符
s.find_last_not_of(args); // 在s中查找最后一个不在args中的字符
```

string比较操作

```cpp
s.compare(args); // 比较s和args指定的字符串
```

string数值转换

```cpp
to_string(args); // 返回args的字符串表示
stoi(s, args, base); // 将s转换成int，base是进制数，args是一个size_t类型的对象，用于存放第一个不能转换的字符的下标
stol(s, args, base); // 将s转换成long，base是进制数，args是一个size_t类型的对象，用于存放第一个不能转换的字符的下标
stoul(s, args, base); // 将s转换成unsigned long，base是进制数，args是一个size_t类型的对象，用于存放第一个不能转换的字符的下标
stoll(s, args, base); // 将s转换成long long，base是进制数，args是一个size_t类型的对象，用于存放第一个不能转换的字符的下标
stoull(s, args, base); // 将s转换成unsigned long long，base是进制数，args是一个size_t类型的对象，用于存放第一个不能转换的字符的下标
stof(s, args); // 将s转换成float，args是一个size_t类型的对象，用于存放第一个不能转换的字符的下标
stod(s, args); // 将s转换成double，args是一个size_t类型的对象，用于存放第一个不能转换的字符的下标
stold(s, args); // 将s转换成long double，args是一个size_t类型的对象，用于存放第一个不能转换的字符的下标
```

容器适配器

stack queue priority_queue

stack 先进后出


```cpp
stack<T> s; // s是空栈
// 填满 
for(size_t ix = 0; ix != 10; ++ix)
    s.push(ix); // 将ix压入栈中
while(!s.empty()){
    int value = s.top(); // 访问栈顶元素
    s.pop(); // 弹出栈顶元素
}
```

queue 先进先出

priority_queue 优先级队列


priority_queue允许我们为队列中的元素建立优先级。新加入的元素会排在所有优先级比它低的已有元素之前。饭店按照客人预定时间而不是到来时间的早晚来为他们安排座位，就是一个优先队列的例子。默认情况下，标准库在元素类型上使用<运算符来确定相对优先级。



## 10 泛型算法

### algorithm 头文件  numeric 头文件

算法不直接操作容器 通过迭代器来访问元素

```cpp
auto result = find(vec.cbegin(), vec.cend(), val);
```

迭代器令算法不依赖于容器 但算法依赖于元素类型的操作

只读算法

```cpp
find(b, e, t); // 在b和e指定的范围中查找值为t的元素
accumulate(b, e, t); // 返回从b到e的和，t是和的初值
equal(b, e, b2); // 如果两个序列在相同位置上的元素都相等，则返回true
```

写容器元素的算法

```cpp
fill(b, e, t); // 将b和e指定的范围内的每个元素都重置为t
fill_n(b, n, t); // 将b指定的范围内的前n个元素都重置为t
copy(b, e, b2); // 将b和e指定的范围内的元素拷贝到以b2开始的位置
copy_n(b, n, b2); // 将b指定的范围内的前n个元素拷贝到以b2开始的位置
copy_if(b, e, b2, f); // 将b和e指定的范围内的满足f的元素拷贝到以b2开始的位置
copy_backward(b, e, e2); // 将b和e指定的范围内的元素拷贝到以e2结束的位置
move(b, e, b2); // 将b和e指定的范围内的元素移动到以b2开始的位置
move_backward(b, e, e2); // 将b和e指定的范围内的元素移动到以e2结束的位置
transform(b, e, b2, f); // 将b和e指定的范围内的元素应用f并存储到以b2开始的位置
generate(b, e, f); // 将b和e指定的范围内的元素应用f并存储到以b2开始的位置
generate_n(b, n, f); // 将b指定的范围内的前n个元素应用f并存储到以b2开始的位置
replace(b, e, t, t2); // 将b和e指定的范围内的值为t的元素替换为t2
replace_if(b, e, f, t2); // 将b和e指定的范围内的满足f的元素替换为t2
replace_copy(b, e, b2, t, t2); // 将b和e指定的范围内的值为t的元素替换为t2并拷贝到以b2开始的位置
replace_copy_if(b, e, b2, f, t2); // 将b和e指定的范围内的满足f的元素替换为t2并拷贝到以b2开始的位置
swap(a, b); // 交换a和b的值
swap_ranges(b, e, b2); // 将b和e指定的范围内的元素与以b2开始的范围内的元素交换
iter_swap(a, b); // 交换a和b的值
reverse(b, e); // 将b和e指定的范围内的元素反转
reverse_copy(b, e, b2); // 将b和e指定的范围内的元素反转并拷贝到以b2开始的位置
rotate(b, b2, e); // 将b和e指定的范围内的元素旋转，b2指定了新的第一个元素
···
```

重排容器元素的算法

```cpp
sort(b, e); // 将b和e指定的范围内的元素排序
```

消除重复单词

```cpp
sort(words.begin(), words.end()); // 将words按字典序排序
auto end_unique = unique(words.begin(), words.end()); // 将不重复的元素放到前面
words.erase(end_unique, words.end()); // 删除重复单词
```

### lambda表达式

```cpp
sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
```

lambda表达式的形式

```cpp
[capture list] (parameter list) -> return type { function body }
```

使用捕获列表

```cpp
auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
```

for each

```cpp
for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });
```
### 值捕获和引用捕获

```cpp
size_t v1 = 42; // 局部变量
auto f = [v1] { return v1; }; // 值捕获：v1是拷贝初始化的
v1 = 0;
auto j = f(); // j为42，f保存了我们创建它时v1的拷贝
```

```cpp
size_t v1 = 42; // 局部变量
auto f2 = [&v1] { return v1; }; // 引用捕获：v1是引用
v1 = 0;
auto j2 = f2(); // j2为0，f2保存了对v1的引用
```

###  隐式捕获

```cpp
size_t v1 = 42; // 局部变量
auto f3 = [=] { return v1; }; // 值捕获：v1是拷贝初始化的
auto f4 = [&] { return v1; }; // 引用捕获：v1是引用
auto f5 = [&, v1] { return v1; }; // 混合捕获：v1是引用
auto f6 = [=, &v1] { return v1; }; // 混合捕获：v1是引用
```

可变lambda

```cpp
size_t v1 = 42; // 局部变量
auto f = [v1] () mutable { return ++v1; }; // 值捕获：v1是拷贝初始化的
v1 = 0;
auto j = f(); // j为43，f保存了我们创建它时v1的拷贝
```

lambda返回类型

```cpp
//错误
transform(vi.begin(), vi.end(), vi.begin(), [](int i) { if (i < 0) return -i; else return i; });
```

```cpp
//正确
transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int { if (i < 0) return -i; else return i; });
```

###  
参数绑定

```cpp
auto check6 = bind(check_size, _1, 6);
```

```cpp
auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
```

```cpp
auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
```

使用placeholders

```cpp
using std::placeholders::_1;
auto check6 = bind(check_size, _1, 6);
```

bind的参数

```cpp
auto g = bind(f, a, b, _2, c, _1);
g(x, y); // 等价于f(a, b, y, c, x)
```

绑定引用参数

```cpp
int f(int v1, int &v2, int v3);
int i = 1024, j = 2048, k = 4096;
auto g = bind(f, _2, ref(i), i);
g(j); // 等价于f(j, i, i)
```

###  再探迭代器

插入迭代器

```cpp
back_inserter(vi); // 返回一个迭代器，每次赋值都会调用push_back
front_inserter(vi); // 返回一个迭代器，每次赋值都会调用push_front
inserter(vi, vi.begin()); // 返回一个迭代器，每次赋值都会调用inse
```

iostream迭代器

```cpp
istream_iterator<int> int_it(cin); // 从cin读取int
istream_iterator<int> int_eof; // 尾后迭代器
ifstream in("afile"); // 打开文件
istream_iterator<string> str_it(in); // 从in读取string
istream_iterator<string> str_eof; // 尾后迭代器
```
下面是一个使用iostream迭代器的例子

```cpp
istream_iterator<int> int_it(cin); // 从cin读取int
istream_iterator<int> int_eof; // 尾后迭代器
while (int_it != int_eof)
    vec.push_back(*int_it++);
```
重写

```cpp
istream_iterator<int> int_it(cin), int_eof; // 从cin读取int
vector<int> vec(int_it, int_eof); // 从int_it到int_eof范围内的元素拷贝到vec
```

使用算法操作流迭代器

```cpp
istream_iterator<int> int_it(cin), int_eof; // 从cin读取int
cout << accumulate(int_it, int_eof, 0) << endl;
```

istream_iterator 允许使用懒惰求值

当我们将一个istream_iterator绑定到一个流时，标准库并不保证从流中读取数据，直到我们试图从迭代器中取值为止。这种行为称为懒惰求值。

ostream_iterator 操作

```cpp
ostream_iterator<int> out_iter(cout, " "); // 输出流迭代器
for (auto e : vec)
    *out_iter++ = e; // 等价于cout << e << " ";
cout << endl;
```

使用流迭代器处理类类型

我们可以为任何定义了输入运算符的类类型定义istream_iterator，为任何定义了输出运算符的类类型定义ostream_iterator。

```cpp
istream_iterator<Sales_item> item_iter(cin), eof;
ostream_iterator<Sales_item> out_iter(cout, "\n");
// 将第一笔交易记录存在sum中，并读取下一条记录
Sales_item sum = *item_iter++;
while (item_iter != eof) {
    // 如果item_iter所指的交易记录与sum相同
    if (item_iter->isbn() == sum.isbn())
        sum += *item_iter++; // 将交易记录累加到sum上
    else {
        out_iter = sum; // 将sum写到输出流
        sum = *item_iter++; // 读取下一条交易记录
    }
}
out_iter = sum; // 将最后一组交易记录写到输出流
```

反向迭代器

```cpp
vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

auto rbegin = vec.rbegin(); // 指向尾元素的迭代器
auto rend = vec.rend(); // 指向首元素的迭代器

while (rbegin != rend) // 逆序打印vec
    cout << *rbegin++ << endl; 
```

反向迭代器需要递减运算符

从技术上讲，普通迭代器与反向迭代器的关系反映了左闭合区间的特性

不是很懂

### 泛型算法结构

#### 5类迭代器

输入迭代器：只读，支持==，!=，++，*，->
输出迭代器：只写，支持++，*
前向迭代器：读写，支持输入迭代器的所有操作
双向迭代器：读写，支持前向迭代器的所有操作，支持--，--
随机访问迭代器：读写，支持双向迭代器的所有操作，支持<，<=，>，>=，+，+=，-，-=，-，[]

算法形参模式

在任何其他算法分类之上，还有一组参数规范。

alg(beg, end, other args);
alg(beg, end, dest, other args);
alg(beg, end, beg2, other args);
alg(beg, end, beg2, end2, other args);

其中beg和end指定了一个输入范围，beg2和end2指定了第二个输入范围，alg是算法名，other args是算法的其他参数，dest参数是一个迭代器，指定了一个输出位置。


#### 算法命名规范

一些算法使用重载形式传递一个谓词

_if 版本的算法

接受一个元素的算法通常有另一个不同名的版本，该版本接受一个谓词，代替元素值

```cpp
find(beg, end, val); // 返回第一个等于val的元素的迭代器
find_if(beg, end, pred); // 返回第一个令pred为true的元素的迭代器
```
区分拷贝元素的版本和不拷贝的版本

```cpp
remove_if(beg, end, pred); // 删除满足pred的元素，不拷贝
remove_copy_if(beg, end, dest, pred); // 删除满足pred的元素，拷贝到dest
```

#### 特定容器算法

链表类型 list 和 forward_list 提供了自己的算法，它们定义了独有的 sort merge remove reverse 和 unique

链表类型还定义了 splice

链表的特有操作会改变容器


## 11 关联容器

关联容器和顺序容器有着根本的不同：关联容器中的元素是按关键字米保存和访问的。与之相对，顺序容器中的元素是按它们在容器中的位置来顺序保存和访问的。

虽然关联容器的很多行为与顺序容器相同，但其不同之处反映了关键字的作用。



允许重复关键字的容器的名字中都包含单词multi:不保持关键字按顺序存储的容器的名字都以单词unordered开头。

因此一个unordered multi set是一个允许重复关键字，元素无序保存的集合，而一个 set则是一个要求不重复关键字，有序存储的集合。

#### map 关联数组

map是一种关联容器，它包含一对关键字和值，关键字起到索引的作用，值则表示与索引相关联的数据。

##### 使用 map

```cpp
map<string, size_t> word_count; // 空容器
string word;
while (cin >> word)
    ++word_count[word]; // 计数器加1

for (const auto &w : word_count) // 打印结果
    cout << w.first << " occurs " << w.second << " times" << endl;
```

##### 使用 set

```cpp
map<string, size_t> word_count; // 空容器
set<string> exclude = {"the", "but", "and", "or", "an", "a",
                       "The", "But", "And", "Or", "An", "A"};
string word;
while (cin >> word) 
    if (exclude.find(word) == exclude.end())   // 就是没找到
        ++word_count[word]; // 计数器加1

```

find 调用返回一个迭代器。如果给定关键字在set中，迭代器指向该关键字。否则，find返回尾后迭代器。在此程序中，仅当word不在exclude中时我们才更新word的计数器。


##### 关联容器概述

注意 关联容器不支持顺序操作 比如 push_back push_front

1. 定义关联容器

    ```cpp
    map<string, size_t> word_count; // 空容器  map 需要指名关键字类型和值类型
    set<string> exclude = {"the", "but", "and", "or", "an", "a",
                        "The", "But", "And", "Or", "An", "A"}; // set 只需要指名关键字类型

    ```

2. 关键字类型的要求

    有序容器：严格弱序

    无序容器：哈希函数和等价性运算符

3. 使用关键字类型的比较函数

    有序容器：可以指定自己的比较函数

    无序容器：可以指定自己的哈希函数和等价性运算符

4. pair 类型

    pair 在 utility 头文件中定义

    ```cpp
    pair<string, string> author{"James", "Joyce"};
    pair<string, string> author = make_pair("James", "Joyce");
    ```

    一个Pair保存两个数据成员。类似容器，pair是一个用来生成特定类型的模板。当创建一个pair时，我们必须提供两个类型名，pair的数据成员将具有对应的类型。两个类型不要求一样：

    pair 的数据成员是 public 的，可以直接访问

    ```cpp
    pair<string, int> word_count;
    cout << word_count.first; // 访问关键字
    cout << word_count.second; // 访问值
    ```
    
    map 的元素是 pair 类型

#### 关联容器操作

##### 关联容器迭代器

当解引用一个关联容器迭代器时，我们会得到一个类型为容器的value_type的值的引用。对于map，value_type是一个pair类型，对于set，value_type就是关键字类型。

```cpp
map<string, size_t> word_count;
for (auto it = word_count.begin(); it != word_count.end(); ++it)
    cout << it->first << " occurs " << it->second << " times" << endl;
++ (*it).second; // 等价于 ++it->second 可以修改值
```

set 的迭代器是 const 的，不能改变值

遍历关联容器

```cpp
// 获得一个迭代器，指向第一个元素
auto map_it = word_count.cbegin(); // map 的迭代器是 const 的
// 只要map_it 没到尾后迭代器，就一直递增它
while (map_it != word_count.cend()) {
    // 解引用迭代器，输出元素
    cout << map_it->first << " occurs " << map_it->second << " times" << endl;
    ++map_it; // 递增迭代器
}
```

##### 添加元素

```cpp
word_count.insert({word, 1}); // 插入一个元素
word_count.insert(make_pair(word, 1)); // 插入一个元素
word_count.insert(pair<string, size_t>(word, 1)); // 插入一个元素
word_count.insert(map<string, size_t>::value_type(word, 1)); // 插入一个元素
```

##### 删除元素

```cpp
word_count.erase(iter); // 删除迭代器指定的元素 返回删除的元素的个数
word_count.erase(key); // 删除关键字为key的元素 返回删除的元素的个数
word_count.erase(beg, end); // 删除迭代器指定的范围的元素 返回删除的元素的个数
```

##### map 的下标操作

set 不支持下标操作


```cpp
word_count[word] = 1; // 如果word不在word_count中，下标操作会添加一个具有关键字word的元素，关联值进行值初始化
++word_count[word]; // 如果word已经在word_count中，下标操作返回一个引用，通过引用我们可以修改元素的值
//at
word_count.at(word) = 1; // 如果word不在word_count中，at会抛出一个out_of_range异常
++word_count.at(word); // 如果word已经在word_count中，at返回一个引用，通过引用我们可以修改元素的值
```

##### 访问元素

```cpp
//find
auto map_it = word_count.find(word); // 返回一个迭代器，指向关键字为word的元素，如果word不在容器中，返回尾后迭代器
// 使用find代替下标操作 可以避免插入元素
if (word_count.find("Anna") == word_count.end())
    cout << "Anna is not in the map" << endl;
else
    cout << "Anna is in the map" << endl;
```
一种不同的，面向迭代器的解决方法 lower_bound 和 upper_bound 如果关键字存在，lower_bound返回一个迭代器，指向第一个等于给定关键字的元素；upper_bound返回一个迭代器，指向第一个大于给定关键字的元素。如果关键字不存在，两个函数都返回一个迭代器，指向关键字可以插入的位置。

```cpp
auto map_it = word_count.lower_bound(word); // 返回一个迭代器，指向第一个关键字不小于word的元素
auto map_it = word_count.upper_bound(word); // 返回一个迭代器，指向第一个关键字大于word的元素
auto map_it = word_count.equal_range(word); // 返回一个迭代器pair，表示关键字等于word的元素的范围

//equal_range
auto map_it = word_count.equal_range(word);
if (map_it.first == map_it.second)
    cout << "word " << word << " not found" << endl;
else
    cout << "word " << word << " occurs " << map_it.second - map_it.first << " times" << endl;


    //find 代替下标操作
    if (word_count.find("Anna") == word_count.end())
        cout << "Anna is not in the map" << endl;
    else
        cout << "Anna is in the map" << endl;
```

multimap 和 multiset  find 
    
```cpp
string search_item("Alain de Botton"); // 作者
auto entries = authors.count(search_item); // 作者为search_item的书的数量
auto iter = authors.find(search_item); // 指向第一本书 迭代器
// 用一个循环查找所有作者为search_item的书
while (entries) {
    cout << iter->second << endl; // 打印每本书的书名
    ++iter; // 前进到下一本书
    --entries; // 该作者的作品数减1
}
```

面向迭代器的解决方法

```cpp
for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg)
    cout << beg->second << endl; // 打印每本书的书名
```

equal_range 函数

```cpp

for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
    cout << pos.first->second << endl; // 打印每本书的书名
```


##### 一个单词转换的map

```cpp
void word_transform(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap(mapfile) //保存转换规则
    string text;
    while(getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while(stream >> word){
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);

        }
        cout << endl;
    }


}
map<string, string> buildMap(ifstream &map_file){
    map<string, string> transmap; //保存转换规则
    string key; // 要转换的单词
    string value; // 替换后的内容
    // 读取第一个单词存入key中，行中剩余内容存入value
    while(map_file >> key && getline(map_file, value))
        if (value.size() > 1) // 检查是否有转换规则
            transmap[key] = value.substr(1); // 跳过前导空格
        else
            throw runtime_error("no rule for " + key);
    return transmap;
} 

const string &transform(const string &s, const map<string, string> &m){
    // 实际的转换工作，这个函数是单词转换的核心
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second; // 使用替换短语
    else
        return s; // 返回原string
}

```

函数首先调用buildMap来生成单词转换map,我们将它保存在trans_map中。函数的剩余部分处理输入文件。while循环用get1ine一行一行地读取输入文件。这样做的目的是使得输出中的换行位置能和输入文件中一样。为了从每行中获取单词，我们使用了一个嵌套的while循环，它用一个istringstream(参见8.3节，第287页)来处理当前行中的每个单词。

在输出过程中，内层while循环使用一个bool变量firstword来确定是否打印一个空格。它通过调用transform米获得要打印的单词。transform的返回值或者是 word中原来的string,或者是trans map中指出的对应的转换内容。


### 无序容器

无序容器使用哈希函数来组织元素，这些元素可以快速地根据关键字来查找。与关联容器不同，无序容器中的元素是无序存储的。

无序容器在存储上组织为一组桶，每个桶保存零个或多个元素。无序容器使用一个哈希函数将元素映射到桶。无序容器中的元素是不按任何顺序保存的，因此无序容器不支持顺序性相关的操作，比如关联容器中的lower_bound和upper_bound操作。

无序容器管理操作

```cpp
// 桶接口
c.bucket_count(); // 返回当前使用的桶的数量
c.max_bucket_count(); // 返回容器可容纳的最大桶的数量
c.bucket_size(n); // 返回第n个桶中的元素数
c.bucket(k); // 返回关键字等于k的元素所在的桶的编号
// 桶迭代
local_iterator  // 桶内迭代器类型
const_local_iterator // 桶内迭代器类型
c.begin(n); // 返回第n个桶的首迭代器
c.end(n); // 返回第n个桶的尾后迭代器
c.cbegin(n); // 返回第n个桶的首迭代器
c.cend(n); // 返回第n个桶的尾后迭代器
// 哈希策略
c.load_factor(); // 返回容器中平均每个桶的元素数
c.max_load_factor(); // 返回容器允许的最大负载因子
c.rehash(n); // 重组存储，使得桶的数量至少为n
c.reserve(n); // 重组存储，使得能保存n个元素而不必重新哈希
```


## 12 动态内存

### 动态内存与智能指针

```cpp
new int; // 分配一个未初始化的动态分配对象，返回指向该对象的指针
new int(1024); // 分配一个值为1024的动态分配对象，返回指向该对象的指针
int *p1 = new int; // p1指向一个动态分配的、未初始化的、无名对象
int *p2 = new int(); // p2指向一个动态分配的、值初始化为0的无名对象
string *ps1 = new string; // 默认初始化的string
delete p1; // 释放p1指向的对象
```

**智能指针**

与普通指针的区别： 智能指针用于管理动态对象，它能自动释放对象。
 
```cpp
shared_ptr<int> p1; // shared_ptr可以指向一个int型对象 多个shared_ptr 可以指向同一个对象

unique_ptr<string> p2(new string("hello")); // unique_ptr独占所指向的对象
unique_ptr<string> p3(p2.release()); // p3接管了p2的指针

weak_ptr<int> wp(p1); // weak_ptr是一种不控制所指向对象生存期的智能指针，它指向一个由shared_ptr管理的对象
```
#### shared_ptr

```cpp
shared_ptr<int> p1; // shared_ptr可以指向一个int型对象 多个shared_ptr 可以指向同一个对象
shared_ptr<list<int>> p2; // shared_ptr可以指向一个int型对象 多个shared_ptr 可以指向同一个对象
```

**空值判断**
    
```cpp
if (p1) // 如果p1指向一个对象
if (p1 == nullptr) // 如果p1为空
if (p1 != p2) // 如果p1和p2指向不同的对象
```

**shared_ptr 支持的操作**

```cpp
make_shared<T>(args); // 返回一个shared_ptr，指向一个动态分配的类型为T的对象，使用args初始化此对象
shared_ptr<T> p(q); // p是shared_ptr q的拷贝，此操作会递增q中的计数器
p = q; // p和q都是shared_ptr，所指向的对象必须能转换为T*，此操作会递增q中的计数器，递减p中的计数器
p.unique(); // 如果p是唯一指向其对象的shared_ptr，则返回true
p.use_count(); // 返回与p共享对象的智能指针数量
```

**make_shared 函数**

最安全的分配和使用动态内存的方法是调用一个名为make_shared的标准库函数。

```cpp
shared_ptr<int> p3 = make_shared<int>(42); // 指向一个值为42的int
shared_ptr<string> p4 = make_shared<string>(10, '9'); // 指向一个值为9999999999的string
shared_ptr<int> p5 = make_shared<int>(); // 指向一个值初始化的int，即值为0
```

shared_ptr 的拷贝和赋值

```cpp
auto p = make_shared<int>(42); // p指向的对象只有p一个引用者
auto q(p); // p和q指向相同对象，此对象有两个引用者
auto r = make_shared<int>(42); // r指向的对象只有r一个引用者
r = q; // 递增q指向对象的引用计数，递减r指向对象的引用计数  r 指向 p 指向的对象
```

shared_ptr 的拷贝和赋值会递增右侧运算对象的引用计数，递减左侧运算对象的引用计数。当引用计数变为0时，shared_ptr会自动释放自己管理的对象。

shared_ptr 自动销毁所管理的对象 还会自动释放相关的内存

如果你将shared_ptr存放于一个容器中，而后不再需要使用该容器的全部或部分元素，你可以使用erase成员来删除那些你不再需要的元素。erase成员会自动销毁元素，因此它会递减每个元素的引用计数。当一个元素的引用计数变为0时，shared_ptr类会自动释放内存。

**使用了动态生存期的资源的类**

原因

1. 程序不知道自己需要使用多少对象
2. 程序不知道所需对象的准确类型
3. 程序需要在多个对象间共享数据


#### 直接管理内存

**new 和 delete 运算符**

```cpp
int *pi = new int; // pi指向一个动态分配的、未初始化的、无名对象
int *pi = new int(); // pi指向一个动态分配的、值初始化为0的无名对象
auto p1 = new auto(obj); // p1指向一个动态分配的对象，该对象的类型与obj的类型相同
auto p2 = new auto{a, b, c}; // p2指向一个动态分配的对象，该对象是由a、b、c初始化得来的
auto p3 = new auto(a, b, c); // 错误：括号中只能有单个初始化器
```

**动态分配的const对象**

```cpp
const int *pci = new const int(1024); // 分配一个动态分配的const int
const string *pcs = new const string; // 分配一个动态分配的const string
```

**内存耗尽**

```cpp
int *p1 = new int; // 如果分配失败，new抛出std::bad_alloc异常
int *p2 = new (nothrow) int; // 如果分配失败，new返回一个空指针  
```

**释放动态内存**

```cpp
delete p; // p必须指向一个动态分配的对象或者是一个空指针
delete [] pa; // pa必须指向一个动态分配的数组或者是一个空指针
```

**指针和delete**

```cpp
int i, *pi1 = &i, *pi2 = nullptr;
double *pd = new double(33), *pd2 = pd;
delete i; // 错误：i不是指针
delete pi1; // 未定义：pi1指向的不是动态分配的内存
delete pd; // 正确：pd指向一个动态分配的对象
delete pd2; // 未定义：指针pd2指向的内存已经被释放了
delete pi2; // 正确：删除一个空指针总是安全的
```

**动态对象的生存期直到被释放时为止**

**由内置指针（而不是智能指针）管理的动态内存的对象，在被显式释放之前一直存在。**

动态内存的管理非常容易出错，常见问题如下
1. 忘记释放内存
2. 使用已经释放的对象
3. 同一块内存释放多次

**delete 之后重置指针值 这只是提供了有限的保护**

```cpp
int *p(new int(42)); // p指向动态分配的对象
auto q = p; // q指向p所指向的对象
delete p; // 但p和q都是未定义的，因为它们指向的对象已经被释放了
p = nullptr; // 将p重置为指向空对象
```

#### shared_ptr 和 new 结合使用

```cpp
shared_ptr<double> p1; // shared_ptr可以指向一个double型对象
shared_ptr<int> p2(new int(42)); // p2指向一个值为42的int
// 不能将一个内置指针直接赋予一个智能指针
shared_ptr<int> p3 = new int(1024); // 错误：不能将int*隐式转换为shared_ptr<int>
shared_ptr<int> p4(new int(1024)); // 正确：使用直接初始化形式
```

**不要混合使用普通指针和智能指针**

**也不要使用get初始化另一个智能指针或为另一个智能指针赋值**


#### 智能指针和异常

```cpp
void f(){
    shared_ptr<int> sp(new int(42)); // sp指向的对象只有sp一个引用者
    // 在f内部发生异常，且没有捕获
 }//在函数结束时，sp被销毁，它指向的对象也被销毁

void f(){
    int *ip = new int(42); // ip指向动态分配的对象
    // 在f内部发生异常，且没有捕获
    delete ip; // ip指向的对象不会被销毁
}//在函数结束时，ip被销毁，但它指向的对象没有被销毁
```

**使用我们自己的释放操作**

```cpp
void end_connection(connection *p){
    disconnect(*p);
}

void f(destination &d){
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    // 使用连接
    // 当f退出时，即使通过异常退出，连接也会被正确关闭
}
```




智能指针的规范
1. 不使用相同的内置指针值初始化（或reset）多个智能指针
2. 不delete get()返回的指针
3. 不使用get()初始化或reset另一个智能指针
4. 如果你使用get()返回的指针，记住当最后一个对应的智能指针销毁后，你的指针就变为无效了
5. 如果你使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器


#### unique_ptr

```cpp
unique_ptr<double> p1; // unique_ptr可以指向一个double型对象
unique_ptr<int> p2(new int(42)); // p2指向一个值为42的int
// unique_ptr不支持普通的拷贝或赋值操作
unique_ptr<int> p3(p2); // 错误：不能拷贝unique_ptr
unique_ptr<int> p4;
p4 = p2; // 错误：不能赋值unique_ptr

// 可以使用release或reset将指针的所有权从一个（非const）unique_ptr转移给另一个unique_ptr
unique_ptr<string> p2(p1.release()); // release将p1置空，将它指向的string的内存管理权转移给p2
unique_ptr<string> p3(new string("hello"));
p2.reset(p3.release()); // reset释放了p2原来指向的内存，将其指向p3原来指向的内存
```

传递unique_ptr参数和返回unique_ptr

```cpp
unique_ptr<int> clone(int p){
    //正确：使用int*显式初始化unique_ptr<int>
    return unique_ptr<int>(new int(p));
}

```

向unique_ptr传递删除器

```cpp
unique_ptr<objT, delT> p(new objT, fcn);

void f(destination &d){
    connection c = connect(&d);
    unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
    // 使用连接
    // 当f退出时，即使通过异常退出，连接也会被正确关闭
}

// p(&c, end_connection);：这是创建一个 std::unique_ptr 的实例 p，将连接对象的地址 &c 以及连接对象的析构函数 end_connection 提供给它。
```

#### weak_ptr

特点  1. 指向shared_ptr管理的对象 2. 不控制所指向对象的生存期（即使shared_ptr销毁了对象，weak_ptr也可以继续指向对象）

```cpp
auto p = make_shared<int>(42);
weak_ptr<int> wp(p); // wp weak_ptr指向p所指向的对象

// weak_ptr的操作
wp.expired(); // 如果wp.use_count()为0，返回true，否则返回false
wp.lock(); // 返回一个shared_ptr，指向weak_ptr所指向的对象，对象已经被销毁，返回一个空shared_ptr
wp.reset(); // 将wp置空
```

### 动态数组

#### new 和 数组

初始化动态分配的数组

```cpp
int *pia = new int[10]; // 10个未初始化的int
int *pia2 = new int[10](); // 10个值初始化为0的int
string *psa = new string[10]; // 10个空string
string *psa2 = new string[10](); // 10个空string
int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9}; // 列表初始化
string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')}; // 列表初始化
```
动态分配一个空数组是合法的

```cpp
int *pia = new int[n]; // n是一个动态确定的值
int *pia2 = new int[get_size()]; // get_size是一个返回值的函数
```

释放动态数组

```cpp
delete [] p; // p必须指向一个动态分配的数组或者是一个空指针
```

**WARNING**

如果delete忘记加[]，编译器不会报错，则只会释放数组的第一个元素，其他元素的内存会泄露

智能指针和动态数组

```cpp
unique_ptr<int[]> up(new int[10]); // up指向一个动态分配的int数组
up.release(); // 自动调用delete[]，释放数组内存
up.reset(new int[10]); // 自动调用delete[]，释放数组内存
```


与unique_ptr不同，shared_ptr不直接支持管理动态数组。如果需要使用shared_ptr管理一个动态数组，必须提供自己定义的删除器。

```cpp
shared_ptr<int> sp(new int[10], [](int *p){delete [] p;}); // 使用lambda来定义删除器
```

#### allocator 类

```cpp
allocator<string> alloc;
auto const p = alloc.allocate(n);
auto q = p; // q指向最后构造的元素之后的位置
// 构造元素
alloc.construct(q++); // *q为空字符串
alloc.construct(q++, 10, 'c'); // *q为cccccccccc
alloc.construct(q++, "hi"); // *q为hi
cout << *p << endl; // 输出空字符串
while (q != p)
    alloc.destroy(--q); // 释放构造的元素  只能销毁构造的元素

```

拷贝和填充未初始化的内存

```cpp
auto p = alloc.allocate(vi.size() * 2); // 分配比vi大两倍的内存空间
auto q = uninitialized_copy(vi.begin(), vi.end(), p); // 拷贝vi中的元素到p指向的空间中
uninitialized_fill_n(q, vi.size(), 42); // 用42填充剩余空间
```


### 使用标准库：文本查询程序



```cpp
class QueryResult; // 前向声明
//TextQuery类负责保存输入文件并且查询
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type; // 行号
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const; // 查询函数 const的作用是不修改数据成员
private:
    std::shared_ptr<std::vector<std::string>> file; // 输入文件
    // 每个单词到它所在的行号的集合的映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
//TextQuery类的构造函数
TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
    std::string text;
    while (getline(is, text)) { // 对文件中每一行
        file->push_back(text); // 保存此行文本  push_back 向vector中添加一个元素
        int n = file->size() - 1; // 当前行号
        std::istringstream line(text); // 将行文本分解为单词
        std::string word;
        while (line >> word) { // 对行中每个单词
            // 如果单词不在wm中，以之为下标在wm中添加一项
            auto &lines = wm[word]; // lines是一个shared_ptr
            if (!lines) // 在我们第一次遇到这个单词时，此指针为空
                lines.reset(new std::set<line_no>); // 分配一个新的set
            lines->insert(n); // 将此行号插入set中
        }
    }
}

// QueryResult类负责保存查询结果并且打印
class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&); // 友元函数 用于打印结果
public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) { }
private:
    std::string sought; // 查询单词
    std::shared_ptr<std::set<line_no>> lines; // 出现的行号
    std::shared_ptr<std::vector<std::string>> file; // 输入文件
};

QueryResult TextQuery::query(const std::string &sought) const {
    // 如果未找到sought，我们将返回一个指向此set的指针
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    // 使用find而不是下标运算符来查找单词，避免将单词添加到wm中
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); // 未找到
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    // 如果找到了单词，打印出现次数和所有出现的位置
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
    // 打印单词出现的每一行
    for (auto num : *qr.lines) // 对set中每个单词
        // 避免行号从0开始给用户带来的困惑
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
    return os;
}

```
## 第三部分 类设计者的工具
## 13 拷贝控制


