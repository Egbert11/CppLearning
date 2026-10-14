// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：把循环变量改为有符号 int，倒序循环可正确终止；
//           但取得起始下标和每次下标访问都要 static_cast，可读性变差。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：9 1 2 8 3 7 6 4
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

void printReverse(const std::vector<int>& arr)
{
    // index is signed
    for (int index{ static_cast<int>(arr.size()) - 1 }; index >= 0; --index)
        std::cout << arr[static_cast<std::size_t>(index)] << ' ';

    std::cout << '\n';
}

int main()
{
    std::vector arr { 4, 6, 7, 3, 8, 2, 1, 9 };
    printReverse(arr);

    return 0;
}
