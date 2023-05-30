<!--
 * @Author: weiekko weiekko@gmail.com
 * @Date: 2023-05-29 22:33:22
 * @LastEditors: weiekko weiekko@gmail.com
 * @LastEditTime: 2023-05-30 13:47:17
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
