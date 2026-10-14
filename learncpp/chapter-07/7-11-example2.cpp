// 来源小节：7.11 Static local variables
// 示例说明：static 静态持久期 —— 初始化器只执行一次，值跨调用保留。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-local-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 2）。
// 预期输出：
// 2
// 3
// 4

#include <iostream>

void incrementAndPrint()
{
    static int s_value{ 1 }; // static 关键字赋予静态持久期。此初始化器只执行一次。
    ++s_value;
    std::cout << s_value << '\n';
} // s_value 不在此销毁，但因离开作用域而变得不可访问

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}
