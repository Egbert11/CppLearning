# 7.7 External linkage and variable forward declarations

> 原文：https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/

## 核心概念

- **外部链接（external linkage）定义**：具外部链接的标识符既可在定义它的文件中使用，也可通过前向声明在其它文件中使用；这类标识符是"真正的全局"。
- **Key insight（链接器可见）**：具外部链接的标识符对链接器可见，链接器因此能够 (a) 把某翻译单元里使用的标识符与另一翻译单元中的定义连接起来；(b) 对**内联**标识符去重，只保留一个规范定义（见 7.9）。
- **函数默认外部链接**：这就是一个文件中定义的函数能被另一文件调用的原因；每个使用它的文件都要写前向声明（满足编译器），链接器再把调用连到定义。
- **若函数改为内部链接**：链接器无法把调用连到定义，于是产生链接错误。
- **具外部链接的全局变量**：也叫 **external variables**。非 const 全局变量默认外部（不必写 `extern`）；const 与 constexpr 全局变量可用 `extern` 使其外部（constexpr 情形本节称为"pretty useless"）。
- **变量前向声明用 `extern`**：要使用在另一文件定义的外部全局变量，需在使用文件中写一条 `extern` 声明（不带初始化式）。示例中 `main.cpp` 前向声明 `g_x`、`g_y`，`a.cpp` 定义它们，二者引用同一个变量。
- **`extern` 有两层含义**：某些上下文里表示"给这个变量外部链接"；另一些上下文里表示"这是对别处定义的外部变量的前向声明"。完整总结见 7.12。
- **Warning（未初始化的非 const 全局变量）**：定义未初始化的非 const 全局变量时**不要**用 `extern`，否则 C++ 会把它当作前向声明。
- **Warning（constexpr 不能前向声明）**：constexpr 变量可用 `extern` 赋予外部链接，但**不能**以前向声明方式声明为 constexpr——因为编译器需要编译期就知道值，而看不到其它文件里的定义。可以把 constexpr 变量前向声明为 `const`（当作运行期 const），但这"不太有用"。
- **为何变量需要 `extern` 而函数不需要**：编译器靠"是否有函数体"区分函数定义与声明；而变量在无初始化式时的定义与声明形式完全相同，所以必须用 `extern` 区分。
- **避免对外部初始化式的非 const 全局变量写 `extern`**：两种写法语义等价，但显式 `extern` 的版本可能引发编译器警告；编译器是在提示"加上初始化式后，声明变成了定义"。修法：若本意是声明就删掉初始化式；若本意是定义就删掉 `extern`。

## 最佳实践

- **Best practice**：Only use `extern` for global variable forward declarations or const global variable definitions. Do not use `extern` for non-const global variable definitions (they are implicitly `extern`).（只把 `extern` 用于全局变量前向声明或 const 全局变量定义；不要用它定义非 const 全局变量。）
- **Key insight**：具外部链接的标识符对链接器可见，链接器借此连接跨翻译单元的引用，并对内联标识符去重（见 7.9）。
- **Warning**：定义未初始化的非 const 全局变量时不要用 `extern`。
- **Warning**：constexpr 变量可经 `extern` 获得外部链接，但不能以前向声明方式声明为 constexpr；可先声明为 `const`，但不太有用。

## 代码示例

- [7-07-example1/](7-07-example1/)：`a.cpp` 定义外部链接的 `sayHi()`，`main.cpp` 前向声明并调用，输出 `Hi!`（对应原文 Example 1 + Example 2）。
- [7-07-example3.cpp](7-07-example3.cpp)：定义外部全局变量——非 const 默认外部，`extern const` / `extern constexpr` 显式外部（对应原文 Example 3）。
- [7-07-example4/](7-07-example4/)：`a.cpp` 定义 `g_x`、`g_y`，`main.cpp` 用 `extern` 前向声明并打印，输出 `2 3`（对应原文 Example 4 + Example 5）。
- [7-07-example7-warning.cpp](7-07-example7-warning.cpp)：**预期产生警告**——`extern int g_x2 { 1 };` 被 GCC 提示 `initialized and declared 'extern'`（对应原文 Example 7）。

### 原文中的其它示例（速查，仅供参考）

```cpp
// Example 6: telling definitions apart from forward declarations
// non-constant
int g_x;        // variable definition (no initializer)
int g_x { 1 };  // variable definition (w/ initializer)
extern int g_x; // forward declaration (no initializer)

// constant
extern const int g_y { 1 }; // variable definition (const requires initializers)
extern const int g_y;       // forward declaration (no initializer)
```

```cpp
// Example 8: Quick summary of declarations and definitions
// Global variable forward declarations (extern w/ no initializer):
extern int g_y;                 // forward declaration for non-constant global variable
extern const int g_y;           // forward declaration for const global variable
extern constexpr int g_y;       // not allowed: constexpr variables can't be forward declared

// External global variable definitions (no extern)
int g_x;                        // defines non-initialized external global variable (zero initialized by default)
int g_x { 1 };                  // defines initialized external global variable

// External const global variable definitions (extern w/ initializer)
extern const int g_x { 2 };     // defines initialized const external global variable
extern constexpr int g_x { 3 }; // defines initialized constexpr external global variable
```

## 测验（本节末尾小结）

- 作用域决定变量在哪里可访问；存储期决定它何时被创建与销毁；链接决定它能否被导出到另一个文件。
- 全局变量：文件/全局作用域，静态存储期（程序启动时创建、结束时销毁），链接为内部（`static`）或外部（`extern`）。

> 说明：本节示例代码为按原文清单与站点标准写法**忠实重建**，以保证可用 `g++ -std=c++20 -Wall` 编译运行；原文代码块本身未逐字获取。
