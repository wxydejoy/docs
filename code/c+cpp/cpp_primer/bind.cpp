/*** 
 * @Author: weiekko weiekko@gmail.com
 * @Date: 2023-06-06 10:48:55
 * @LastEditors: weiekko weiekko@gmail.com
 * @LastEditTime: 2023-06-06 10:48:58
 * @FilePath: \docs\code\c+cpp\cpp_primer\bind.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by weiekko weiekko@gmail.com, All Rights Reserved. 
 */
#include <iostream>
#include <functional>

void foo(int a, int b, int c)
{
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}

int main()
{
    auto f1 = std::bind(foo, 1, 2, 3);
    f1(); // 输出：a = 1, b = 2, c = 

    auto f2 = std::bind(foo, std::placeholders::_1, std::placeholders::_2, 4);
    f2(5, 6); // 输出：a = 5, b = 6, c = 4

    return 0;
}
