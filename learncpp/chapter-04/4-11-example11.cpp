// 来源小节：4.11 Chars
// 示例说明：换行转义——单独的 '\n' 字符字面量，以及字符串内的 \n。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 预期输出：
//   The value of x is: 5
//   First line
//   Second line

#include <iostream>

int main()
{
    int x { 5 };
    std::cout << "The value of x is: " << x << '\n'; // '\n' is a standalone char literal
    std::cout << "First line\nSecond line\n";        // '\n' embedded in a double-quoted string

    return 0;
}
