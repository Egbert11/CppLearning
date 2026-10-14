// 来源小节：F.4 Constexpr functions (part 4)
// 示例说明：constexpr/consteval 函数内部可以使用并修改非 const 的形参与局部变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-4/
//
// 预期输出：
//   12
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       原文未给出输出，此处由计算推得：doSomething(5,6) -> x=7, z=13, x>y 故 z=12。
#include <iostream>

consteval int doSomething(int x, int y) // function is consteval
{
    x = x + 2;       // we can modify the value of non-const function parameters

    int z { x + y }; // we can instantiate non-const local variables
    if (x > y)
        z = z - 1;   // and then modify their values

    return z;
}

int main()
{
    // --- 原文示例片段 ---
    constexpr int g { doSomething(5, 6) };
    std::cout << g << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
