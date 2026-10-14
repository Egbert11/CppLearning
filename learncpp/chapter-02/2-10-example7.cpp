// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 7 —— 用 #if 0 把一段代码排除在编译之外（Bob、Steve 都不会被编译）。
//           预期输出：Joe
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example7.cpp -o a

#include <iostream>

int main()
{
    std::cout << "Joe\n";

#if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    std::cout << "Steve\n";
#endif // until this point

    return 0;
}
