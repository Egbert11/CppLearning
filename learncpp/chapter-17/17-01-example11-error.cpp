// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：CTAD 不能只省略长度或只省略类型——必须两个模板实参都给出或都
//           由初始化列表推导（截至 C++23 仍如此）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期错误：编译错误——wrong number of template arguments (1, should be 2)。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>

int main()
{
    constexpr std::array<int> a1 { 9, 7, 5, 3, 1 }; // error: too few template arguments (length not provided)
    constexpr std::array<5> a2 { 9, 7, 5, 3, 1 };   // error: too few template arguments (type not provided)

    return 0;
}
