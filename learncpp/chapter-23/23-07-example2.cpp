// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：动态分配的数组同样可以用花括号列表初始化，
//           用下标循环打印后 delete[]。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   5 4 3 2 1
// 备注：本节代码为按原文描述重建（原 Example 2）。
// ============================================================
#include <iostream>
#include <cstddef>

int main()
{
    auto* array{ new int[5]{ 5, 4, 3, 2, 1 } }; // initializer list

    for (std::size_t count{ 0 }; count < 5; ++count)
        std::cout << array[count] << ' ';
    std::cout << '\n';

    delete[] array;

    return 0;
}
