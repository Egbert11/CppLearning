// ============================================================
// 来源小节：16.4 Passing std::vector
// 示例说明：Quiz 解答——带边界检查的 printElement。
//           下标参数必须是 int 而非 std::size_t，否则无法检测调用者传入的负下标。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// 预期输出：
//   The element has value 2
//   Invalid index
//   The element has value 1.1
//   Invalid index
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

// index needs to be an int, not a std::size_t, otherwise we won't be able to detect if the user passes in a negative index
template <typename T>
void printElement(const std::vector<T>& arr, int index)
{
    if (index < 0 || index >= static_cast<int>(arr.size())) // In C++20, could use std::ssize(arr) to avoid the cast
        std::cout << "Invalid index\n";
    else
        std::cout << "The element has value " << arr[static_cast<std::size_t>(index)] << '\n';
}

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
