// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：Quiz #1 —— multiply() 的返回类型写成了 void，却又想返回 x * y。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: return-statement with a value, in function returning 'void'
//           正确写法应是把返回类型改成 int。
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-quiz1-error.cpp -o a   （会报错，属预期）

#include <iostream>

void multiply(int x, int y)
{
    return x * y; // compile error: cannot return a value from a void function
}

int main()
{
    std::cout << multiply(4, 5) << '\n';

    return 0;
}
