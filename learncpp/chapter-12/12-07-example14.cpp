// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：引用与指针并排演示——它们都能修改同一个变量 x，区别在于
//           引用一经绑定不可重设且更"安全"，指针可重设且更"危险"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 14）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };

    int& ref { x };
    int* ptr { &x };

    std::cout << x << ref << *ptr << '\n'; // 555

    x = 6;

    std::cout << x << ref << *ptr << '\n'; // 666

    ref = 7; // this modifies x (the object ref is bound to)

    std::cout << x << ref << *ptr << '\n'; // 777
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 555
// 666
// 777
