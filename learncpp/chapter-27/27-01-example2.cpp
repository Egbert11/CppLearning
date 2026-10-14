// ============================================================
// 来源小节：27.1 The need for exceptions
// 示例说明：一个"急需错误处理"的除法函数——若 y 为 0，整数除以 0 是未定义
//           行为（会崩溃）。原文用它引出：仅靠返回值无法表达"出错了"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-need-for-exceptions/
// 预期输出：1.66667
// 备注：函数体逐字取自原文；main 为便于编译运行而补充，这里只传合法的 y=3。
//       若改为 divide(5, 0)，static_cast<double>(x)/y 会得到 inf；若用整数
//       除法除以 0 则是未定义行为（-ub），故此处不演示崩溃路径。
// ============================================================
#include <iostream>

double divide(int x, int y)
{
    return static_cast<double>(x)/y;
}

int main()
{
    std::cout << divide(5, 3) << '\n'; // 1.66667

    return 0;
}
