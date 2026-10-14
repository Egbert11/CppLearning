// 来源小节：F.3 Constexpr functions (part 3) and consteval
// 示例说明：consteval 函数必须在编译期求值，用运行期实参调用会报错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-3-and-consteval/
//
// 预期错误：greater() 是 consteval（immediate function），
//   用非 constexpr 的 x 调用它会编译失败。g++ 报错类似：
//   error: call to consteval function 'greater(int, int)' is not a constant expression
//
// 说明：本文件为按原文描述重建，故意保留编译错误，请勿修复。
//       本文件预期编译失败。
#include <iostream>

consteval int greater(int x, int y) // function is now consteval
{
    return (x > y ? x : y);
}

int main()
{
    constexpr int g { greater(5, 6) };            // ok: evaluated at compile-time
    std::cout << g << " is greater!\n";

    std::cout << greater(5, 6) << " is greater!\n"; // ok: evaluated at compile-time

    int x{ 5 }; // not constexpr
    std::cout << greater(x, 6) << " is greater!\n"; // compile error: can't be evaluated at runtime

    return 0;
}
