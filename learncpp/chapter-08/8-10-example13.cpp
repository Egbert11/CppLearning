// 来源小节：8.10 For statements
// 示例说明：反面写法——i 定义在循环外、在循环内赋值，循环结束后 i 仍存在
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：0 1 2 3 4 5 6 7 8 9
// 说明：最佳实践建议"仅在循环内使用的变量应定义在循环作用域内"。

#include <iostream>

int main()
{
    int i {}; // i defined outside loop

    // i 在循环外定义，因此循环结束后不会被销毁（这是应避免的写法）
    for (i = 0; i < 10; ++i) // i assigned inside loop
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}
