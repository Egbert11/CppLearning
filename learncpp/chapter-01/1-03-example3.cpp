// 来源小节：1.3 Introduction to objects and variables
// 示例说明：定义一个变量、在同一语句里定义多个同类型变量，并用注释保留两种错误写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-objects-and-variables/
//
// 说明：这些变量仅被定义、未赋值，程序不读取它们的值（读取未初始化变量是未定义行为）。
// 编译时 g++ -Wall 会给出 "unused variable" 警告，符合本节示例本意。

int main()
{
    // --- 原文示例片段：两条独立的定义语句，等价于下面合并成一条的写法 ---
    int a;
    int b;
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：一条语句定义两个同类型变量 ---
    int c, d;
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：错误的写法（原文示例，无法编译，故以注释保留）---
    // int e, int f;       // wrong (compiler error): 重复写类型
    // int g, double h;    // wrong (compiler error): 一条语句里混用类型
    // --- 原文示例片段结束 ---

    // correct (but not recommended)
    int i;
    double j;

    return 0;
}
