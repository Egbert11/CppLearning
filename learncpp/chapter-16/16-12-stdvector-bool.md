# 16.12 std::vector<bool>

> 原文：https://www.learncpp.com/cpp-tutorial/stdvector-bool/

## 核心概念

- **`std::bitset` 的位压缩**：`std::bitset` 能把 8 个布尔值压进一个字节，并可通过其成员函数逐位修改。
- **`std::vector<bool>` 的特殊实现**：`std::vector<bool>` 可能采用一种特殊形式，同样把 8 个布尔值压进一个字节，从而可能节省空间。
- **类模板特化（class template specialization）**：为某个特定的模板类型实参提供不同实现，就叫类模板特化。
- **没有位操作成员函数**：与 `std::bitset` 不同，`std::vector<bool>` 不提供直接做位操作的成员函数。
- **基本用法与普通 vector 类似**：大多数操作下 `std::vector<bool>` 表现得就像普通 `std::vector`——可初始化、可遍历、可给元素赋值。
- **代价：额外开销**：`std::vector<bool>` 有可观的开销；作者报告其机器上 `sizeof(std::vector<bool>)` 为 40 字节，所以只有当存储的布尔值远多于这个开销时，省空间才有意义。
- **代价：性能依实现而异**：性能高度依赖实现。优化良好的实现可以快很多，优化糟糕的可能更慢。
- **代价：既不是真正的 vector、也不是容器**：`std::vector<bool>` 不要求连续存储、不实际保存 `bool` 值，也不满足 C++ 对容器的定义。
- **与通用标准库风格代码不兼容**：因为它不是真正的容器，很多能作用于其他元素类型的代码用到 `std::vector<bool>` 上会失败。
- **总建议：避免使用 `std::vector<bool>`**：现代共识是回避它，因为其性能收益通常抵不上不兼容带来的麻烦。
- **优化版是默认且无法关闭**：压缩实现在默认下启用，也没有标准办法切换到那种"表现得像真正容器"的非优化版本。
- **未来可能被替换**：有人呼吁弃用 `std::vector<bool>`，同时正在推进一种压缩布尔容器，也许未来会是一个 `std::dynamic_bitset`。
- **替代方案推荐**：
  - 当位数在编译期已知、数量适中（例如少于 64k）、且其有限的运算符/成员函数够用时，用 `constexpr std::bitset`；
  - 当不需要省空间、又想要可调整大小的"类布尔"容器时，优先用 `std::vector<char>`；
  - 当需要带位操作的动态 bitset 时，用第三方库的动态 bitset，如 `boost::dynamic_bitset`。

## 最佳实践

- **For advanced readers**：当某个模板类对特定模板类型实参有不同实现时，称为类模板特化（详见 26.4）。
- **Best practice**：优先选择 `constexpr std::bitset`、`std::vector<char>` 或第三方动态 bitset，而不要用 `std::vector<bool>`。

## 代码示例

- [16-12-example1.cpp](16-12-example1.cpp)：`std::vector<bool>` 的创建、遍历与逐元素修改（原 Example 1）。
- [16-12-example2.cpp](16-12-example2.cpp)：接受元素引用的泛型函数，`T` 为除 `bool` 外的任何类型都能工作（原 Example 2）。

> 说明：本节代码为按原文描述重建。Example 2 原文为函数模板片段，此处包进 `main()` 补全为可编译程序；其反面情形（`T = bool` 时 `T& first = v[0]` 无法编译）见该文件注释。
