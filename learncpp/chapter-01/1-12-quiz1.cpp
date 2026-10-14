// 来源小节：1.x Chapter 1 summary and quiz（官方编号 1.x）
// 题目：第 1 题——初始化（initialization）与赋值（assignment）有什么区别？
// 解答：初始化是在创建对象时给出初始值；赋值是之后改变一个已存在对象的值。
//       创建只发生一次，所以初始化只发生一次；而赋值可以发生任意多次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-1-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 1-12-quiz1.cpp -o quiz1

#include <iostream>

int main()
{
    int x{ 5 };  // 初始化：x 在创建的同时获得初始值 5（初始化只发生这一次）
    std::cout << x << '\n';

    x = 10;      // 赋值：改变已存在对象 x 的值（赋值可以重复进行）
    std::cout << x << '\n';

    x = 15;      // 再次赋值
    std::cout << x << '\n';

    return 0;
}
