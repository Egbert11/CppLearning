// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：Quiz #2 —— multiply() 有两个缺陷：
//           1) 它需要两个参数，但 main() 只传了一个实参（编译错误）；
//           2) 函数体里没有 return 语句（非 void 函数缺返回值，未定义行为 + 警告）。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: too few arguments to function 'int multiply(int, int)'
//           warning: control reaches end of non-void function [-Wreturn-type]
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-quiz2-error.cpp -o a   （会报错，属预期）

#include <iostream>

int multiply(int x, int y)
{
    // missing return statement
}

int main()
{
    std::cout << multiply(4) << '\n'; // too few arguments, and result is undefined

    return 0;
}
