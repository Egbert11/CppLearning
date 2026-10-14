// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 5 —— #ifdef 条件编译：PRINT_JOE 已定义，故编译 Joe；
//           PRINT_BOB 未定义，故 Bob 被排除。预期输出：Joe
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example5.cpp -o a

#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

    return 0;
}
