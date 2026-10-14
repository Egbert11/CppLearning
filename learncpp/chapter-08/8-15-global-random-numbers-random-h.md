# 8.15 Global random numbers (Random.h)

> 原文：https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h/

## 核心概念

1. **跨文件的 PRNG 问题**：在多个函数或文件间复用随机数生成器，通常要在 `main()` 中创建一个并到处传递，而对于只是偶用一下的东西，这增加了杂乱。
2. **为什么不在每个函数里用 static 局部**：在每个需要随机数的函数中声明 `static std::mt19937`，它只播种一次，但在各处重复生成器很浪费，且每个生成器调用不频繁会降低结果质量。
3. **选定的方案**：使用一个共享的**全局** PRNG 对象，放在命名空间内，从而任何函数或文件都能访问。这是对"避免非 const 全局变量"这一常规建议的**明确例外**。
4. **仅头文件设计**：提供的头文件实现一个自播种的 Mersenne Twister，需要 C++17 或更新版本。
5. **`inline` 规则**：把 `mt` 与辅助函数标记为 `inline`，允许在多个翻译单元中有重复定义而不违反单一定义规则（ODR），只要每个定义完全相同。从同一个头文件包含它们实际上保证了这种相同性。
6. **为什么需要 `generate()` 辅助函数**：全局变量的初始化器必须是一个**表达式**，而播种 `std::mt19937` 需要基于语句的辅助对象。函数调用本身就是表达式，因此 `generate()` 构造并返回一个已播种的生成器。它还绕开了 `std::seed_seq` 不可复制、因而不能按值返回的问题。
7. **播种方式**：种子序列把系统时钟（`std::chrono::steady_clock`）与 7 个来自 `std::random_device` 的值组合在一起。
8. **三步用法**：(a) 把代码粘贴到项目目录下的 `Random.h`，保存（可选地加入项目）；(b) 在任何需要随机数的 .cpp 中 `#include "Random.h"`；(c) 调用 `Random::get(min, max)`。无需初始化或设置。
9. **重载选择规则**：如果两个参数类型相同，返回值就是该类型。如果参数类型不同，或你想要不同的返回类型，必须在尖括号里显式指定返回类型作为模板实参。
10. **直接访问生成器**：可以把 `Random::mt` 与你自己的分布一起使用，例如构建一个可复用的掷骰分布。

## 最佳实践

本节没有明确标注 "Best practice" / "Author's note" / "Warning" 的提示框。最接近的两处：

- **全局变量例外提示**：在推荐使用命名空间内的全局 PRNG 后，原文写道："Remember how we told you to avoid non-const global variables? This is an exception."（记得我们告诉过你要避免非 const 全局变量吗？这是个例外。）
- **Related content**：指出 7.9 节 "Inline functions and variables" 讲解支撑这种仅头文件写法的 inline 机制。

## 代码示例

多文件示例（放在子目录 [`8-15-example1/`](8-15-example1/) 中）：

- [`8-15-example1/Random.h`](8-15-example1/Random.h)：仅头文件、自播种的全局 Mersenne Twister（`Random::get` / `Random::mt` / `Random::generate`）。
- [`8-15-example1/main.cpp`](8-15-example1/main.cpp)：调用 `Random::get()`（同类型参数、显式返回类型）以及直接使用 `Random::mt`。

编译方式：`g++ -std=c++20 -Wall 8-15-example1/*.cpp`
