# 13.13 Class templates

> 原文：https://www.learncpp.com/cpp-tutorial/class-templates/

## 核心概念

- **普通函数的冗余问题**：为每种类型各写一个重载（如 `int` 版和 `double` 版 `max`）会重复相同逻辑；函数模板解决了这一点。
- **聚合类型同样有此问题**：struct、class、union、数组都会遇到与函数相同的重复问题。
- **朴素 struct 做法失败**：想定义两个 `Pair` struct 会被拒绝，因为"类型定义不能重载"；第二个被视为对第一个的重复声明。
- **仅按返回类型重载失败**：即便函数，也只有当签名不同时才能重载；规则是"重载函数不能仅靠返回类型区分"。
- **三个明确的问题**：类型定义不可重载、仅返回类型不同的重载非法、大量代码冗余。
- **改名只是部分修复**：用 `PairInt`/`PairDouble` 这样的不同名字能编译，但你得记住这套命名规则，且仍在克隆代码。
- **类模板定义**：按教程，"类模板是用于实例化类类型的模板定义"。
- **类类型提醒**："类类型（class type）是 struct、class 或 union 类型。"示例用 struct，但规则同样适用于 class。
- **模板参数声明语法**：以 `template` 关键字开头，随后尖括号中列出各模板类型；优先用 `typename` 而非 `class`，后跟一个名字如 `T`。
- **使用模板类型**：在定义内部照常书写 struct，把将来会被替换成真实类型的位置写成 `T`。
- **使用时实例化**：`Pair<int>` 会让编译器生成一份把 `T` 替换为 `int` 的类型定义；`Pair<double>` 同理。
- **实例化会被缓存**：第二次使用 `Pair<double>`（例如给 `p3`）会复用之前生成的定义，而非重新生成。
- **编译器展开视图**：教程给出实例化后等价的代码，用显式特化 `Pair<int>`、`Pair<double>` 加一个主模板的声明表示。
- **进阶**：该展开依赖类模板特化（后续小节内容），现阶段不必掌握。
- **对实例化类型重载**：因为 `Pair<int>` 与 `Pair<double>` 是不同类型，按参数类型区分的两个 `max` 重载可以编译——但冗余仍在。
- **接受 `Pair<T>` 的函数模板**：要接受任意类型的 pair，把 `max` 写成函数模板，参数为 `Pair<T>`；`T` 在函数前声明，同时用于返回类型与 pair 的元素类型。
- **调用如何展开**：用 `Pair<int>` 实参调用时，会实例化 `T` 变成 `int` 的特化版本。
- **显式 vs 推导实参**：可以写明（如 `max<int>(p1)`），也可以省略让模板实参推导来推断；教程推荐隐式形式。
- **模板与非模板成员混用**：类模板可以一部分成员由模板参数决定类型，另一部分用固定的普通类型如 `int`。
- **多个模板类型**：用逗号分隔多个参数（如 `template <typename T, typename U>`）；提供的实参可同可异。
- **约束函数模板**：把参数声明为 `Pair<T, U>` 可把匹配限制为该类型（或可转换类型）；用普通类型模板参数则会匹配任何东西。
- **鸭子类型式的灵活性**：单个参数 `print(T p)` 对任何"拥有 `first` 和 `second` 成员"的类型都能编译，因此对 `Pair` 和不相关的 `Point` 都可用。
- **遮蔽陷阱**：把模板参数命名为 `Pair` 会遮蔽类类型 `Pair`，于是函数会静默地匹配任意类型而不只是 `Pair` 对象。
- **命名建议**：坚持用简单的模板参数名，如 `T`、`U`、`N`，以免遮蔽类类型。
- **`std::pair`**：标准库 `<utility>` 头提供 `std::pair`（含 `first`、`second` 成员），定义本质上与两参数的 `Pair` 示例相同。
- **优先用标准类型**："在实际代码中，应优先用 `std::pair` 而不是自己写一个。"
- **多文件使用**：与函数模板一样，类模板应放在头文件中以便按需包含；"模板定义和类型定义都豁免于单一定义规则（ODR）"。

## 最佳实践

本节无 Best practice / Rule / Warning 条目。相关 callout：

- **Related content**：函数模板实例化的工作方式见前文小节。
- **Author's note**：若对模板类型或实例化不清楚，建议先复习"函数模板"与"函数模板实例化"两节。
- **A reminder**：类类型涵盖 struct、class 或 union；示例用 struct，但规则对 class 同样成立。
- **For advanced readers**：编译器展开的示例用到类模板特化（未来小节），现阶段无需了解。

## 代码示例

- [13-13-example1.cpp](13-13-example1.cpp)：为 `int`、`double` 各写一个重载 `max`，演示模板要消除的重复（原 Example 1）。
- [13-13-example2.cpp](13-13-example2.cpp)：单个函数模板 `max(T, T)` 替代两个重载（原 Example 2）。
- [13-13-example3.cpp](13-13-example3.cpp)：普通 `Pair`（两个 `int`）加 `max(Pair)` 的非模板做法（原 Example 3）。
- [13-13-example4-error.cpp](13-13-example4-error.cpp)：定义两个 `Pair`、以及仅返回类型不同的 `max` 重载 —— 预期编译失败（原 Example 4）。
- [13-13-example5.cpp](13-13-example5.cpp)：把 `Pair` 改写为 `template <typename T> struct Pair` 并实例化（原 Example 5）。
- [13-13-example6.cpp](13-13-example6.cpp)：`Pair` 类模板配合 `max` 函数模板，显式调用与推导调用（原 Example 7、8、9）。
- [13-13-example7.cpp](13-13-example7.cpp)：`Foo` 模板混用模板成员 `T first` 与固定 `int second`（原 Example 10）。
- [13-13-example8.cpp](13-13-example8.cpp)：两参数 `Pair<T, U>` 加 `print(Pair<T, U>)` 函数模板（原 Example 11、12）。
- [13-13-example9.cpp](13-13-example9.cpp)：鸭子类型的 `print(T)`，对 `Pair` 与 `Point` 都可用（原 Example 13）。
- [13-13-example10.cpp](13-13-example10.cpp)：把模板参数命名为 `Pair` 造成的遮蔽（原 Example 14）。
- [13-13-example11.cpp](13-13-example11.cpp)：改用标准库 `std::pair` 与 `print(std::pair<T,U>)`（原 Example 15）。
- [13-13-example12/](13-13-example12/)：多文件示例 `pair.h` + `foo.cpp` + `main.cpp`（原 Example 16）。

> 说明：本节代码为按原文清单与站点标准写法重建。

## 编译说明

多文件示例用通配符编译：

```
g++ -std=c++20 -Wall 13-13-example12/*.cpp -o example12
```
