// ============================================================
// 来源小节：12.1 Introduction to compound data types
// 示例说明：把两个分数相乘，每个分数用两个独立的 int（分子/分母）
//           表示。变量之间的配对只靠注释和上下文暗示，代码本身
//           没有任何机制把 num1 与 den1 绑定成一个整体——这正是
//           需要复合类型的动机。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-compound-data-types/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // Our first fraction
    int num1 {};
    int den1 {};

    // Our second fraction
    int num2 {};
    int den2 {};

    char ignore {}; // used to ignore the '/' character

    std::cout << "Enter a fraction: ";
    std::cin >> num1 >> ignore >> den1;

    std::cout << "Enter a fraction: ";
    std::cin >> num2 >> ignore >> den2;

    std::cout << "The two fractions multiplied: " << num1 * num2 << '/' << den1 * den2 << '\n';

    return 0;
}

// 预期交互与输出（交叉相乘）：
// Enter a fraction: 1/2
// Enter a fraction: 3/4
// The two fractions multiplied: 3/8
