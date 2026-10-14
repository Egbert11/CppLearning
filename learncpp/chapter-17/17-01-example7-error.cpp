// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：初始化列表个数多于数组长度是编译错误；少于长度时剩余元素被值初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期错误：编译错误——too many initializers for 'std::array<int, 4>'。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>

int main()
{
    std::array<int, 4> a { 1, 2, 3, 4, 5 }; // compile error: too many initializers
    std::array<int, 4> b { 1, 2 };          // b[2] and b[3] are value initialized

    [[maybe_unused]] auto check = b[3];

    return 0;
}
