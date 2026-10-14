// 来源小节：2.7 Forward declarations and definitions
// 示例说明：函数声明（函数原型）—— 只有返回类型、函数名、参数类型和分号，没有函数体。
//           预期输出：The sum of 3 and 4 is: 7
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example3.cpp -o a

#include <iostream>

// --- 原文示例片段 ---
int add(int x, int y); // function declaration includes return type, name, parameters, and semicolon.  No function body!
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
