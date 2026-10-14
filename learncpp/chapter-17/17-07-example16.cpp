// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：要"整体拷贝"数组内容，可用 std::copy（配合 std::begin/std::end），
//           或改用 std::vector。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：567
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{
    int arr[] { 1, 2, 3 };
    const int src[] { 5, 6, 7 };

    std::copy(std::begin(src), std::end(src), std::begin(arr));

    std::cout << arr[0] << arr[1] << arr[2] << '\n';

    return 0;
}
