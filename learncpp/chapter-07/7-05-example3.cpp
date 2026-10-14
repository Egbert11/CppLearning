// 来源小节：7.5 Variable shadowing (name hiding)
// 示例说明：局部变量遮蔽全局变量——main 里的局部 value 隐藏了全局 value；foo() 中使用的是
//           全局 value。（对应原文 Example 3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/
//
// 预期输出：
//   local variable value: 8
//   global variable value: 5
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int value { 5 }; // global variable

void foo()
{
    std::cout << "global variable value: " << value << '\n'; // value is not shadowed here
}

int main()
{
    int value { 7 }; // hides the global variable value until the end of this block

    ++value; // increments local value, not global value

    std::cout << "local variable value: " << value << '\n';

    foo();

    return 0;
} // local value is destroyed
