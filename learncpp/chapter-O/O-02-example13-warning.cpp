// 来源小节：O.2 Bitwise operators
// 示例说明：整型提升陷阱——c 被提升为 int，~c 的结果是 int，
//           把 int 用列表初始化赋给 std::uint8_t 属于窄化转换（narrowing conversion）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bitwise-operators/
//
// 预期：产生 -Wnarrowing 警告（标准称其为 ill-formed；GCC 只给警告并继续编译，
//       因此本文件命名为 -warning 而非 -error）。
//   warning: narrowing conversion of '~(int)c' from 'int' to 'uint8_t' [-Wnarrowing]
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <cstdint>

int main()
{
    // --- 原文示例片段 ---
    std::uint8_t c { 0b00001111 };

    std::uint8_t cneg { ~c }; // narrowing conversion (原文标为 compile error；GCC 只警告)
    // --- 原文示例片段结束 ---

    (void)cneg;
    return 0;
}
