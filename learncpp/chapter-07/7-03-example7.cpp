// 来源小节：7.3 Local variables
// 示例说明：无链接（no linkage）——不同作用域里同名的两个局部变量指向不同的对象。（对应原文 Example 7）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出：
//   3
//   2
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{
    int x { 2 }; // outer block x

    { // nested block
        int x { 3 }; // this is a different x, a different object (no linkage)
        std::cout << x << '\n'; // prints the nested block x (3)
    } // nested block x destroyed

    std::cout << x << '\n'; // prints the outer block x (2)

    return 0;
}
