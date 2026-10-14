// ============================================================
// 来源小节：28.5 Stream states and input validation（原 Example 5）
// 示例说明：在 Example 4 基础上，成功提取后无条件 ignore() 掉本行剩余输入，
//           避免 "34abcd" 这类输入把垃圾留在流中。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation/
// 预期：需要交互输入。
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

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear out any additional input from the stream

        if (age <= 0) // make sure age is positive
            continue;

      break;
    }

    std::cout << "You entered: " << age << '\n';
}
