# 10.4 Narrowing conversions, list initialization, and constexpr initializers

> 原文：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/

## 核心概念

- **窄化转换（narrowing conversion）**：原文定义为"一种可能不安全的数值转换，目标类型可能无法容纳源类型的所有取值"。
- **C++ 定义的四类窄化转换**：
  1. 浮点 → 整型；
  2. 浮点 → 更窄 / 更低等级（rank）的浮点类型，**除非被转换的值是 constexpr 且落在目标类型范围内**（精度仍可能丢失）；
  3. 整型 → 浮点，**除非被转换的值是 constexpr 且其值能被目标类型精确存储**；
  4. 整型 → 无法表示源全部取值的整型，**除非被转换的值是 constexpr 且其值能被目标类型精确存储**（这包括变窄的转换和符号转换）。
- **警告**：多数隐式窄化转换会触发编译器警告；符号/无符号转换例外，是否警告取决于编译器配置。
- **避免使用**：窄化转换不安全、是错误来源，应尽量减少。
- **让有意的窄化显式化**：不可避免时（常因函数调用形参与实参类型不匹配），用 `static_cast` 把意图记录下来并抑制警告/错误。
- **花括号初始化禁止窄化**：在花括号初始化中做窄化转换是编译错误——这正是该初始化形式被推荐的重要原因。确实想要时可在花括号内用 `static_cast`。
- **取值运行期才知**：若源值要到运行期才知道，编译器无法判断转换是否保值，因此可能仍发出符号/无符号警告。
- **constexpr 例外条款**：当源值是 constexpr 时，编译器知道其值，能自己执行转换并检查是否保值。保值则不算窄化；不保值则编译报错。
- **浮点 → 整型没有 constexpr 例外**：即使 constexpr 值落在目标范围内，这类转换**总是**窄化。
- **constexpr 浮点 → 更窄浮点"从不"是窄化**：即使丢精度，也不算窄化——原文称这一点很奇怪。
- **例外条款为何重要**：它们让人能用 int/double 字面量或 constexpr 对象对非 int/non-double 对象做列表初始化，省去字面量后缀与 `static_cast` 的啰嗦。拷贝初始化、直接初始化同理。
- **浮点等级（由高到低）**：`long double` → `double` → `float`。
- **残余警告**：用落在范围内的 constexpr 值初始化更窄浮点类型是合法的，但编译器仍可能警告（GCC 和 Clang 在 `-Wconversion` 下会）。

## 最佳实践

- **Best practice**："Because they can be unsafe and are a source of errors, avoid narrowing conversions whenever possible."（由于可能不安全且是错误来源，尽量避免窄化转换。）
- **Best practice**："If you need to perform a narrowing conversion, use `static_cast` to convert it into an explicit conversion."（需要窄化时请用 `static_cast` 转为显式转换。）
- **Warning**："Conversion from a constexpr floating point type to a narrower floating point type is not considered narrowing even when a loss of precision results."（constexpr 浮点 → 更窄浮点在丢精度时也不视为窄化。）
- **Key insight**：浮点类型等级由高到低为 `long double`、`double`、`float`。

本节无 Author's note 条目。

## 代码示例

- [10-04-example1.cpp](10-04-example1.cpp)：函数调用中对有意的窄化转换使用 `static_cast` 以抑制警告（原示例 1）。
- [10-04-example2-error.cpp](10-04-example2-error.cpp)：`int i { 3.5 };` —— 花括号初始化拒绝窄化，预期编译失败（原示例 2）。
- [10-04-example3.cpp](10-04-example3.cpp)：在花括号内用 `static_cast` 允许窄化（原示例 3）。
- [10-04-example4.cpp](10-04-example4.cpp)：源值运行期才知，编译器无法判定是否保值（原示例 4）。
- [10-04-example5-error.cpp](10-04-example5-error.cpp)：constexpr 例外条款——保值可通过，变值则编译失败（原示例 5）。
- [10-04-example6-error.cpp](10-04-example6-error.cpp)：浮点 → 整型没有 constexpr 例外，`int n { 5.0 };` 预期编译失败（原示例 6）。
- [10-04-example7.cpp](10-04-example7.cpp)：constexpr `double` → `float` 不算窄化，即使丢精度（原示例 7）。
- [10-04-example8.cpp](10-04-example8.cpp)：constexpr 初始化让代码免去后缀与 `static_cast`（原示例 8）。
- [10-04-example9.cpp](10-04-example9.cpp)：用 `double` 字面量初始化 `float`，合法但丢精度（原示例 9）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。
