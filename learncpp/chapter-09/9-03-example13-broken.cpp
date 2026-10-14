// 来源小节：9.3 Common semantic errors in C++
// 示例说明：漏写函数调用运算符 ()——只写函数名得到函数指针，它转换为 bool 的 true
//           并打印为 1（部分编译器上打印的是地址）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example13-broken.cpp -o a
// 预期输出：1
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。

#include <iostream>

int getValue()
{
    return 5;
}

int main()
{
    std::cout << getValue << '\n'; // oops: missing () - prints 1 (or a memory address)

    return 0;
}
