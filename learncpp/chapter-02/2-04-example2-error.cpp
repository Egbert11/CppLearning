// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：printDouble() 直接引用 main() 中的 num，但 num 在这个函数里不可见，无法编译。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: 'num' was not declared in this scope
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example2-error.cpp -o a   （会报错，属预期）

#include <iostream>

void printDouble() // This function won't compile: it can't see num
{
    std::cout << num << " doubled is: " << num * 2 << '\n';
}

int main()
{
    int num{};
    std::cout << "Enter an integer: ";
    std::cin >> num;

    printDouble(); // this call doesn't help, num is still not visible inside printDouble()

    return 0;
}
