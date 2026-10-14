// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：与 Example 7 相同，但 id1、id2 是普通（非引用）变量，返回的引用
//           被用来初始化它们，于是各复制了一份值，输出 “12”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// 预期输出：12
// 备注：本节代码为按原文描述忠实重建（原 Example 9）。
// ============================================================
#include <iostream>

int& getNextId()
{
    static int s_x{ 0 };
    ++s_x;
    return s_x;
}

int main()
{
    const int id1 { getNextId() }; // id1 is a normal variable (a copy is made)
    const int id2 { getNextId() }; // id2 is a normal variable (a copy is made)

    std::cout << id1 << id2 << '\n'; // prints 12

    return 0;
}
