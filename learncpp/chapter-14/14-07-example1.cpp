// ============================================================
// 来源小节：14.7 Member functions returning references to data members
// 示例说明：非成员函数返回两个引用参数中按字母序靠前者——安全的按引用返回。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>

// --- 原文示例片段（原 Example 1）---
// Takes two std::string objects, returns the one that comes first alphabetically
const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
    return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

int main()
{
    std::string hello { "Hello" };
    std::string world { "World" };

    std::cout << firstAlphabetical(hello, world); // either hello or world will be returned by reference

    return 0;
}

// 预期输出：
// Hello
