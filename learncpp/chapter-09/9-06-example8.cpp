// 来源小节：9.6 Assert and static_assert
// 示例说明：用 #define NDEBUG 在某个翻译单元中禁用断言——必须放在任何 #include 之前，
//           且行尾不加分号。于是 assert(false) 不会触发。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example8.cpp -o a
// 预期输出：Hello, world!
//
// 本节代码为按原文描述重建。

#define NDEBUG // disable asserts (must be placed before any #includes)
#include <cassert>
#include <iostream>

int main()
{
    assert(false); // won't trigger since asserts have been disabled in this translation unit

    std::cout << "Hello, world!\n";

    return 0;
}
