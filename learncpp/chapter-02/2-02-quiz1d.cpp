// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：Quiz 1d —— 函数里先 return 5; 再 return 7;，函数在执行到第一个 return 时就结束，
//           第二个返回语句永远执行不到。
//           预期输出（两行都是 5）：
//           5
//           5
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-quiz1d.cpp -o a

#include <iostream>

int getNumbers()
{
    return 5; // execution of the function ends here, the next line is never reached
    return 7; // so this line produces no effect
}

int main()
{
    std::cout << getNumbers() << '\n'; // 5
    std::cout << getNumbers() << '\n'; // 5

    return 0;
}
