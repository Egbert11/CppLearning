// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：at() 进行运行期边界检查，越界下标会抛出 std::out_of_range 异常，
//           未捕获异常终止程序（不是未定义行为）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：先输出 7，随后因 prime.at(9) 越界抛异常而终止程序。
//           程序若被包装在 try/catch 中会打印 "std::out_of_range"，此处不捕获。
// 备注：本节代码为按原文描述重建。退出码通常非 0（异常终止）。
// ============================================================
#include <iostream>
#include <vector>
#include <stdexcept>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    std::cout << prime.at(3); // print the value of element with index 3
    std::cout << prime.at(9); // invalid index (throws exception)

    return 0;
}
