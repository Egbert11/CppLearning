// ============================================================
// 来源小节：13.4 Converting an enumeration to and from a string
// 示例说明：默认情况下枚举按整数打印——因为没有针对 Color 的 operator<<，
//           编译器把枚举隐式转成整数，输出 2 而不是 blue。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

enum Color
{
    black, // 0
    red,   // 1
    blue,  // 2
};

int main()
{
    Color shirt{ blue };

    std::cout << "Your shirt is " << shirt << '\n';

    return 0;
}

// 预期输出：
// Your shirt is 2
