// 来源小节：7.7 External linkage and variable forward declarations
// 示例说明：用 extern（不带初始化式）对另一文件里定义的外部变量做前向声明，然后访问它们。
//           （对应原文 Example 4 的 main.cpp，配合 Example 5 的 a.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
//
// 预期输出：2 3

#include <iostream>

extern int g_x;       // forward declaration of a variable named g_x that is defined somewhere else
extern const int g_y; // forward declaration of a const variable named g_y that is defined somewhere else

int main()
{
    std::cout << g_x << ' ' << g_y << '\n'; // prints 2 3

    return 0;
}
