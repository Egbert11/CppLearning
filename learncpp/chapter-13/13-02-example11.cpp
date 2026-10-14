// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：枚举可用来定义"位标志"（bit flag），配合 std::bitset 表示一组
//           可同时成立的开关状态。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <bitset>
#include <iostream>

namespace Flags
{
    enum State
    {
        isHungry,
        isSad,
        isMad,
        isHappy,
        isLaughing,
        isAsleep,
        isDead,
        isCrying,
    };
}

int main()
{
    std::bitset<8> me {};
    me.set(Flags::isHappy);

    std::cout << std::boolalpha << me.test(Flags::isHappy) << '\n';

    return 0;
}

// 预期输出：
// true
