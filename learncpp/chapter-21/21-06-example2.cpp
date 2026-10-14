// 来源小节：21.6 Overloading unary operators +, -, and !
// 示例说明：逻辑非 ! 的常见用法（内置 bool 版本），作为重载 operator! 的铺垫。
//           本片段未涉及自定义类型，只是演示 ! 的语义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-unary-operators/
// 说明：原文该片段不带 main，此处按规范包进 main() 以便编译；片段边界见注释。
// 预期输出：I am not happy!

#include <iostream>

int main()
{
    bool isHappy { false };

    // --- 原文示例片段 ---
    if (!isHappy)
        std::cout << "I am not happy!\n";
    else
        std::cout << "I am so happy!\n";
    // --- 原文示例片段结束 ---

    return 0;
}
