// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：改用内联的 lambda（匿名函数）完成同样的查找：
//           函数定义就写在使用它的地方，不需要名字，也不污染全局命名空间。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// lambda 语法：[captureClause](parameters) -> returnType { statements; }
//   捕获子句可省略；参数表可为空或省略（除非写了返回类型）；返回类型可选（默认 auto）。
// 预期输出：Found walnut

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // --- 原文示例片段 ---
    // Define the function right where we use it.
    auto found{ std::find_if(arr.begin(), arr.end(),
                             [](std::string_view str) // here's our lambda, no capture clause
                             {
                                 return str.find("nut") != std::string_view::npos;
                             }) };
    // --- 原文示例片段结束 ---

    if (found == arr.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found << '\n';

    // A trivial lambda: [] {}; (no captures, no parameters, omitted return type)
    auto trivial{ [] {} };
    trivial();

    return 0;
}
