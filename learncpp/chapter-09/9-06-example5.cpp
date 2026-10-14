// 来源小节：9.6 Assert and static_assert
// 示例说明：一个不具描述性的断言 assert(found); 及其产生的信息——只知道失败，
//           却不知道失败指的是什么。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example5.cpp -o a
// 说明：这里模拟"查找失败"的情形，found 为 false，运行到断言时异常终止。
//       预期信息形如：
//       Assertion failed: found, file C:\VCProjects\Test.cpp, line 34
// 警告：本程序运行到断言处会异常终止（非零退出），属预期行为。
//
// 本节代码为按原文描述重建。

#include <cassert>  // for assert
#include <iostream>

int main()
{
    // Pretend we searched a database and did not find anything
    bool found{ false };

    assert(found); // not very descriptive

    std::cout << "Found the car\n";

    return 0;
}
