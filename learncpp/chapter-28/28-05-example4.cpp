// ============================================================
// 来源小节：28.5 Stream states and input validation（原 Example 4）
// 示例说明：基础数值验证循环——提取失败时 clear() 重置状态、ignore() 丢弃
//           坏输入后重试；并要求 age 为正数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation/
// 预期：需要交互输入；输入非数字或非正数会要求重输。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。
// ============================================================
#include <iostream>
#include <limits>

int main()
{
    int age{};

    while (true)
    {
        std::cout << "Enter your age: ";
        std::cin >> age;

        if (std::cin.fail()) // no extraction took place
        {
            std::cin.clear(); // reset the state bits back to goodbit so we can use ignore()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear out the bad input from the stream
            continue; // try again
        }

        if (age <= 0) // make sure age is positive
            continue;

        break;
    }

    std::cout << "You entered: " << age << '\n';
}
