// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：本文件覆盖原文示例 4（三种参数个数的函数定义）与示例 5（三种调用形式）。
//           预期输出：
//           In doPrint()
//           6
//           9
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example4.cpp -o a

#include <iostream>

// This function takes no parameters
// It does not rely on the caller for anything
void doPrint()
{
    std::cout << "In doPrint()\n";
}

// This function takes one integer parameter named x
// The caller will supply the value of x
void printValue(int x)
{
    std::cout << x  << '\n';
}

// This function has two integer parameters, one named x, and one named y
// The caller will supply the value of both x and y
int add(int x, int y)
{
    return x + y;
}

int main()
{
    // --- 原文示例片段 ---
    doPrint();     // this call has no arguments
    printValue(6); // this call has one argument, named 6
    std::cout << add(2, 3) << '\n'; // this call has two arguments, named 2 and 3
    // --- 原文示例片段结束 ---

    return 0;
}
