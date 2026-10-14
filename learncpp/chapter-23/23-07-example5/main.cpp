// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：带 std::initializer_list<int> 构造函数的 IntArray，
//           现在可以用花括号列表初始化；因为拷贝操作被 delete，
//           避免了浅拷贝隐患。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   5 4 3 2 1
// 备注：本节代码为按原文描述重建（原 Example 5/6/7）。
// ============================================================
#include <iostream>
#include "IntArray.h"

int main()
{
    IntArray array { 5, 4, 3, 2, 1 }; // this line is our string of numbers

    for (int count{ 0 }; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';
    std::cout << '\n';

    return 0;
}
