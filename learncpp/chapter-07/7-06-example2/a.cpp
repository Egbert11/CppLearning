// 来源小节：7.6 Internal linkage
// 示例说明：内部链接的名字在不同翻译单元里是独立实体。a.cpp 的 g_x 与 main.cpp 的 g_x
//           同名但互不冲突（各自只有一个定义，不破坏 ODR）。（对应原文 Example 2 的 a.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/internal-linkage/
//
// 多文件示例，编译：g++ -std=c++20 -Wall 7-06-example2/*.cpp

[[maybe_unused]] constexpr int g_x { 2 }; // this internal g_x is only accessible within a.cpp
