// ============================================================
// 来源小节：28.5 Stream states and input validation（原 Example 1）
// 示例说明：把整数读入 age；若输入非数字（如 "Alex"）则 failbit 被置位，
//           之后 cin 处于失败状态、后续提取都被忽略。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation/
// 预期：输入合法整数时正常；输入字母后 age 保持为 0 且 std::cin.fail() 为 true。
// 备注：原 Example 1 只有读取的两行片段，这里补全为可运行程序以演示 failbit。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;
    // --- 原文示例片段结束 ---

    if (std::cin.fail())
        std::cout << "Extraction failed (failbit set); age = " << age << '\n';
    else
        std::cout << "You entered: " << age << '\n';

    return 0;
}
