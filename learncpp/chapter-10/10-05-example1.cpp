// 来源小节：10.5 Arithmetic conversions
// 示例说明：int + double 的常规算术转换——int 操作数被转成 double，结果类型也是
//           double。用 <typeinfo> 的 typeid 打印各表达式类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-05-example1.cpp -o a
// 注：typeid().name() 的输出是实现相关的。原文（作者机器）输出：
//       int
//       double
//       double 5.5
//     GCC 下类型名会显示为简写（如 'i'、'd'），数值部分一致（5.5）。
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <typeinfo> // for typeid()

int main()
{
    // --- 原文示例片段 ---
    int i{ 2 };
    double d{ 3.5 };

    std::cout << typeid(i).name() << '\n';
    std::cout << typeid(d).name() << '\n';

    // int 2 will be converted to double 2.0, then added to 3.5 => 5.5
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
