// 来源小节：4.8 Floating point numbers
// 示例说明：对比整数与浮点字面量的书写（5 / 5.0 / 5.0f，以及 0 / 0.0）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
// 说明：本文件为重建代码；变量未使用，编译时可能出现 unused variable 警告。

int main()
{
    // --- 原文示例片段 ---
    int a { 5 };          // 5 means integer
    double b { 5.0 };     // 5.0 is a floating point literal (no suffix means double type by default)
    float c { 5.0f };     // 5.0 is a floating point literal, f suffix means float type

    int d { 0 };          // 0 is an integer
    double e { 0.0 };     // 0.0 is a floating point literal
    // --- 原文示例片段 ---

    return 0;
}
