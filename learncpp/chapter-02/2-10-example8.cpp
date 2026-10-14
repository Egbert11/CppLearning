// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 8 —— 用 #if 0 包裹含有块注释（/* */）的代码。
//           多行注释不能嵌套，所以要用 #if 0 才能把这类代码注释掉。预期输出：Joe
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example8.cpp -o a

#include <iostream>

int main()
{
    std::cout << "Joe\n";

#if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    /* Some
     * multi-line
     * comment here
     */
    std::cout << "Steve\n";
#endif // until this point

    return 0;
}
