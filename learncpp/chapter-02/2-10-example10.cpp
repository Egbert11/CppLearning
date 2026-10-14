// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 10 —— 宏在预处理指令内部不会被替换：
//           #ifdef PRINT_JOE 中的 PRINT_JOE 保持原样（不会被替换成空）。预期输出：Joe
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example10.cpp -o a

#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

    return 0;
}
