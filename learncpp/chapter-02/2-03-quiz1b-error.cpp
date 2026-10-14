// 来源小节：2.3 Void functions (non-value returning functions)
// 示例说明：Quiz 1b —— 把一个 void 函数的调用当作值交给 std::cout，无法编译。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: no match for 'operator<<' (operand types are 'std::ostream' and 'void')
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-03-quiz1b-error.cpp -o a   （会报错，属预期）

#include <iostream>

void printA()
{
    std::cout << "A\n";
}

int main()
{
    // compile error: printA() returns void, which can't be sent to std::cout
    std::cout << printA() << '\n';

    return 0;
}
