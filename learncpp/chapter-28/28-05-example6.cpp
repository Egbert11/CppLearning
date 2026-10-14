// ============================================================
// 来源小节：28.5 Stream states and input validation（原 Example 6）
// 示例说明：在 Example 5 基础上，用 std::cin.gcount() > 1 判断本行是否还有
//           额外字符；若有则视为非法输入并重试（拒绝 "34abcd" 这类混合输入）。
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
        if (std::cin.gcount() > 1) // if we cleared out more than one additional character
        {
            continue; // we'll consider this input to be invalid
        }

        if (age <= 0) // make sure age is positive
        {
            continue;
        }

        break;
    }

    std::cout << "You entered: " << age << '\n';
}
