// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：C++23 起用 std::to_underlying（来自 <utility>）把有作用域枚举转成
//           其底层类型，比 static_cast<int> 更准确、更推荐。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 构建：g++ -std=c++23 -Wall（std::to_underlying 是 C++23 特性）
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <utility> // for std::to_underlying

enum class Color
{
    black,
    red,
    blue,
};

int main()
{
    Color color { Color::red };

    std::cout << std::to_underlying(color) << '\n'; // prints 1

    return 0;
}

// 预期输出：
// 1
