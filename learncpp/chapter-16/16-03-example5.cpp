// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：把 size() 的结果 static_cast 成 int，存进有符号变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    int length { static_cast<int>(prime.size()) }; // static_cast return value to int
    std::cout << "length: " << length;

    return 0;
}
