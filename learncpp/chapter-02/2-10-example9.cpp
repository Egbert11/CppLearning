// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 9 —— 把 #if 0 改成 #if 1（恒真），Bob、Steve 又被重新编译。
//           预期输出：Joe / Bob / Steve（各占一行）
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example9.cpp -o a

#include <iostream>

int main()
{
    std::cout << "Joe\n";

#if 1 // always true, so the following code will be compiled
    std::cout << "Bob\n";
    /* Some
     * multi-line
     * comment here
     */
    std::cout << "Steve\n";
#endif

    return 0;
}
