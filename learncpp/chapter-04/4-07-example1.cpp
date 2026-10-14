// 来源小节：4.7 Introduction to scientific notation
// 示例说明：演示 C++ 中科学计数法字面量的书写与输出。
//          原文本节只讲解数值记法（如 1.2e4、5.9722e24、5e-2），没有正式的 C++ 代码块，
//          本程序是依据原文数值示例补充的演示，代码为重建。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-scientific-notation/

#include <iostream>

int main()
{
    // 1.2e4 表示 1.2 x 10^4 = 12000
    std::cout << 1.2e4 << '\n';

    // 5e-2 表示 5 x 10^-2 = 0.05
    std::cout << 5e-2 << '\n';

    // 5.9722e24 表示地球质量的量级（kg）
    std::cout << 5.9722e24 << '\n';

    // 3.14e0 与 3.14159e0：有效数字位数不同（值相同，精度不同）
    std::cout << 3.14e0 << '\n';
    std::cout << 3.14159e0 << '\n';

    return 0;
}
