// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：Quiz #2 解答——把 Quiz #1 的打印逻辑封装成函数模板 printArray()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (std::size_t index{ 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    if (arr.size() > 0)
        std::cout << '\n';
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr);

    return 0;
}
