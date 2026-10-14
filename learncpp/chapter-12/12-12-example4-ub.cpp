// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：与非 static 局部变量形成对比。programName 在函数返回时被销毁，
//           返回对它的引用会产生悬垂引用；使用该引用是未定义行为。
//           编译器通常对此类简单情形给出警告或错误（gcc 会报
//           -Wreturn-local-addr）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// !! -ub：未定义行为演示，可编译（gcc 会给出警告）。
// 备注：本节代码为按原文描述忠实重建（原 Example 4）。
// ============================================================
#include <iostream>
#include <string>

const std::string& getProgramName() // will return a const reference
{
    const std::string programName { "Calculator" }; // local, destroyed at end of function

    return programName; // undefined behavior: returns a dangling reference
}

int main()
{
    std::cout << "This program is named " << getProgramName() << '\n'; // undefined behavior

    return 0;
}
