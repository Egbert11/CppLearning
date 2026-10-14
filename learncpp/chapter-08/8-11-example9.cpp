// 来源小节：8.11 Break and continue
// 示例说明：把条件取反、使用嵌套块的写法（不使用 continue）
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 预期输出：1 2 3 5 6 7 9（各一行）

#include <iostream>

int main()
{
    for (int count{ 0 }; count < 10; ++count)
    {
        // if the number is not divisible by 4...
        if ((count % 4) != 0) // nested block
        {
            // Print the number
            std::cout << count << '\n';
        }
    }

    return 0;
}
