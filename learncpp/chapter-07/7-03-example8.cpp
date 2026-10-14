// 来源小节：7.3 Local variables
// 示例说明：把变量定义在尽可能小的作用域里——y 只在某个块内使用，就定义在该块内。
//           （对应原文 Example 8）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出：5
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{
    // do not define y here

    { // nested block
        // y is only used inside this block, so define it here
        int y { 5 };
        std::cout << y << '\n';
    }

    // otherwise y could still be used here, where it's not needed

    return 0;
}
