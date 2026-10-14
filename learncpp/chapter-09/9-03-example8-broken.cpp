// 来源小节：9.3 Common semantic errors in C++
// 示例说明：用 == 比较浮点数不可靠——累加得到的 d 与 1.0 因舍入误差不相等。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example8-broken.cpp -o a
// 预期输出：not equal
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。

#include <iostream>

int main()
{
    double d{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should be 1.0

    if (d == 1.0) // oops: floating point equality comparison
        std::cout << "equal\n";
    else
        std::cout << "not equal\n";

    return 0;
}
