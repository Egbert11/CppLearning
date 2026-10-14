// ============================================================
// 来源小节：16.1 Introduction to containers and arrays
// 示例说明：用 std::string::length() 得到容器的元素个数（长度）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-containers-and-arrays/
// 预期输出：Alex has 4 characters
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" };
    std::cout << name << " has " << name.length() << " characters\n";

    return 0;
}
