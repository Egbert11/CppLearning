// 来源小节：7.7 External linkage and variable forward declarations
// 示例说明：外部全局变量的定义——非 const 默认外部；extern + 初始化式使 const 也变外部。
//           （对应原文 Example 5 的 a.cpp，配合 Example 4 的 main.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
//
// 多文件示例，编译：g++ -std=c++20 -Wall 7-07-example4/*.cpp

// global variable definitions
int g_x { 2 };              // non-constant globals have external linkage by default
extern const int g_y { 3 }; // this extern gives g_y external linkage
