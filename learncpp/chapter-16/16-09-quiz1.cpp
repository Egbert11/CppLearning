// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators —— 测验解答
// 示例说明：用枚举量作下标从"动物腿数"数组中取值，并用计数枚举量 max_animals
//           断言数组长度与枚举量个数一致。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：An elephant has 4 legs.
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cassert>
#include <iostream>
#include <vector>

namespace Animals
{
    enum Animals
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };

    const std::vector legs { 2, 4, 4, 4, 2, 0 };
}

int main()
{
    // Ensure the number of legs is the same as the number of animals
    assert(std::size(Animals::legs) == Animals::max_animals);

    std::cout << "An elephant has " << Animals::legs[Animals::elephant] << " legs.\n";

    return 0;
}
