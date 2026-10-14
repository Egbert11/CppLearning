// 来源小节：21.1 Introduction to operator overloading
// 示例说明：内置的 operator+ (double)。对 w + z 而言，重载解析在 int 版与 double 版之间
//           选择了 double 版（因为两个操作数都是 double）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/
// 说明：原文该片段不带 main，此处按规范包进 main() 以便编译；片段边界见注释。
// 预期输出：5

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    double z { 2.0 };
    double w { 3.0 };
    std::cout << w + z << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
