// ============================================================
// 来源小节：17.5 Arrays of references via std::reference_wrapper
// 示例说明：C++17 起 CTAD 可直接推导出模板实参；但 std::ref()/std::cref()
//           因为更短，仍然流行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper/
// 预期输出：5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <functional>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    std::reference_wrapper ref1 { x };        // C++17
    auto ref2 { std::reference_wrapper{ x }}; // C++17
    // --- 原文示例片段 ---

    std::cout << ref1 << '\n'; // prints 5

    return 0;
}
