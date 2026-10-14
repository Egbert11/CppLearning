// 来源小节：4.6 Fixed-width integers and size_t
// 示例说明：fast 类型的实现定义尺寸会跨架构改变程序行为。0 减 1 的回绕结果取决于 uint_fast16_t 实际是 16/32/64 位。
//           原文描述：输出依 std::uint_fast16_t 是 16、32 还是 64 位而异
//           （16 位得到 65535，32 位得到 4294967295，64 位得到 18446744073709551615）。
//           注意：结果依实现而定。
// 原文链接：https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
//
// 编译：g++ -std=c++20 -Wall 4-06-example5.cpp -o a

#include <cstdint>
#include <iostream>

int main()
{
    std::uint_fast16_t sometype { 0 };
    sometype = sometype - 1; // intentionally overflow to invoke wraparound behavior

    std::cout << sometype << '\n';

    return 0;
}
