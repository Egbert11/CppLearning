// 来源小节：9.2 Code coverage
// 示例说明：循环覆盖率示例——用 0、1、2 三种迭代次数调用 printTimes()，
//           演示 "0, 1, 2 test"：若 2 次正确，更多次也应正确。
// 原文链接：https://www.learncpp.com/cpp-tutorial/code-coverage/
//
// 编译：g++ -std=c++20 -Wall 9-02-example4.cpp -o a
// 预期输出：
//   (0 次迭代时无输出，随后换行)
//   Spam!
//   Spam! Spam!
//
// 本节代码为按原文描述重建。

#include <iostream>

void printTimes(int timesToPrint)
{
    for (int count{ 0 }; count < timesToPrint; ++count)
        std::cout << "Spam! ";
}

int main()
{
    // 0, 1, 2 test for loops
    printTimes(0); // zero iterations
    std::cout << '\n';
    printTimes(1); // one iteration
    std::cout << '\n';
    printTimes(2); // two iterations
    std::cout << '\n';

    return 0;
}
