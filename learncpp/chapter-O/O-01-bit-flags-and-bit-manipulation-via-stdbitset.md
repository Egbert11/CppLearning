# O.1 Bit flags and bit manipulation via std::bitset

> 原文：https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/

## 核心概念

- 内存中最小的**可寻址单位是字节（byte）**。因为每个对象都必须拥有唯一地址，对象至少占一个字节，所以一个只需要一位的布尔值也要占满一个字节，另外 7 位被浪费。
- 打包布尔值：在大多数程序里这点浪费无关紧要，优先考虑可读性；但在存储受限的场景中，可以把 8 个布尔值打包进一个字节。
- **位操作（bit manipulation）**：逐位地操作对象，即"修改对象内部的单个二进制位"。
- **位标志（bit flags）**：不把对象当成一个整体值，而是把它的每一位都当作一个独立的布尔值来用，这些位就叫位标志。
- 命名约定：值为 `0` 的位叫 "false"/"off"/"not set"；值为 `1` 的位叫 "true"/"on"/"set"；在两种状态间切换叫 "flipped"/"inverted"。
- 术语"flag"的含义：标志用来表示某种"条件已满足"——就像邮箱上竖起的小旗表示"箱内有信"。
- 声明一组标志：通常使用宽度合适的**无符号整数**（8、16、32 位……）或 `std::bitset`。
- **位的编号规则**：从右往左、从 0 开始编号（不是从 1 开始），每个编号称为**位位置（bit position）**。在 `00000101` 中，位置 0 和位置 2 上是 1。
- `std::bitset` 的四个关键成员函数（都接收一个位位置参数）：
  - `test(pos)` — 查询某位是 0 还是 1；
  - `set(pos)` — 把某位置 1（若已是 1 则无效果）；
  - `reset(pos)` — 把某位置 0（若已是 0 则无效果）；
  - `flip(pos)` — 反转某位。
- **普通函数与成员函数**：普通函数调用形如 `function(object)`；成员函数调用形如 `object.function()`。
- 给位命名：用 `constexpr int`（或稍后的枚举量）给位位置起名字，可读性更好。
- 一次操作多个位：`std::bitset` 做这件事比较别扭；要用无符号整数的位标志来做，需要用到后面小节介绍的传统技巧。
- **`std::bitset` 的大小规则**：它为速度而非省内存而设计，大小会向上取整到最近的 `sizeof(size_t)`——32 位机器上通常是 4 字节，64 位机器上通常是 8 字节。因此 `std::bitset<8>` 实际通常占 4 或 8 字节，尽管只需要 1 字节。它适合"方便"，而非"省内存"。
- 查询函数：`size()` 位数；`count()` 被置为 `true` 的位数；`all()` 是否全为 true；`any()` 是否有任意位为 true；`none()` 是否没有任何位为 true。

## 最佳实践

- **Best practice**：位操作是少数几种应明确使用无符号整数（或 `std::bitset`）的场合之一。
- **Author's note**：位操作大量出现在图形、加密、压缩、优化等领域，但在一般编程里用得不多，因此整章属于**可选阅读**，可以跳过、略读或以后再回来看。
- **Reminder**：成员函数此前已介绍过；普通调用形如 `function(object)`，成员调用形如 `object.function()`。`0b` 二进制字面量前缀与 `'` 数字分隔符在"数字系统"小节介绍过。
- **Related content**：`[[maybe_unused]]` 见 1.4 小节；13.2 小节（无作用域枚举）展示了用枚举量收集命名位更好的写法。

## 代码示例

- [O-01-example1.cpp](O-01-example1.cpp) — 普通变量保存单个值（与逐位标志形成对照）。
- [O-01-example2.cpp](O-01-example2.cpp) — 声明一个 8 位的标志集合 `std::bitset<8>`，并给出位位置编号参考。
- [O-01-example3.cpp](O-01-example3.cpp) — 用 `set()` / `flip()` / `reset()` / `test()` 操作位集合。
- [O-01-example4.cpp](O-01-example4.cpp) — 同上，但为各位置起名字以提高可读性。
- [O-01-example5.cpp](O-01-example5.cpp) — 用 `size()` / `count()` / `all()` / `any()` / `none()` 查询位集合。
