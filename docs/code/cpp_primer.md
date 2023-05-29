<!--
 * @Author: weiekko weiekko@gmail.com
 * @Date: 2023-05-29 22:33:22
 * @LastEditors: weiekko weiekko@gmail.com
 * @LastEditTime: 2023-05-29 23:08:21
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

