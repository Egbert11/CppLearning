// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：用 static_cast<int> 打印 char 的整数值（变量本身不受影响）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 预期输出：a has value 97

#include <iostream>

int main()
{
    char ch{ 97 }; // 97 is ASCII code for 'a'
    // print value of variable ch as an int
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n';

    return 0;
}
