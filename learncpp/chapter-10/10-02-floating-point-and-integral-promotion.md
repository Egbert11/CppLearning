# 10.2 Floating-point and integral promotion

> 原文：https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion/

## 核心概念

- **类型尺寸因平台而异**：C++ 只为核心类型规定最小尺寸保证，实际大小随编译器和体系结构不同。这种灵活性的目的是让 `int`、`double` 取到该机器上性能最好的尺寸。
- **宽度（width）**：一个类型占用的位数。更宽的类型用更多位，更窄的用更少位。
- **为什么窄值处理起来别扭**：某些 32 位 CPU（如 32 位 x86）能直接处理 8/16 位值，但往往比处理 32 位值更慢；另一些（如 32 位 PowerPC）只能处理 32 位值，需要额外技巧。因此语言不会假设 CPU 能高效处理比其自然尺寸更窄的值。
- **数值提升（numeric promotion）**：一类类型转换，把某些较窄的数值类型（如 `char`）转换为硬件能高效处理的较宽类型（通常是 `int` 或 `double`）。
- **保值转换 / 安全转换（value-preserving / safe conversion）**：源类型的每一个可能取值都能在目标类型中表示为相等的值。所有数值提升都满足这一点。
- **提升是"静默"的**：因为提升安全，编译器会自由地做，并且不发出任何警告。
- **减少冗余**：提升让一个以 `int`/`double` 为形参的函数能接受多种实参类型，不必为 `short`、`char`、`unsigned char`、`signed char`、`unsigned short`、`wchar_t`、`char8_t`、`char16_t`、`char32_t` 等各写一份重载。
- **两个子类别**：数值提升分为**整型提升（integral promotion）**与**浮点提升（floating point promotion）**；只有这两类里的转换才算数值提升。
- **浮点提升规则**：`float` 可转换为 `double`。于是形参是 `double` 的函数既能接受 `double` 也能接受 `float` 实参。
- **整型提升规则**：
  - `signed char` 或 `signed short` → `int`。
  - `unsigned char`、`char8_t`、`unsigned short` → 若 `int` 能容纳其全部取值范围则提升为 `int`，否则为 `unsigned int`。
  - 若 `char` 默认有符号，按 `signed char` 规则；默认无符号则按 `unsigned char` 规则。
  - `bool` → `int`，`false` 变 `0`，`true` 变 `1`。
- **典型结果**：在 8 位字节、`int` 为 4 字节或更多（当今常见）的平台上，`bool`、`char`、`signed char`、`unsigned char`、`signed short`、`unsigned short` 全都提升为 `int`。
- **罕见的额外规则**：还有少量整型提升规则（见 cppreference 的隐式转换页）。
- **两点注意**：
  - 在某些体系结构（如 2 字节 `int`）上，某些无符号类型可能提升为 `unsigned int` 而非 `int`。
  - 某些较窄的无符号类型（如 `unsigned char`）可能提升为更大的**有符号**类型（如 `int`），因此提升保值但不一定保号（signedness）。
- **并非所有"变宽"都算提升**：像 `char` → `short`、`int` → `long` 这类属于**数值转换**（见 10.3），不是提升，因为它们无助于把小的类型变成高效处理的大类型。这个区分主要影响编译器对提升的偏好，例如函数重载解析（11.3）。

## 最佳实践

本节无 Best practice / Rule / Warning 条目。仅有：

- **A reminder**：类型占用的位数称为**宽度（width）**，更宽的类型位数更多，更窄的位数更少。

## 代码示例

- [10-02-example1.cpp](10-02-example1.cpp)：以一个取 `int` 的函数引入——说明为什么提升能避免为每种类型写重复函数。
- [10-02-example2.cpp](10-02-example2.cpp)：浮点提升——形参为 `double` 的函数同时接受 `double` 与 `float` 实参。
- [10-02-example3.cpp](10-02-example3.cpp)：整型提升——`int`、`short`、`char`、`bool` 实参都传给同一个取 `int` 形参的函数。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。（原文未给出这三个示例的运行输出。）
