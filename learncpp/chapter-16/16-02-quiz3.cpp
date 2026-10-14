// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：Quiz #3 解答——用长度构造函数创建含 365 个 double 的 vector
//           （一年每天一个温度），元素值初始化为 0.0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：365
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> temperature (365); // 365 double values, value-initialized to 0.0

    std::cout << temperature.size() << '\n';

    return 0;
}
