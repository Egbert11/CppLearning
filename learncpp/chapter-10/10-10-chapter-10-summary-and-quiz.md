# 10.x Chapter 10 summary and quiz

> 官方编号为 10.x；本文件按整章小节数顺延编号为 10-10。
> 原文：https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/

## 核心概念

- **类型转换（type conversion）**：把值从一种数据类型改成另一种的统称。
- **隐式类型转换（implicit type conversion，又称自动类型转换 / 强制转换 coercion）**：当提供了与预期不同的类型时自动发生；编译器若知道怎么做就做，否则以编译错误失败。
- **标准转换（standard conversions）**：语言在基础类型（及某些高级类型）之间定义的内建转换；包括数值提升、数值转换、算术转换等。
- **数值提升（numeric promotion）**：把某些较小数值类型转换为较大类型（通常是 `int` 或 `double`），让 CPU 按其自然数据尺寸工作。涵盖整型提升与浮点提升，且都**保值**（不丢值、不丢精度）。
- **重要提醒**：并非所有"变宽"都算提升。
- **数值转换（numeric conversion）**：基础类型之间除数值提升之外的所有转换。
- **窄化转换（narrowing conversion）**：可能丢失值或精度的数值转换。
- **常规算术转换（usual arithmetic conversions）**：一套规则，把类型不同的操作数隐式转换成匹配类型，因为某些二元运算符要求两操作数同类型。
- **显式类型转换**：程序员通过转换（cast）直接要求的转换。
- **转换（cast）**：程序员对显式类型转换的请求。C++ 提供五种：C 风格、static、const、dynamic、reinterpret。
- **转换选用建议**：C 风格、`const_cast`、`reinterpret_cast` 一般应避免；`static_cast` 是最常用的。
- **typedef 与类型别名**：可以为数据类型创建别名。它们不是新类型，行为与被别名的类型完全相同；没有类型安全，因此不要以为别名是独立的类型。
- **`auto` 类型推导（type deduction，又称类型推断 type inference）**：从初始化式推导变量类型；会丢弃 const 和引用，需要时自己加回。
- **`auto` 作为返回类型**：让编译器从 return 语句推断函数返回类型，但普通函数应避免这样用；`auto` 也参与**尾置返回语法**。

## 最佳实践

本节为总结/测验小节，无独立的 Best practice / Author's note / Warning 提示框。内嵌的规则性指引为：避免 C 风格、`const`、`reinterpret` 转换；优先 `static_cast`；不要把类型别名当作独立类型；普通函数避免 `auto` 返回类型。

## 代码示例

- [`10-10-quiz1.cpp`](10-10-quiz1.cpp)：测验 1 解答——能通过编译的声明（含 `1a`~`1j` 注释），演示各类转换类型。
- [`10-10-quiz1-c-error.cpp`](10-10-quiz1-c-error.cpp)：测验 1 的 `1c`（`int c { 5.4 };`）单独成文件，预期编译失败。
- [`10-10-quiz1-i-warning.cpp`](10-10-quiz1-i-warning.cpp)：测验 1 的 `1i`（`float i { f };`）单独成文件，预期产生窄化警告（GCC 默认只警告，标准要求 ill-formed，需 `-pedantic-errors` 才报错）。
- [`10-10-quiz2-original.cpp`](10-10-quiz2-original.cpp)：测验 2a 的起始程序（未用别名的度/弧度转换）。
- [`10-10-quiz2.cpp`](10-10-quiz2.cpp)：测验 2a 解答——用 `Degrees`/`Radians` 类型别名重写；并含测验 2b 的 `radians = degrees;` 演示。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

## 本章知识速览

- **类型转换三类**：隐式（自动 coercion）、显式（cast）、标准转换（提升 + 数值转换 + 算术转换）。
- **数值提升**：保值；`bool`/`char`/`signed char`/`unsigned char`/`signed short`/`unsigned short` → `int`（在 4 字节 `int` 平台），`float` → `double`。
- **数值转换**：非提升的基础类型间转换；三档安全度——保值（value-preserving）、重解释（reinterpretive）、有损（lossy）。
- **窄化转换**：可能丢值/丢精度；花括号初始化拒绝它（constexpr 且在目标范围内时例外）；浮点 → 整型无例外，constexpr 浮点 → 更窄浮点不算窄化。
- **常规算术转换**：类型不同的二元操作数先提升，必要时再按等级/符号规则统一到公共类型。等级：`long double` > `double` > `float` > `long long` > `long` > `int`。
- **显式转换**：首选 `static_cast`（编译期检查、能力受限、误用报错）；避免 C 风格与 `const_cast`/`reinterpret_cast`。
- **类型别名**：`using X = T;`（优先于 `typedef`）；别名不是新类型、无类型安全；用于平台无关、简化复杂类型、记录含义、便于维护；命名首字母大写、无后缀、审慎使用。
- **`auto`（对象）**：从初始化式推导；丢弃顶层 const 与引用（需自行加回）；字符串字面量推成 `const char*`（要 `std::string`/`string_view` 用 `s`/`sv`）；强制初始化；可能掩盖 `unsigned` 与整数除法等陷阱。
- **`auto`（函数返回）**：C++14 起；所有 return 必须同类型；必须先定义后调用；接口不透明，通常建议避开；尾置返回 `auto f(args) -> T` 在复杂返回类型、依赖参数类型、lambda 等场景必需；形参 `auto`（C++20）触发的是函数模板。

## 测验

**测验 1**：对下列每种情况判定其转换类型（无需转换 / 数值提升 / 数值转换 / 因窄化而无法编译）。假设 `int` 与 `long` 均为 4 字节。

| 情况 | 代码 | 答案 |
|---|---|---|
| 1a | `int a { 5 };` | 无需转换 |
| 1b | `int b { 'a' };` | 数值提升：`char` → `int` |
| 1c | `int c { 5.4 };` | 无法编译——窄化转换 |
| 1d | `int d { true };` | 数值提升：`bool` → `int` |
| 1e | `int e { static_cast<int>(5.4) };` | 数值转换：`double` → `int` |
| 1f | `double f { 5.0f };` | 数值提升：`float` → `double` |
| 1g | `double g { 5 };` | 数值转换：`int` → `double` |
| 1h | `long h { 5 };` | 数值转换：`int` → `long`（平凡，但仍是转换） |
| 1i | `float i { f };` | 无法编译——`double` → `float` 窄化 |
| 1j | `float j { 5.0 };` | 数值转换：`double` → `float`；因 `5.0` 是 constexpr 且在 `float` 范围内，允许 |

解答见 [`10-10-quiz1.cpp`](10-10-quiz1.cpp)（可通过编译的部分），以及两份预期失败/警告的演示文件 [`10-10-quiz1-c-error.cpp`](10-10-quiz1-c-error.cpp)、[`10-10-quiz1-i-warning.cpp`](10-10-quiz1-i-warning.cpp)（`1i` 在 GCC 下仅窄化警告，需 `-pedantic-errors` 才报错）。

**测验 2a**：用类型别名重写度/弧度转换程序。

**解答**：在 `constants` 命名空间后加上 `using Degrees = double;` 与 `using Radians = double;`；转换函数返回 `Radians`、形参为 `Degrees`，公式仍为 `degrees * constants::pi / 180`；`main()` 中把输入变量声明为 `Degrees`、结果变量声明为 `Radians`，其余提示、输入、输出不变。见 [`10-10-quiz2.cpp`](10-10-quiz2.cpp)。

**测验 2b**：在上述 `degrees`、`radians` 定义下，`radians = degrees;` 能否编译？

**答案**：能。两个别名都解析为 `double`，该语句就是把一个 `double` 赋给另一个，别名不构成类型区分。见 [`10-10-quiz2.cpp`](10-10-quiz2.cpp) 中的演示。
