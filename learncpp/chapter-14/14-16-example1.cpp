// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：隐式数值转换——printDouble 形参是 double，传入 int 5 时编译器
//           自动把 5 转换为 5.0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
void printDouble(double d) // has a double parameter
{
    std::cout << d;
}

int main()
{
    printDouble(5); // we're supplying an int argument

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// 5
