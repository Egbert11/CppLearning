// 来源小节：20.x Chapter 20 summary and quiz（Quiz 2e）
// 示例说明：argv[1] 可能不存在（没有传命令行参数时会越界），
//           而且它本身是 C 风格字符串，不能直接赋值给 int。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz/
// 预期错误：error: invalid conversion from 'char*' to 'int' [-fpermissive]
// 说明：本节代码为按原文描述重建。请勿修复，此文件故意无法编译。

// --- 原文示例片段 ---
int main(int argc, char* argv[])
{
    int age{ argv[1] }; // argv[1] may not exist, and it is a string, not an int

    return 0;
}
// --- 原文示例片段结束 ---
