// 来源小节：7.4 Introduction to global variables
// 示例说明：常量全局变量（const / constexpr）必须初始化；两者都能被各函数使用。
//           （对应原文 Example 4，其中必须初始化的错误行已单独放入 7-04-example4-error.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/
//
// 预期输出：
//   1
//   2
//   1
//   2
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

// const int g_x;     // error: constant variables must be initialized
// constexpr int g_w; // error: constexpr variables must be initialized

const int g_y { 1 };     // const global variable g_y, initialized with a value
constexpr int g_z { 2 }; // constexpr global variable g_z, initialized with a value

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';
}

int main()
{
    doSomething();

    // global variables can be seen and used everywhere in the file
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';

    return 0;
}
// g_y and g_z go out of scope here
