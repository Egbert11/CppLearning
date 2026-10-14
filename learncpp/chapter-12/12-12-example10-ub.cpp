// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：从一个悬垂引用复制。getProgramName() 返回对非 static 局部的
//           引用；用该引用初始化 std::string name 时，复制自一个已经悬垂的
//           引用，仍是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// !! -ub：未定义行为演示，可编译（gcc 会给出警告）。
// 备注：本节代码为按原文描述忠实重建（原 Example 10）。
// ============================================================
#include <iostream>
#include <string>

const std::string& getProgramName() // will return a const reference
{
    const std::string programName{ "Calculator" }; // local, destroyed at end of function

    return programName;
}

int main()
{
    std::string name { getProgramName() }; // makes a copy of a dangling reference
    std::cout << "This program is named " << name << '\n'; // undefined behavior

    return 0;
}
