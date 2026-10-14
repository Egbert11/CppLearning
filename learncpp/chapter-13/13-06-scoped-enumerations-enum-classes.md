# 13.6 Scoped enumerations (enum classes)

> 原文：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/

## 核心概念

- **无作用域枚举不是类型安全的**：它们虽然是不同的类型，但编译器可以把它隐式转成整数，从而允许毫无意义的运算。
- **跨枚比较经由整数转换**：比较两个不同的枚举类型时，编译器退化为把它们都转成 `int`；例如 `Color::red` 与 `Fruit::banana` 值都是 0，于是比较结果为"相等"（输出 `color and fruit are equal`）。
- **语义 vs. 机制**：这种比较在语义上是错的——两个值来自毫不相关的枚举——而标准枚举没有简单的办法阻止它。
- **命名空间污染问题**：在全局作用域声明的无作用域枚举，其枚举量也落在全局命名空间里。
- **定义——有作用域枚举 / enum class**：用 `enum class` 关键字制作的更干净的替代品，与无作用域枚举有两点主要差异。
- **差异 1：不隐式转换为整数**：有作用域枚举量不会悄悄变成整数。
- **差异 2：枚举量的作用域**：枚举量*只*被放进枚举自身的作用域区域，而不进入外围作用域。
- **访问语法**：用 `Color::red` 这样的限定名访问——与命名空间一致。
- **比较规则**：比较同一个有作用域枚举内的枚举量是允许的（它们类型相同）；跨不同的有作用域枚举比较则是编译错误。
- **`enum struct` 等价**：`enum struct` 与 `enum class` 行为完全一致，但不合习惯用法，应避免。
- **关于 `class` 关键字的旁注**：`class` 是 C++ 中被重载得最厉害的关键字之一；有作用域枚举用了它，但**不是**"类类型"（类类型指 struct、class、union）。
- **命名空间化好处**：有作用域枚举实际上把枚举量做了命名空间化，减少了全局命名空间污染与命名冲突；除非另有理由，不必再把它嵌套进另一层作用域。
- **显式转整数**：用 `static_cast<int>(color)`；C++23 有更好的选择 `std::to_underlying()`（来自 `<utility>`），返回该枚举的底层类型。
- **从整数显式转换**：`static_cast<Pet>(input)` 可以把用户输入的整数转成有作用域枚举量。
- **C++17 列表初始化**：可以用整数值列表初始化有作用域枚举，无需 `static_cast`，也无需指定底层类型：`Pet pet { 1 };`
- **Best practice**：除非有充分理由，优先使用有作用域枚举而非无作用域枚举。
- **为什么无作用域枚举仍然存在**：有时确实想要隐式 `int` 转换，也不需要额外的命名空间化，否则到处 `static_cast` 会很烦人。
- **进阶技巧——重载一元 `operator+`**：重载一元 `+`（返回 `std::underlying_type_t<T>`）可以在不允许意外隐式转换的同时提供便利的显式转换（示例打印 `3`）。
- **`using enum` 语句（C++20）**：`using enum EnumName;` 把某个枚举的所有枚举量引入当前作用域，省去重复前缀，在 `switch` 中尤其方便。

## 最佳实践

- **Best practice**：除非有充分理由，优先使用有作用域枚举而非无作用域枚举。
- **Note**：同一个有作用域枚举内部的枚举量类型相同，因此可以比较。
- **Note（C++23）**：`std::to_underlying()` 比 `static_cast` 更适合把枚举量转成其底层类型。
- **Aside**：`class` 是 C++ 中被重载得最厉害的关键字之一；有作用域枚举用它，但并不属于"类类型"。

## 代码示例

- [13-06-example1-warning.cpp](13-06-example1-warning.cpp)：无作用域枚举跨类型比较，输出 `color and fruit are equal`（触发 `-Wenum-compare` 警告）。
- [13-06-example2-error.cpp](13-06-example2-error.cpp)：改成 `enum class` 后同样的比较变成编译错误。
- [13-06-example3-error.cpp](13-06-example3-error.cpp)：枚举量作用域受限（未限定名不可用）且不能隐式转 int。
- [13-06-example4.cpp](13-06-example4.cpp)：同一有作用域枚举内部比较合法，输出 `The shirt is red!`。
- [13-06-example5.cpp](13-06-example5.cpp)：用 `static_cast<int>` 输出枚举值，输出 `1`。
- [13-06-example5-cpp23.cpp](13-06-example5-cpp23.cpp)：C++23 用 `std::to_underlying` 输出 `1`（需 `-std=c++23`）。
- [13-06-example6.cpp](13-06-example6.cpp)：整数 `static_cast` 成有作用域枚举（输入）。
- [13-06-example7.cpp](13-06-example7.cpp)：C++17 用整数列表初始化有作用域枚举 `Pet pet { 1 };`。
- [13-06-example8.cpp](13-06-example8.cpp)：进阶的 `operator+` 一元重载，输出 `3`。
- [13-06-example9.cpp](13-06-example9.cpp)：C++20 `using enum` 让 `switch` 中不必重复前缀。
- [13-06-quiz1.cpp](13-06-quiz1.cpp)：测验解答，`Animal` 名字与腿数，输出 `A cat has 4 legs.` / `A chicken has 2 legs.`。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。原文各示例的预期输出已在 cpp 文件注释中标注。
