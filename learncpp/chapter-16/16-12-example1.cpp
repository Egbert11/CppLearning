// ============================================================
// 来源小节：16.12 std::vector<bool>
// 示例说明：std::vector<bool> 的基本用法——创建、遍历、按下标修改元素，
//           其行为看起来与普通 std::vector 类似。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-bool/
// 预期输出（原作者 64 位机器）：
//   1 0 0 1 1
//   1 0 0 1 0
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector<bool> v { true, false, false, true, true };

    for (int i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    // Change the Boolean value with index 4 to false
    v[4] = false;

    for (int i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
