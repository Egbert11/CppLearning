// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：初始化列表中的值多于数组长度是编译错误；少于长度时剩余元素被
//           值初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期错误：编译错误——too many initializers for 'int [4]'。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
int main()
{
    int a[4] { 1, 2, 3, 4, 5 }; // compile error: too many initializers
    int b[4] { 1, 2 };          // b[2] and b[3] are value initialized

    return a[0] + b[3];
}
