// ============================================================
// 来源小节：17.4 std::array of class types, and brace elision
// 示例说明：对"简单标量"元素，单层花括号就够用；而同一数组用双层花括号也
//           照样接受——花括号省略（brace elision）规则允许省略一部分花括号。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision/
// 预期输出：1 2 3 4 5
//            1 2 3 4 5
// 备注：本节代码为按原文描述重建。注意 CTAD 不能与双层花括号一起用，
//       双层写法必须显式给出模板实参。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array<int, 5> arr { 1, 2, 3, 4, 5 };   // single braces: fine for scalars
    constexpr std::array<int, 5> arr2 {{ 1, 2, 3, 4, 5 }}; // double braces: also accepted

    for (auto e : arr)
        std::cout << e << ' ';
    std::cout << '\n';

    for (auto e : arr2)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}
