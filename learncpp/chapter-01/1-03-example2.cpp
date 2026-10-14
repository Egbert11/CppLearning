// 来源小节：1.3 Introduction to objects and variables
// 示例说明：定义一个变量（int x;），并给出它出现在完整程序中的形式；同时演示定义 double 变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-objects-and-variables/
//
// 说明：此处变量仅被"定义"、并未赋值，因此本程序不读取它们的值（读取未初始化变量是未定义行为）。
// 编译时 g++ -Wall 会给出 "unused variable" 警告——这正符合本节"只定义、未使用"的示例本意。

int main()
{
    // --- 原文示例片段 ---
    int x; // define a variable named x (of type int)
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：完整程序中的变量定义 ---
    // int main() { int x; // definition of variable x ... }
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：定义 double 类型的变量 ---
    double width; // define a variable named width, of type double
    // --- 原文示例片段结束 ---

    return 0;
}
