// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：const std::array 的元素不可修改，即使没有显式给元素加 const。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期错误：编译错误——assignment of read-only location（元素为 const）。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>

int main()
{
    const std::array<int, 5> prime { 2, 3, 5, 7, 11 };

    prime[4] = 13; // compile error: can't modify a const std::array

    return 0;
}
