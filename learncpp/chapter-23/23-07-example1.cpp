// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：普通（栈）数组可以用花括号列表初始化，并用范围 for 打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   5 4 3 2 1
// 备注：本节代码为按原文描述重建（原 Example 1）。
// ============================================================
#include <iostream>

int main()
{
    int array[] { 5, 4, 3, 2, 1 }; // initializer list

    for (auto i : array)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
