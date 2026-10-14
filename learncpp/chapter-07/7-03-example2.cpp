// 来源小节：7.3 Local variables
// 示例说明：函数形参在文本上位于函数体之外，但其作用域等同于函数体块的作用域。（对应原文 Example 2）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出：4
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int max(int x, int y) // x and y enter scope here
{
    // assign the greater of x or y to max
    int max{ (x > y) ? x : y }; // max enters scope here

    return max;
} // max, y, and x go out of scope here

int main()
{
    std::cout << max(3, 4) << '\n';
    return 0;
}
