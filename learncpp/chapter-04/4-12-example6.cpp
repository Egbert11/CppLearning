// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：打印 char 得到的是字符而非数字。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 预期输出：a

#include <iostream>

int main()
{
    char ch{ 97 }; // 97 is ASCII code for 'a'
    std::cout << ch << '\n';

    return 0;
}
