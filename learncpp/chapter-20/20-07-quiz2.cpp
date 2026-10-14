// 来源小节：20.7 Lambda captures（Quiz 2）
// 示例说明：默认按值捕获 [=] 捕获的是变量的副本；之后在 main 里修改 favoriteFruit
//           不会影响已经捕获的副本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 预期输出：I like grapes（而不是 pineapples）

#include <iostream>
#include <string>

int main()
{
    std::string favoriteFruit{ "grapes" };

    // --- 原文示例片段 ---
    // [=] captures all used variables by value
    auto printFavoriteFruit{ [=]() {
        std::cout << "I like " << favoriteFruit << '\n';
    } };
    // --- 原文示例片段结束 ---

    favoriteFruit = "pineapples"; // the captured copy is unaffected

    printFavoriteFruit();

    return 0;
}
