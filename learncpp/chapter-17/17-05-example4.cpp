// ============================================================
// 来源小节：17.5 Arrays of references via std::reference_wrapper
// 示例说明：C++17 之前没有 CTAD，必须显式写出模板实参来创建
//           std::reference_wrapper，写法冗长。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建，原文片段包进 main() 并用
//       "--- 原文示例片段 ---" 标出边界。
// ============================================================
#include <functional>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };

    std::reference_wrapper<int> ref1 { x };        // C++11
    auto ref2 { std::reference_wrapper<int>{ x }}; // C++11
    // --- 原文示例片段 ---

    std::cout << ref1 << ref2 << '\n'; // prints 55

    return 0;
}
