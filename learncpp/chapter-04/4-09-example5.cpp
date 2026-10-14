// 来源小节：4.9 Boolean values
// 示例说明：使用 std::boolalpha，让布尔值打印为 true / false。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/
// 预期输出：
//   1
//   0
//   true
//   false

#include <iostream>

int main()
{
    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << true << '\n';
    std::cout << false << '\n';

    return 0;
}
