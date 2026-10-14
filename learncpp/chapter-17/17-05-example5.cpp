// ============================================================
// 来源小节：17.5 Arrays of references via std::reference_wrapper
// 示例说明：std::ref() 创建 std::reference_wrapper，std::cref() 创建
//           std::reference_wrapper<const T>；配合 auto 可免去写出模板实参。
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
    auto ref { std::ref(x) };   // C++11, deduces to std::reference_wrapper<int>
    auto cref { std::cref(x) }; // C++11, deduces to std::reference_wrapper<const int>
    // --- 原文示例片段 ---

    std::cout << ref << '\n'; // prints 5

    return 0;
}
