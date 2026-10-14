# 10.6 Explicit type conversion (casting) and static_cast

> 原文：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/

## 核心概念

- **变宽时隐式转换没问题**：把数值从一种类型提升到更宽的类型时，让编译器自动转换是合适的。
- **整数除法陷阱**：写 `double d = 10 / 4;` 会先做整数除法得到 `int` 值 `2`，再转成 `2.0`——通常并非本意。
- **字面量的修法**：如果操作数是字面量，把其中一个或两个整数字面量改成 double 字面量即可做浮点除法。
- **变量的问题**：面对变量 `x`、`y`，没法加字面量后缀，需要有办法把某个操作数转成浮点类型。
- **转换运算符 / 强制转换（casts / type casting operators）**：C++ 提供的、让程序员指示编译器做转换的运算符。
- **显式类型转换（explicit type conversion）**：因为是程序员主动要求的，所以相对自动的隐式转换而称为显式类型转换。
- **五种转换**：`static_cast`、`dynamic_cast`、`const_cast`、`reinterpret_cast`，以及 C 风格转换；前四种称为**具名转换（named casts）**。
- **转换安全性汇总（表）**：

  | 转换 | 作用 | 安全 |
  |---|---|---|
  | `static_cast` | 编译期在相关类型之间转换 | 是 |
  | `dynamic_cast` | 运行期在多态继承体系的指针/引用间转换 | 是 |
  | `const_cast` | 增删 `const` | 仅加 `const` 时 |
  | `reinterpret_cast` | 把一个类型的位级表示重解释为另一个类型 | 否 |
  | C 风格转换 | 执行上述若干种转换的某种组合 | 否 |

- **统一机制**：每种转换都接受一个表达式（值或对象）和一个目标类型，返回转换结果。
- **本节范围**：C 风格转换和 `static_cast` 是最常用的，本节讲解它们。
- **延后 / 不推荐**：`dynamic_cast` 留到有前置知识后讲；`const_cast` 与 `reinterpret_cast` 一般应避免，因为它们很少有用且可能有害。
- **C 风格转换定义**：C 用 `operator()` 做转换，把目标类型名括起来、值紧跟右括号；C++ 称之为 C 风格转换，在从 C 迁移来的代码里仍能见到。
- **函数式转换（function-style cast）**：C 风格转换的另一种形式，看起来像函数调用，更容易看清被转换的东西。
- **为什么避免 C 风格转换（两个原因）**：
  1. 一个 C 风格转换可能悄悄完成 static、const 或 reinterpret 转换，看不出究竟做了哪种，损害可读性，也容易无意误用、可能到运行期才暴露。
  2. 它只是一个类型名、括号和一个值，难以识别、难以检索。
- **具名转换的优势**：容易看出、容易检索，意图清楚，能力受限，误用会产生编译错误。
- **C 风格转换的特殊能力（高级）**：它能把派生对象转成不可访问的基类（如私有继承），这是 C++ 转换做不到的。
- **static_cast 是最常用的转换**：通过 `static_cast` 关键字访问，用于把一种类型的值显式转换成另一种。
- **static_cast 语法**：先写 `static_cast`，尖括号里写目标类型，圆括号里写要转换的表达式；形似函数调用，返回一个用转换结果直接初始化的临时对象。
- **编译期类型检查**：如果编译器不知道怎么完成所请求的转换，就会编译报错。
- **有意更弱**：`static_cast` 禁止某些危险转换，例如需要重解释或丢弃 const 的转换。
- **让窄化转换显式化**：编译器通常会对可能不安全的隐式窄化（如 `int` → `char`、`double` → `int`）发出警告；static cast 告诉编译器该转换是有意且可接受的。
- **转换 vs 初始化临时量**：两种惯用写法——`static_cast<int>(x)`（直接初始化的临时量）与 `int { x }`（直接列表初始化的临时量）。`int ( x )` 是 C 风格转换，应避免。
- **两种写法的三点差异**：
  1. 列表初始化禁止窄化转换——初始化变量时是好事，但需要有意丢数据的转换时会碍事（还可能导致平台相关的编译失败，如 64 位 `int` 转 `double`）。
  2. `static_cast` 使意图的转换更清楚；虽然更啰嗦，但更易发现与检索，代码更安全易懂。
  3. 直接列表初始化一个临时量只允许单词类型名（"simple type specifiers"），所以 `int { x }` 行，`unsigned int { x }` 不行；可用单词类型别名绕过。
- **总体偏好**：基于以上原因，需要转换时一般首选 `static_cast`，而非直接列表初始化临时量。

## 最佳实践

- **Warning**：除非有很好的理由，避免 `const_cast` 和 `reinterpret_cast`。
- **Best practice（C 风格转换）**：避免使用 C 风格转换。
- **Best practice（选择转换）**：需要在类型之间转换值时，优先用 `static_cast`。
- **Best practice（转换 vs 临时量）**：需要转换时，优先用 `static_cast` 而非初始化临时对象。
- **For advanced readers（C 风格转换的解析顺序）**：C 风格转换按序尝试：`const_cast`；`static_cast`；`static_cast` 加 `const_cast`；`reinterpret_cast`；`reinterpret_cast` 加 `const_cast`。
- **For advanced readers（static_cast 与构造函数）**：因为 `static_cast` 使用直接初始化，它也会考虑目标类类型的显式构造函数来初始化返回的临时对象。
- **Related content**：`dynamic_cast` 见 25.10《Dynamic casting》；`static_cast` 与类类型的更多用法见 14.13《Temporary class objects》。

## 代码示例

- [10-06-example1.cpp](10-06-example1.cpp)：整数除法陷阱——`10 / 4` 得 `2.0` 而非 `2.5`（原示例 1~3）。
- [10-06-example2.cpp](10-06-example2.cpp)：C 风格转换与函数式转换强制做浮点除法（原示例 4、5）。
- [10-06-example3.cpp](10-06-example3.cpp)：用 `static_cast` 把 `char` 打印成整数（原示例 6）。
- [10-06-example4.cpp](10-06-example4.cpp)：用 `static_cast<double>` 解决整数除法问题（原示例 7）。
- [10-06-example5-error.cpp](10-06-example5-error.cpp)：`static_cast<int>("Hello")` —— 无效转换，预期编译失败（原示例 8）。
- [10-06-example6.cpp](10-06-example6.cpp)：隐式窄化会警告，`static_cast<char>` 显式窄化则不警告（原示例 9、10）。
- [10-06-example7-warning.cpp](10-06-example7-warning.cpp)：`i = i / 2.5;` 可能警告，用显式 `static_cast` 消除（原示例 11、12）。
- [10-06-example8-warning.cpp](10-06-example8-warning.cpp)：`double{x} / y` 直接列表初始化临时量（原示例 13）。
- [10-06-example9-error.cpp](10-06-example9-error.cpp)：`unsigned int { c }` 多词类型名列表初始化，预期编译失败（原示例 14）。
- [10-06-example10.cpp](10-06-example10.cpp)：用单词类型别名 `uint` 绕过上述限制（原示例 15）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

## 测验

**题目 1**：隐式类型转换与显式类型转换有什么区别？

**解答**：隐式转换在提供了与预期不同的数据类型时自动发生；显式转换发生在程序员使用类型转换（cast）有意地把值从一种类型转成另一种类型时。对应代码见 [10-06-quiz1.cpp](10-06-quiz1.cpp)。
