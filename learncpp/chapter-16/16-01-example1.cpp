// ============================================================
// 来源小节：16.1 Introduction to containers and arrays
// 示例说明：std::string 本身就是一个字符容器；容器有名字，元素没有名字，
//           可以把整个字符串作为一串字符一次性输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-containers-and-arrays/
// 预期输出：Alex
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" }; // strings are a container for characters
    std::cout << name; // output our string as a sequence of characters

    return 0;
}
