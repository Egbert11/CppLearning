// ============================================================
// 来源小节：5.1 Constant variables (named constants)
// 示例说明：const 变量的初始化式可以是非常量（运行期才知道的值）。
//           输入一个年龄，用该非常量初始化一个 const 变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int constAge { age }; // initialize const variable using non-const value

    age = 5;         // ok: age is non-const, we can change its value
    // constAge = 6; // error: constAge is const, we can't change its value
    // --- 原文示例片段结束 ---

    std::cout << "age is now: " << age << '\n';
    std::cout << "constAge stays: " << constAge << '\n';

    return 0;
}
