# O.3 Bit manipulation with bitwise operators and bit masks

> 原文：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/

## 核心概念

- **位掩码（bit mask）**：一组预定义好的位，用来"选择后续操作会修改哪些具体的位"。掩码挡住不想被改动的位，同时放开你想操作的位。
- 掩码的比喻：就像美纹纸（masking tape）保护窗框上不想被刷到漆的部分，位掩码保护你不希望被改动的那些位。
- **C++14 定义掩码**：有二进制字面量，写掩码很方便。用 `0` 表示要忽略的位，用 `1` 表示要操作的位；用符号常量给掩码取有意义的名字以便复用。
- **C++11 及更早**：没有二进制字面量，可改用十六进制字面量或左移。十六进制与四位一组直接对应；左移则把单个 `1` 放到目标位置。
- **测试某位**：用位与 `&` 配合对应掩码。结果非零转换为 `true`，结果为零转换为 `false`。
- **设置某位**：用位或赋值 `|=` 配合掩码。把多个掩码先或在一起，就能一次设置多个位。
- **复位某位**：用位与赋值配合按位取反（`&= ~mask`）。多个位可用 `&= ~(mask4 | mask5)` 一起清除。
- **符号转换提醒**：`~mask2` 可能被提升为有符号 `int`，从而触发编译器抱怨。必要时转回 `std::uint8_t`。
- **翻转某位**：用位异或赋值 `^=` 配合掩码。把掩码组合起来，XOR 也能一次翻转多个位。
- **`std::bitset`**：支持所有位运算符。`test`、`set`、`reset`、`flip` 等成员函数只改单个位，而配合掩码的运算符可以一次改多个位。
- **取有意义的名字**：掩码要按它所代表的标志命名，而不是按位位置命名。
- **位标志何时有用**：当大量同类对象都需要许多"类布尔"标志时，可省内存；也能让"选项很多"的函数调用更可读。
- **多位的掩码**：掩码可以选中一组位。对 RGBA 值，先用 AND 隔离出每个 8 位分量，再右移到低位。
- **总结口诀**：查询用 AND；设置用 OR；清除用 AND + NOT；翻转用 XOR。

## 最佳实践

- **Best practice**：给位掩码取有用的名字，用它来记录位标志的含义。
- **Key insight**：某些编译器可能对 `flags &= ~mask2;` 给出符号转换警告；若如此，可改用 `flags &= static_cast<std::uint8_t>(~mask2);`。
- **Related content**：十六进制见 5.2 小节（Literals）。
- **关于 `std::bitset` 的两点**：它没有直接的"掩码查询"函数，需用位与来查询位；可用 `.any()` 判断被查询的位中是否还有任何一位处于置位状态。

## 代码示例

本节代码为**重建**（抓取工具无法逐字返回长代码块，以下示例按原文描述与该站标准示例忠实重建，语义与预期输出一致）。

- [O-03-example1.cpp](O-03-example1.cpp) — 用 C++14 二进制字面量定义 `mask0`…`mask7`。
- [O-03-example2.cpp](O-03-example2.cpp) — 用十六进制字面量定义同样的一组掩码（C++11 及更早写法）。
- [O-03-example3.cpp](O-03-example3.cpp) — 用左移 `1 << n` 定义同样的一组掩码。
- [O-03-example4.cpp](O-03-example4.cpp) — 用 `flags & maskN` 测试位（输出 `bit 0 is on`、`bit 1 is off`）。
- [O-03-example5.cpp](O-03-example5.cpp) — 用 `flags |= maskN` 设置位，并一次设置多个位。
- [O-03-example6.cpp](O-03-example6.cpp) — 用 `flags &= ~maskN` 复位位，并一次清除多个位（含符号转换修复写法）。
- [O-03-example7.cpp](O-03-example7.cpp) — 用 `flags ^= maskN` 翻转位，并一次翻转多个位。
- [O-03-example8.cpp](O-03-example8.cpp) — 在 `std::bitset` 上配合掩码做查询/设置/清除/翻转。
- [O-03-example9.cpp](O-03-example9.cpp) — 用取有意义名字的 `std::uint8_t` 掩码表示情绪状态。
- [O-03-example10.cpp](O-03-example10.cpp) — 同上，但用 `std::bitset` 与 `.any()`。
- [O-03-example11.cpp](O-03-example11.cpp) — 32 个 `bool` 参数的函数难以使用（问题示例）。
- [O-03-example12.cpp](O-03-example12.cpp) — 改用 `std::bitset<32>` 传选项，调用点更可读。
- [O-03-example13-opengl.cpp](O-03-example13-opengl.cpp) — OpenGL 风格的位标志用法。**依赖 OpenGL，需要 `-lopengl32` 才能链接**。

> 补充说明：原文把"`std::uint8_t cneg { ~c };`"标为 compile error（窄化转换），但 GCC 对该情形只给出 `-Wnarrowing` 警告并继续编译，因此 O.2 中对应示例以 `-warning` 命名（见 [O-02-example13-warning.cpp](O-02-example13-warning.cpp)）。
- [O-03-example14.cpp](O-03-example14.cpp) — 从一个 32 位 RGBA 像素值中提取各 8 位分量。
- [O-03-example15.cpp](O-03-example15.cpp) — 查询/设置/清除/翻转的总结片段。
- [O-03-quiz.cpp](O-03-quiz.cpp) — 测验解答：设置已读、检查已删除、清除收藏标志（输出 `00000101`、`00000001`）。

## 测验

1. 给出文章的一组位标志（`option_viewed`、`option_edited`、`option_favorited`、`option_shared`、`option_deleted`，除打印外不得使用 `std::bitset`）：
   - 设置"已查看"标志；
   - 判断文章是否已被删除；
   - 清除"收藏"标志。
   - 解答见 [O-03-quiz.cpp](O-03-quiz.cpp)。德摩根定律可解释两种等价的清除写法：`flags &= ~(option4 | option5)` 等价于 `flags &= ~option4 & ~option5`。
