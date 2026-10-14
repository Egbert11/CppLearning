// 来源小节：9.3 Common semantic errors in C++
// 示例说明：无限循环——while 循环漏写了自增语句，条件永远为真，反复打印 1。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example3-broken.cpp -o a
// 预期输出：不断打印 "1 "，永不结束（需手动终止程序）。
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。
// 警告：本程序不会自行结束，请勿直接运行（或运行后用 Ctrl-C 终止）。

#include <iostream>

int main()
{
    int count{ 1 };

    while (count <= 10) // this condition will never be false
    {
        std::cout << count << ' '; // so this line happens over and over
    }

    return 0;
}
