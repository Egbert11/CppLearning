// 来源小节：7.3 Local variables
// 示例说明：嵌套块的作用域与生存期——内层块里声明的 y 只在内层块内可见、可用；
//           外层块里无法访问 y。（对应原文 Example 5）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出：
//   5 7
//   5
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{ // outer block
    int x { 5 }; // x enters scope and is created here

    { // nested block
        int y { 7 }; // y enters scope and is created here

        std::cout << x << ' ' << y << '\n'; // x and y are both in scope here
    } // y goes out of scope and is destroyed here

    // y can not be used here because it is out of scope in this block

    std::cout << x << '\n';

    return 0;
} // x goes out of scope and is destroyed here
