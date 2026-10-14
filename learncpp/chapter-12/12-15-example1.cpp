// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：一个普通的按值返回函数，用来引出“y 可能为 0”的错误处理问题。
//           函数本身不处理错误，需要把错误情况交回调用方。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 1）。
//       原文只给出该函数的定义，这里补一个 main 以便独立编译。
// ============================================================
#include <iostream>

int doIntDivision(int x, int y)
{
    return x / y; // y == 0 is not handled here
}

int main()
{
    std::cout << doIntDivision(20, 5) << '\n';

    return 0;
}
