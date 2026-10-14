// 来源小节：7.3 Local variables
// 示例说明：外层变量在内层块里可见——嵌套块属于外层块的作用域，块外声明的变量可在块内使用
//           （反向不成立）。（对应原文 Example 6）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出：12
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{ // outer block
    int x { 5 }; // x is created here

    { // nested block
        int y { 7 }; // y is created here

        std::cout << x + y << '\n'; // x and y are both in scope here
    } // y is destroyed here

    return 0;
} // x is destroyed here
