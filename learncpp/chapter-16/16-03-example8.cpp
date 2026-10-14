// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：用 auto 推导 std::ssize() 返回的有符号类型，避免手动指定。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };
    auto length { std::ssize(prime) }; // use auto to deduce signed type, as returned by std::ssize()
    std::cout << "length: " << length;

    return 0;
}
