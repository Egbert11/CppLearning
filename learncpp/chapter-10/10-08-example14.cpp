// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：类型"漂移"——auto 变量 sum 的类型随表达式参与者的类型改变而改变。
//           这里 add 返回 int、gravity 是 int 时 sum 是 int；把两者改为 double，
//           sum 便自动变成 double。（对应原文示例 17）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example14.cpp -o a
// 预期输出：
//   int
//   double
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <typeinfo>

int addInt(int x, int y) { return x + y; }
double addDouble(double x, double y) { return x + y; }

int main()
{
    // --- 原文示例片段 ---
    int gravityInt{ 9 };
    auto sumInt{ addInt(5, 6) + gravityInt }; // sumInt 推导为 int

    double gravityDouble{ 9.8 };
    auto sumDouble{ addDouble(5, 6) + gravityDouble }; // sumDouble 推导为 double
    // --- 原文示例片段结束 ---

    std::cout << typeid(sumInt).name() << '\n';    // 'i'（int）
    std::cout << typeid(sumDouble).name() << '\n'; // 'd'（double）

    return 0;
}
