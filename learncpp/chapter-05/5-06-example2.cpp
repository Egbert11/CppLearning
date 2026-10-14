// 来源小节：5.6 Constexpr variables
// 示例说明：初始化器来自变量或函数调用时，无法从声明本身一眼看出该 const 变量能否用于常量表达式，
//           必须回溯初始化器的定义才能确定。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-variables/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建。
// 预期输出：
//   5 3

#include <iostream>

int getValue()
{
    return 3;
}

int main()
{
    int someVar { 5 };

    const int d { someVar };    // could be a constant expression or not, depending on someVar
    const int e { getValue() }; // could be a constant expression or not, depending on getValue()

    std::cout << d << ' ' << e << '\n';

    return 0;
}
