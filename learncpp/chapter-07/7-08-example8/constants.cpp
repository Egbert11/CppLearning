// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：封装式访问——常量保持内部链接（constexpr），通过具有外部链接的访问函数
//           getGravity() 暴露出去，实现细节可随时改动。（对应原文 Example 8 的 constants.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 多文件示例，编译：g++ -std=c++20 -Wall 7-08-example8/*.cpp

namespace constants
{
    constexpr double gravity { 9.8 }; // internal linkage, not directly accessible outside
}

// getGravity() has external linkage, can be accessed by other files
double getGravity()
{
    return constants::gravity;
}
