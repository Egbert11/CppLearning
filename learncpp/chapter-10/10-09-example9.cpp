// 来源小节：10.9 Type deduction for functions
// 示例说明：当返回类型依赖参数类型时，常规位置写不出来（编译器还没看到 x、y 的定义），
//           必须使用尾置返回语法。decltype(x) 求值为 x 的类型。
//           （对应原文示例 9）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example9.cpp -o a
// 预期输出：7.5
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits> // for std::common_type_t

// --- 原文示例片段 ---
// 常规位置写法会失败：
//   std::common_type_t<decltype(x), decltype(y)> add(int x, double y); // Compile error: compiler hasn't seen definitions of x and y yet

// 尾置返回写法可行：
auto add(int x, double y) -> std::common_type_t<decltype(x), decltype(y)>; // ok
// --- 原文示例片段结束 ---

// decltype(x)=int, decltype(y)=double -> common_type_t<int, double> = double
auto add(int x, double y) -> std::common_type_t<decltype(x), decltype(y)>
{
    return x + y;
}

int main()
{
    std::cout << add(3, 4.5) << '\n'; // 7.5
    return 0;
}
