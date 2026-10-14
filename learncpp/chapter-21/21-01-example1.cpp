// 来源小节：21.1 Introduction to operator overloading
// 示例说明：内置的 operator+ (int)。表达式 x + y 等价于函数调用 operator+(x, y)，
//           编译器为 int 选择了内置的整型加法版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/
// 说明：原文该片段不带 main，此处按规范包进 main() 以便编译；片段边界见注释。
// 预期输出：5

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 2 };
    int y { 3 };
    std::cout << x + y << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
