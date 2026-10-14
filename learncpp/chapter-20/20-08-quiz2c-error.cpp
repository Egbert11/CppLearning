// 来源小节：20.x Chapter 20 summary and quiz（Quiz 2c）
// 示例说明：两个 divide() 重载名字相同、参数列表也相同，只有返回类型不同，
//           因此不是有区别的重载（重定义错误）。另外还可能除以 0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz/
// 预期错误：error: ambiguating new declaration of 'double divide(float, float)'
//           （GCC 会提示重定义/冲突声明）
// 说明：本节代码为按原文描述重建。请勿修复，此文件故意无法编译。

// --- 原文示例片段 ---
float divide(float x, float y)
{
    return x / y;
}

double divide(float x, float y) // same name and parameters as above -> not distinct
{
    return x / y;
}
// --- 原文示例片段结束 ---

int main()
{
    return 0;
}
