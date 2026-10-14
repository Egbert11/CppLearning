// ============================================================
// 来源小节：13.12 Member selection with pointers and references
// 示例说明：混用指针与非指针——指针用 ->，普通成员用 .。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>

struct Paw
{
    int claws{};
};

struct Animal
{
    std::string name{};
    Paw paw{};
};

int main()
{
    Animal puma{ "Puma", { 5 } };

    Animal* ptr{ &puma };

    // ptr is a pointer, use ->
    // paw is not a pointer, use .

    // --- 原文示例片段（原 Example 7）---
    std::cout << (ptr->paw).claws << '\n';

    return 0;
}

// 预期输出：
// 5
