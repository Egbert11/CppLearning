// 来源小节：2.11 Header files
// 示例说明：头文件应当自己 #include 它所需要的东西（这里是 std::string_view），
//           不要依赖"传递包含"（transitive include）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-files/

#include <string_view> // required to use std::string_view

std::string_view getApplicationName(); // std::string_view used here
