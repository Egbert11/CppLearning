// ============================================================
// 来源小节：13.1 Introduction to program-defined (user-defined) types
// 示例说明：定义简单的复合类型（compound type）：函数、指针、引用、数组。
//           这些类型由已知的类型名/符号拼出，无需额外定义或导入。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/
// 备注：本节代码为按原文描述忠实重建。原文里的 x 在别处定义，这里补上；
//       并为无用的指针/数组加 [[maybe_unused]] 以消除警告。
// ============================================================
void fcn(int) {}; // define a function of type void(int)

int main()
{
    int x { 5 };

    // --- 原文示例片段 ---
    [[maybe_unused]] int* ptr;      // define variable of compound type 'pointer to int'
    [[maybe_unused]] int& ref { x }; // define variable of compound type 'reference to int' (initialized with x)
    [[maybe_unused]] int arr[5];     // define an array of 5 integers of type int[5] (we'll cover this in a future chapter)
    // --- 原文示例片段结束 ---

    return 0;
}
