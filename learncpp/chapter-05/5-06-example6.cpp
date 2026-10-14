// 来源小节：5.6 Constexpr variables
// 示例说明：对比普通函数 max() 与 constexpr 函数 cmax()。cmax() 可用于常量表达式，
//           max() 不可以（`constexpr int m3 { max(5, 6) };` 是编译错误）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-variables/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建。
// 原示例中 `constexpr int m3 { max(5, 6) };` 是【编译错误】，为让本文件可通过编译，
// 该行以注释保留（见下方）。取消注释即会重现编译错误。
// 预期输出：
//   6 6 6 6 6

#include <iostream>

int max(int x, int y) // this is a non-constexpr function
{
    return (x > y) ? x : y;
}

constexpr int cmax(int x, int y) // this is a constexpr function
{
    return (x > y) ? x : y;
}

int main()
{
    int m1 { max(5, 6) };             // ok
    const int m2 { max(5, 6) };       // ok
    // constexpr int m3 { max(5, 6) }; // compile error: max(5, 6) not a constant expression  <-- 取消注释将无法编译

    int m4 { cmax(5, 6) };            // ok: can evaluate at compile time or runtime
    const int m5 { cmax(5, 6) };      // ok
    constexpr int m6 { cmax(5, 6) };  // ok: cmax(5, 6) is a constant expression

    std::cout << m1 << ' ' << m2 << ' ' << m4 << ' ' << m5 << ' ' << m6 << '\n';

    return 0;
}
