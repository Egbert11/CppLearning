// ============================================================
// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：测验解答——设置"已查看"标志、检查文章是否已删除、
//           清除"收藏"标志。除打印外不使用 std::bitset。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
// ============================================================
//
// 预期输出：
//   00000101
//   00000001
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <bitset>  // 仅用于打印
#include <cstdint>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] constexpr std::uint8_t option_viewed{    0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{    0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{    0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{   0x10 };

    std::uint8_t myArticleFlags{ option_favorited }; // starts out favorited

    // Set the viewed flag
    myArticleFlags |= option_viewed;

    std::cout << std::bitset<8>{ myArticleFlags } << '\n'; // 00000101

    // Check if the article was deleted
    if (myArticleFlags & option_deleted)
        std::cout << "This article was deleted\n";

    // Clear the favorited flag
    myArticleFlags &= static_cast<std::uint8_t>(~option_favorited);

    std::cout << std::bitset<8>{ myArticleFlags } << '\n'; // 00000001
    // --- 原文示例片段结束 ---

    return 0;
}
