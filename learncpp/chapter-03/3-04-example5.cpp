// 来源小节：3.4 Basic debugging tactics
// 示例说明：修复版——补上 getValue() 的调用括号后，重跑可见 getValue 确实被调用了。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 预期输出：
//   main() called
//   getValue() called
//   4

#include <iostream>

int getValue()
{
std::cerr << "getValue() called\n";
    return 4;
}

int main()
{
std::cerr << "main() called\n";
    std::cout << getValue() << '\n'; // added parenthesis here

    return 0;
}
