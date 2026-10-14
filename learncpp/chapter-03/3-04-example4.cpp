// 来源小节：3.4 Basic debugging tactics
// 示例说明：手法 #2（验证代码流程）——在函数开头加“打印函数名”的调试语句，看哪些函数真的被执行。
//           该程序仍含原文故意保留的 bug（调用 getValue 时漏写括号）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 预期输出：
//   main() called
//   1

#include <iostream>

int getValue()
{
std::cerr << "getValue() called\n"; // 临时调试语句：不缩进，便于日后定位删除
    return 4;
}

int main()
{
std::cerr << "main() called\n"; // 临时调试语句
    std::cout << getValue << '\n';

    return 0;
}
