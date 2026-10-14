// ============================================================
// 来源小节：6.8 Logical operators
// 示例说明：AND/OR 混用的优先级（&& 高于 ||），以及德摩根定律的等价演示。
// 原文链接：https://www.learncpp.com/cpp-tutorial/logical-operators/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    bool value1{ true };
    bool value2{ false };
    bool value3{ true };

    // && has higher precedence than ||:
    // value1 || value2 && value3 evaluates as value1 || (value2 && value3)
    bool grouped { value1 || (value2 && value3) };
    std::cout << std::boolalpha;
    std::cout << "value1 || value2 && value3 = " << grouped << '\n';

    // Preferred: explicitly parenthesize each operation
    bool mixed { (value1 && value2) || (value3 && value1) };
    std::cout << "(value1 && value2) || (value3 && value1) = " << mixed << '\n';

    // De Morgan's laws:
    //   !(x && y) == !x || !y
    //   !(x || y) == !x && !y
    // 分别打印两侧，可看到每对结果相同
    bool x{ true };
    bool y{ false };
    std::cout << "!(x && y) = " << (!(x && y)) << '\n';
    std::cout << "!x || !y  = " << (!x || !y) << '\n';
    std::cout << "!(x || y) = " << (!(x || y)) << '\n';
    std::cout << "!x && !y  = " << (!x && !y) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
