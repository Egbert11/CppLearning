// 来源小节：20.7 Lambda captures
// 示例说明：在捕获子句里定义并初始化一个新变量（捕获初始化）：
//           [userArea{ width * height }]，其类型由初始化器推导，值在 lambda 定义时计算一次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// Best practice：只在该值很短、且类型显而易见时才在捕获里初始化变量；
//               否则先把变量定义在外面再捕获它。
// 预期输出：Area found :)

#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> areas{ 100, 36, 100, 25, 81 };

    int width{ 5 };
    int height{ 5 };

    // --- 原文示例片段 ---
    // We can define and initialize a variable to be captured by the lambda
    auto found{ std::find_if(areas.begin(), areas.end(),
                             [userArea{ width * height }](int knownArea) { // capture @userArea, initialized with @width * @height
                                 return userArea == knownArea;
                             }) };
    // --- 原文示例片段结束 ---

    if (found == areas.end())
        std::cout << "I don't know this area :(\n";
    else
        std::cout << "Area found :)\n";

    return 0;
}
