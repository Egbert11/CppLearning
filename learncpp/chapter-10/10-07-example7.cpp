// 来源小节：10.7 Typedefs and type aliases
// 示例说明：用别名简化复杂的类型 std::vector<std::pair<std::string, int>>，使函数
//           形参与局部变量都更好读、更不容易打错。（对应原文示例 12、13）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example7.cpp -o a
// 预期输出：1
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <string>
#include <utility>
#include <vector>

// 未使用别名时的冗长写法（原文示例 12）：
//   bool hasDuplicates(std::vector<std::pair<std::string, int>> pairlist);

// --- 原文示例片段（使用别名，原文示例 13） ---
using VectPairSI = std::vector<std::pair<std::string, int>>; // make VectPairSI an alias

bool hasDuplicates(VectPairSI pairlist) // use VectPairSI in a function parameter
{
    for (std::size_t i{ 0 }; i < pairlist.size(); ++i)
        for (std::size_t j{ i + 1 }; j < pairlist.size(); ++j)
            if (pairlist[i] == pairlist[j])
                return true;
    return false;
}
// --- 原文示例片段结束 ---

int main()
{
    VectPairSI pairlist{ { "a", 1 }, { "b", 2 }, { "a", 1 } };
    std::cout << std::boolalpha << hasDuplicates(pairlist) << '\n'; // true

    return 0;
}
