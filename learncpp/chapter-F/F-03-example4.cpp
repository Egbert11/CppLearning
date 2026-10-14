// 来源小节：F.3 Constexpr functions (part 3) and consteval
// 示例说明：用「非宏」的 consteval 函数模板替代 CONSTEVAL 宏，强制编译期求值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-3-and-consteval/
//
// 预期输出：
//   6
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       For advanced readers：这里用 auto 返回类型（10.9）与 auto 形参的缩写函数模板（11.8）。
//       原文提示：GCC 14 起存在 bug，开启任意优化级别时该示例可能给出错误答案。
//       本文件在 GCC 15.2 上以 -O0 与 -O2 分别验证。
#include <iostream>
#include <type_traits> // for std::is_constant_evaluated

consteval auto CONSTEVAL(auto value)
{
    return value;
}

constexpr int compare(int x, int y) // function is constexpr
{
    if (std::is_constant_evaluated())
        return x > y ? x : y; // greater in constant context
    else
        return x < y ? x : y; // lesser otherwise
}

int main()
{
    // --- 原文示例片段 ---
    std::cout << CONSTEVAL(compare(5, 6)) << '\n'; // prints 6 (always compile-time: greater)
    // --- 原文示例片段结束 ---

    return 0;
}
