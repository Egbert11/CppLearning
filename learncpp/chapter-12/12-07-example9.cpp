// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：ptr 保存 x 的地址（&x 是 int*），用 *ptr 取得 x 的值。
//           使用 ptr 访问地址，使用 *ptr 访问被指向的对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 9）。
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
