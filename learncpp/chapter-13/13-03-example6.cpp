// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：可以显式指定枚举的底层类型（base，也叫 underlying type）。这里用
//           8 位整数 std::int8_t，使枚举对象只占 1 字节。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <cstdint>  // for std::int8_t
#include <iostream>

// Use an 8-bit integer as the enum underlying type
enum Color : std::int8_t
{
    black,
    red,
    blue,
};

int main()
{
    Color c{ black };
    std::cout << sizeof(c) << '\n'; // prints 1 (byte)

    return 0;
}

// 预期输出：
// 1
