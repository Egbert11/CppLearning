// 来源小节：10.1 Implicit type conversion
// 示例说明：高级旁注（As an aside）——真正的转换会改变数值；若绕过转换、直接用
//           std::memcpy 把 int 的二进制位按 float 解读，会得到无意义的结果
//           （本例打印出 4.2039e-45）。这正说明"位模式不能照抄"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/
//
// 编译：g++ -std=c++20 -Wall 10-01-example2.cpp -o a
//       预期输出：4.2039e-45
//
// 本节代码为按原文描述重建（原文用 memcpy 的旁注示例）。

#include <cstring>
#include <iostream>

int main()
{
    // --- 原文示例片段（旁注） ---
    int i{ 3 };
    float f{};
    std::memcpy(&f, &i, sizeof(f)); // 直接复制 int 的位模式到 float，绕过类型转换

    std::cout << f << '\n'; // 4.2039e-45（把整数 3 的位按浮点解读得到的极小非规格化数）
    // --- 原文示例片段结束 ---

    return 0;
}
