/*** 
 * @Author: weiekko weiekko@gmail.com
 * @Date: 2023-06-08 08:30:02
 * @LastEditors: weiekko weiekko@gmail.com
 * @LastEditTime: 2023-06-08 08:40:25
 * @FilePath: \docs\code\c+cpp\leetcode\T3.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by weiekko weiekko@gmail.com, All Rights Reserved. 
 */
#include <iostream>
//时间
#include <ctime>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    string temp;
    int ftemp = 0;
    for(int i = s.length(); i > 0; i--)
    {
        if (temp.find(s[s.length() - i]) > temp.length()) // 无重复  temp.find(s[s.length() - i]) == -1 但会很大 所以
        {
            // 无重复
            temp.push_back(s[s.length() - i]);
            ftemp = temp.length() > ftemp ? temp.length() : ftemp;
        }
        else
        {
            // 有重复
            i += (temp.length() - temp.find(s[s.length() - i]) - 1);
            temp.clear();
            temp.push_back(s[s.length() - i]);
            ftemp = temp.length() > ftemp ? temp.length() : ftemp;
        }
    }
    return ftemp;
}
int main()
{
    string s;
    clock_t start, finish;
    double duration;
    start = clock();


    //循环1000次
    for (size_t i = 0; i < 1000; i++)
    {
        /* code */
        
    s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    s = "bbbbb";
    cout << lengthOfLongestSubstring(s) << endl;
    s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;
    s = "dawdacxzwd";
    cout << lengthOfLongestSubstring(s) << endl;
    }
    




    // 计算运行时间
    finish = clock();
    // double duration;
    // start = clock();
    // finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << endl;
    return 0;
}