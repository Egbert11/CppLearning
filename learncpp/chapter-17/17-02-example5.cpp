// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：语言缺陷——对"按 (const) 引用传递的 std::array 函数形参"调用
//           std::size()/size()/ssize() 会返回非 constexpr 值，从而使
//           `constexpr int length{ std::size(arr) };` 报错；而 main 里对
//           真正的数组对象做同样的事却没问题。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：length: 5
//            length: 5
// 备注：该缺陷已由 C++23 的 P2280 修复。GCC 15.2（本仓库所用）已支持，
//       故本文件能正常编译——在较老的编译器上 printLength 内那行会报错。
//       变通办法见 17-02-example6.cpp。
// ============================================================
#include <array>
#include <iostream>

void printLength(const std::array<int, 5>& arr)
{
    constexpr int length{ std::size(arr) }; // compile error on pre-P2280 compilers!
    std::cout << "length: " << length << '\n';
}

int main()
{
    std::array arr { 9, 7, 5, 3, 1 };
    constexpr int length{ std::size(arr) }; // works just fine
    std::cout << "length: " << length << '\n';

    printLength(arr);

    return 0;
}
