// 来源小节：10.9 Type deduction for functions
// 示例说明：尾置返回提升复杂返回类型的可读性。常规写法里函数名淹没在类型中；
//           尾置写法可先看函数名与参数，不在意返回类型时可跳过。
//           （对应原文示例 7）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example7.cpp -o a
// 预期输出：7.5
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits> // for std::common_type_t

// --- 原文示例片段 ---
std::common_type_t<int, double> compare(int, double); // harder to read (where is the name of the function in this mess?)
auto compare(int x, double y) -> std::common_type_t<int, double>; // easier to read
// --- 原文示例片段结束 ---

// 为可运行而补上定义（语义与原文一致）
auto compare(int x, double y) -> std::common_type_t<int, double>
{
    return x > y ? x : y;
}

int main()
{
    std::cout << compare(3, 7.5) << '\n'; // 7.5
    return 0;
}
