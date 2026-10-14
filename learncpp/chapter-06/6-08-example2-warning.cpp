// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：! 的优先级陷阱——`! x > y` 实际解析为 `(!x) > y`，打印出错误结论。
//           本例打印 "5 is greater than 7"（错误），因为 x=5 时 !x 为 0，0 > 7 为假。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 预期警告：本示例演示的正是会产生该警告的写法（-warning 后缀），警告为预期行为，请勿消除。
// 备注：本节代码为按原文描述忠实重建。
//       预期产生 -Wlogical-not-parentheses 警告（提示 ! 只作用于比较左侧）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    int y{ 7 };

    // Intended: if x is not greater than y
    // Actual:   if (!x) > y  ->  (0) > 7  ->  false
    if (!x > y)
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n'; // prints this (wrong!)
    // --- 原文示例片段结束 ---

    return 0;
}
