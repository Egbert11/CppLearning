# 7.6 Internal linkage

> 原文：https://www.learncpp.com/cpp-tutorial/internal-linkage/

## 核心概念

- **链接回顾（7.3）**：标识符的链接决定同名声明是否指向同一实体；局部变量无链接。
- **全局变量与函数的两种选择**：全局变量与函数标识符可以是**内部链接**或**外部链接**；本节讲内部，外部见 7.7。
- **内部链接的定义**：具内部链接的标识符 "can be seen and used within a single translation unit, but it is not accessible from other translation units."（可在单个翻译单元内看见并使用，但不能从其它翻译单元访问。）
- **跨文件不构成 ODR 问题**：若两个源文件各有同名的内部标识符，这些名字算作各自独立的实体，重复定义不违反 ODR。
- **Key insight（链接器的可见性）**："Identifiers with internal linkage may not be visible to the linker at all. Alternatively, they may be visible to the linker, but marked for use in a specific translation unit only."
- **术语**：具内部链接的全局变量称 **internal variables**。
- **把非 const 全局变量设为内部**：用 `static` 关键字；非 const 全局变量默认是外部链接。
- **const / constexpr 的默认**：`const` 与 `constexpr` 全局变量默认已是内部链接，不需要（写了也会被忽略）`static`。
- **进阶：存储类说明符（storage class specifier）**：此处的 `static` 是存储类说明符，它同时设定名字的链接与存储期；常见的还有 `extern`、`mutable`。
- **进阶：const 默认内部链接的缘由**：C++11 附录 C 说明该设计鼓励给出显式初始化式，以便 const 对象能放在被多个翻译单元包含的头文件中。
- **两种设计意图**：const 对象应能用于常量表达式（编译器需要可见的定义），且 const 对象应能通过头文件共享。
- **为何外部链接会出问题**：具外部链接的对象只能在一个翻译单元中定义；其它翻译单元需要前向声明，所以头文件里的 const 会造成 ODR 违规，且无法在别处用于常量表达式。
- **为何内部链接可行**：每个翻译单元都可以持有自己的定义而不违反 ODR，因此头文件里的 const 可被自由包含，同时仍可作为编译期值使用。内联变量（外部链接、无 ODR 问题）到 C++17 才出现。
- **函数**：函数标识符也有链接；默认外部，声明为 `static` 时变为内部，其它文件无法访问。
- **ODR 与内部链接**：在各自文件中定义的内部对象/函数，即使名字与类型相同也是独立实体，因此每个仍恰好只有一个定义。
- **`static` vs 未命名命名空间**：用 `static` 实现内部链接正逐渐不受青睐；未命名命名空间能覆盖更多种类的标识符（含类型），在标识符很多时更易扩展。
- **为什么要这么做**：两点理由——把标识符对其它文件隐藏（比如不想被外部触碰的全局变量、不想被外部调用的辅助函数）；以及避免程序范围内的命名冲突（内部名字不暴露给链接器）。
- **建议**：许多现代指南建议"凡是不打算给其它文件用的标识符都给予内部链接"；learncpp 给出更轻的最小做法：当你确有理由阻止外部访问时再这样做。

## 最佳实践

- **Best practice**：Give identifiers internal linkage when you have an explicit reason to disallow access from other files.（当你有明确理由不允许其它文件访问时，给标识符内部链接。）
- 后续建议：对不想暴露到别处的标识符都可以考虑此做法，此时用**未命名命名空间**。

## 代码示例

- [7-06-example1.cpp](7-06-example1.cpp)：`static int g_x` 与默认内部的 `const` / `constexpr` 全局变量，输出 `0 1 2`（对应原文 Example 1）。
- [7-06-example2/](7-06-example2/)：`a.cpp` / `main.cpp` —— 两个文件各自持有同名内部 `g_x`，互不冲突，输出 3（对应原文 Example 2）。

### 原文中"无法链接"的示例（仅说明，不生成文件）

- **Example 3（`static` 函数不可跨文件访问）**：`add.cpp` 中把 `add` 声明为 `static`（内部链接），`main.cpp` 前向声明 `int add(int, int);` 并调用。由于 `add` 是文件局部的，链接器找不到可供 `main.cpp` 使用的定义 → **链接错误（undefined reference）**。此例需要两个文件且其中一个是刻意的链接失败，无法表达为单个可构建文件，故不生成。相关文件片段如下：

```cpp
// add.cpp
// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}
```

```cpp
// main.cpp
int add(int x, int y); // forward declaration for function add

int main()
{
    std::cout << add(3, 4) << '\n'; // linker error: add is internal to add.cpp
    return 0;
}
```

### 原文 Quick Summary（速查，仅供参考）

```cpp
// Internal global variables definitions:
static int g_x;          // defines non-initialized internal global variable (zero initialized by default)
static int g_x{ 1 };     // defines initialized internal global variable

const int g_y { 2 };     // defines initialized internal global const variable
constexpr int g_y { 3 }; // defines initialized internal global constexpr variable

// Internal function definitions:
static int foo() {};     // defines internal function
```

> 说明：本节示例代码为按原文清单与站点标准写法**忠实重建**，以保证可用 `g++ -std=c++20 -Wall` 编译运行；原文代码块本身未逐字获取。
