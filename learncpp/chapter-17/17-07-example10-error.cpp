// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：const C 风格数组的元素不可修改。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期错误：编译错误——assignment of read-only location 'prime[0]'。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
int main()
{
    const int prime[5] { 2, 3, 5, 7, 11 };

    prime[0] = 17; // compile error: can't modify a const array

    return prime[0];
}
