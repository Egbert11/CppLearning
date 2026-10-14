// 来源小节：8.10 For statements（本节 Quiz 第 1 题解答）
// 示例说明：用 for 循环打印 0 到 20 之间的所有偶数
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：0 2 4 6 8 10 12 14 16 18 20（各一行）

#include <iostream>

int main()
{
    for (int i{ 0 }; i <= 20; i += 2)
        std::cout << i << '\n';

    return 0;
}
