// 来源小节：2.3 Void functions (non-value returning functions)
// 示例说明：void 函数中多余的 return; —— 函数本来就会在末尾返回，所以这句 return 是冗余的。
//           预期输出：Hi
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-03-example2.cpp -o a

#include <iostream>

void printHi()
{
    std::cout << "Hi" << '\n';

    return; // redundant because function would return at the end anyway

    // This function does not return a value so no return statement is needed
}

int main()
{
    printHi(); // okay: function return value is void (no value is returned)

    return 0;
}
