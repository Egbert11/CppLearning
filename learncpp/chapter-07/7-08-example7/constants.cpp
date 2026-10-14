// 来源小节：7.8 Why (non-const) global variables are evil
// 示例说明：不推荐的做法——让常量具有外部链接，供其它文件直接访问（对应原文 Example 7 的 constants.cpp）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
//
// 多文件示例，编译：g++ -std=c++20 -Wall 7-08-example7/*.cpp

// constants.cpp
extern const double gravity { 9.8 }; // has external linkage, can be accessed by other files
