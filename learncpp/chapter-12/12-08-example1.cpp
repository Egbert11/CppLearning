// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：回顾——指针保存另一个对象的地址，可用解引用运算符 * 访问
//           那个地址处的值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 1）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x

    int* ptr{ &x }; // ptr holds the address of x
    std::cout << *ptr << '\n'; // use dereference operator to print the value of the object at the address that ptr is holding (which is x's address)
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5
// 5
