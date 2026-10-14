// ============================================================
// 来源小节：17.x Chapter 17 summary and quiz（测验 1(c)）
// 示例说明：一段有 bug 的代码——用运行期读入的 length 作为 std::array 的长度。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
// 预期错误：length 不是常量表达式，不能作为 std::array 的非类型模板实参，编译失败。
//           此处用 -error 后缀表示预期编译失败。
// 修法：改用 std::vector<int> scores(length);（长度在运行期确定时用动态数组）。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    int length{};
    std::cout << "How many scores? ";
    std::cin >> length;

    std::array<int, length> scores; // error: length is not a constant expression

    return 0;
}
