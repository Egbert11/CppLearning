// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：值初始化（value-initialization）会把枚举变量零初始化为整数值 0，
//           即使没有任何枚举量的值等于 0。本例的 Animal 没有 0 值枚举量，
//           所以 a 的值是一个"语义上无效"的状态。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

enum Animal
{
    cat = -3,    // -3
    dog,         // -2
    pig,         // -1
    // note: no enumerator with value 0 in this list
    horse = 5,   // 5
    giraffe = 5, // 5
    chicken,     // 6
};

int main()
{
    Animal a {}; // value-initialization zero-initializes a to value 0
    std::cout << a; // prints 0

    return 0;
}

// 预期输出：
// 0
