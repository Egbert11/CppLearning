// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：参数 count 在函数体里从未被使用，会触发未使用参数的警告。
//           预期编译警告：
//           warning: unused parameter 'count' [-Wunused-parameter]
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-example11-warning.cpp -o a   （应出现 -Wunused-parameter 警告）

#include <iostream>

void doSomething(int count) // warning: unreferenced parameter count
{
}

int main()
{
    doSomething(5);

    return 0;
}
