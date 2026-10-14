// 来源小节：2.x Chapter 2 summary and quiz（官方编号 2.x）
// 题目 2：把 readNumber() 和 writeAnswer() 移到单独的 io.cpp 中，
//        main() 通过前置声明来调用它们。
// 示例说明：io.cpp —— 两个函数的定义所在文件（因为用到 I/O，需要 #include <iostream>）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/

#include <iostream>

int readNumber()
{
    std::cout << "Enter a number to add: ";
    int x {};
    std::cin >> x;

    return x;
}

void writeAnswer(int x)
{
    std::cout << "The answer is " << x << '\n';
}
