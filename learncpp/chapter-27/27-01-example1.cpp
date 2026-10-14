// ============================================================
// 来源小节：27.1 The need for exceptions
// 示例说明：用"返回码"/哨兵值表示错误——找到字符返回下标，未找到返回 -1。
//           体现返回码方案的简单，但也暴露其缺点：-1 既可能是错误，也可能
//           是合法结果，调用者无法仅凭返回值判断。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-need-for-exceptions/
// 预期输出：
//   7
//   -1
// 备注：函数体逐字取自原文；main 为便于编译运行而补充。
// ============================================================
#include <iostream>
#include <string_view>

int findFirstChar(std::string_view string, char ch)
{
    // Step through each character in string
    for (std::size_t index{ 0 }; index < string.length(); ++index)
        // If the character matches ch, return its index
        if (string[index] == ch)
            return index;

    // If no match was found, return -1
    return -1;
}

int main()
{
    std::cout << findFirstChar("Hello, world!", 'w') << '\n'; // 7，找到
    std::cout << findFirstChar("Hello, world!", 'z') << '\n'; // -1，未找到（错误码）

    return 0;
}
