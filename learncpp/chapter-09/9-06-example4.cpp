// 来源小节：9.6 Assert and static_assert
// 示例说明：用运行期断言 assert() 验证函数参数——gravity 必须为正。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example4.cpp -o a
// 说明：main() 故意传入 -9.8，触发断言并调用 std::abort()（异常终止）。
//       预期输出（依编译器而异）形如：
//       dropsimulator: src/main.cpp:6: double calculateTimeUntilObjectHitsGround(double, double):
//       Assertion 'gravity > 0.0' failed.
// 警告：本程序运行到断言处会异常终止（非零退出），属预期行为。
//
// 本节代码为按原文描述重建。

#include <cassert>  // for assert()
#include <cmath>    // for std::sqrt
#include <iostream>

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
    assert(gravity > 0.0); // The object won't reach the ground unless there is positive gravity.

    if (initialHeight <= 0.0)
    {
        // The object is already on the ground. Or buried.
        return 0.0;
    }

    return std::sqrt((2.0 * initialHeight) / gravity);
}

int main()
{
    std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";

    return 0;
}
