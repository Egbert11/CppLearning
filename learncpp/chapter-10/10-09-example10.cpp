// 来源小节：10.9 Type deduction for functions
// 示例说明：函数形参上的 auto。C++20 之前这是编译错误；C++20 下可以编译，但这里的
//           auto 触发的是函数模板（而非"类型推导"）。（对应原文示例 10）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example10.cpp -o a
// 预期输出：
//   5
//   11.2
//
// 本节代码为按原文描述重建。原文说明：pre-C++20 该代码无法编译；
// C++20 起可编译，因为形参 auto 等价于函数模板。

#include <iostream>

// --- 原文示例片段 ---
void addAndPrint(auto x, auto y)
{
    std::cout << x + y << '\n';
}
// --- 原文示例片段结束 ---

int main()
{
    addAndPrint(2, 3);     // 调用同一模板的两个实例化：int, int -> 5
    addAndPrint(4.5, 6.7); // double, double -> 11.2
    return 0;
}
