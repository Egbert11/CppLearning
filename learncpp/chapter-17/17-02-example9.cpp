// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：与 operator[] 不同，at() 在越界时会抛出 std::out_of_range 异常
//           （作者建议用预先检查或编译期检查代替 at() 的运行时检查）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：out_of_range: array::at: __n (which is 9) >= _Nm (which is 5)
// 备注：本节代码为按原文描述重建，补充了异常演示；异常消息由标准库实现决定。
// ============================================================
#include <array>
#include <iostream>
#include <stdexcept>

int main()
{
    constexpr std::array prime{ 2, 3, 5, 7, 11 };

    try
    {
        std::cout << prime.at(9) << '\n'; // throws std::out_of_range
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "out_of_range: " << e.what() << '\n';
    }

    return 0;
}
