// 来源小节：1.5 Introduction to iostream: cout, cin, and endl
// 示例说明：换行的三种做法——不换行、用 std::endl、用 \n。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/
//
// 预期输出：
//   Hi!My name is Alex.
//   Hi!
//   My name is Alex.
//   x is equal to: 5
//   Yep.
//   And that's all, folks!

#include <iostream>

int main()
{
    // --- 原文示例片段：两条独立语句，不加换行会连在一起 ---
    std::cout << "Hi!";
    std::cout << "My name is Alex.";
    // --- 原文示例片段结束 ---
    std::cout << '\n'; // 为便于区分，这里补一个换行（原文未补）

    // --- 原文示例片段：用 std::endl 逐行输出 ---
    std::cout << "Hi!" << std::endl;
    std::cout << "My name is Alex." << std::endl;
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：使用 \n 的三种写法 ---
    std::cout << "x is equal to: " << 5 << '\n'; // single-quoted (conventional)
    std::cout << "Yep." << "\n";                  // double-quoted (unconventional but okay)
    std::cout << "And that's all, folks!\n";      // \n embedded in existing text
    // --- 原文示例片段结束 ---

    return 0;
}
