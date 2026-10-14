// 来源小节：7.5 Variable shadowing (name hiding)
// 示例说明：全局变量被局部变量遮蔽时，可用无前缀的作用域运算符 :: 访问全局变量：
//           --(::value) 递减的是全局 value。（对应原文 Example 4）
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/
//
// 预期输出：
//   local variable value: 8
//   global variable value: 4
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int value { 5 }; // global variable

void foo()
{
    std::cout << "global variable value: " << value << '\n';
}

int main()
{
    int value { 7 }; // hides the global variable value

    ++value; // increments local value, not global value
    --(::value); // decrements global value, not local value (parentheses for clarity)

    std::cout << "local variable value: " << value << '\n';

    foo();

    return 0;
}
