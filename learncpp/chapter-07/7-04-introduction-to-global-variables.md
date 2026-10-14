# 7.4 Introduction to global variables

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/

## 核心概念

- **局部变量回顾**：在函数体内定义，具有块作用域（仅在其块内可见）与自动存储期（定义处创建、块退出销毁）。
- **全局变量（global variables）**：在任何函数之外声明的变量。
- **声明惯例**：按惯例，全局变量放在文件顶部、`#include` 之后，位于全局命名空间中。
- **全局变量的作用域**：全局命名空间里的标识符具有**全局命名空间作用域**（也叫全局作用域，非正式称文件作用域 file scope）。它们从声明点起、到文件末尾都可见；一旦声明，之后可在文件任意处使用。
- **用户自定义命名空间里的全局变量**：全局变量也可定义在用户自定义命名空间中；此时名字限定在该命名空间作用域内，但仍可通过命名空间限定符全局访问，因此仍是全局变量。
- **Key insight**："Variables declared inside a namespace are also global variables."（在命名空间内声明的变量也是全局变量。）
- **静态存储期（static duration）**：全局变量在程序启动时（`main()` 之前）创建，在程序结束时销毁。具静态存储期的变量有时称**静态变量（static variables）**。
- **命名惯例**：有些开发者用 `g` 或 `g_` 前缀命名全局标识符。好处：避免全局命名空间中的命名冲突、避免无意的名字遮蔽、并提示"对该变量的修改会跨函数持续"。放在用户自定义命名空间里的全局变量常省略前缀（前两个顾虑不再适用，且命名空间名已表明其全局性）。
- **初始化**：与局部变量（默认未初始化）不同，静态存储期的变量默认**零初始化**。非 const 全局变量可选择是否初始化。
- **常量全局变量**：全局变量可以是常量；与所有常量一样，必须初始化。
- **非 const 全局变量的告诫**：新手常因为可以省去显式传参而大量使用全局变量，但非 const 全局变量的使用总体应避免。

## 最佳实践

- **Best practice**：Prefer defining global variables inside a namespace rather than in the global namespace.（优先把全局变量定义在命名空间里而不是全局命名空间。）
- **Best practice**：考虑给全局变量（尤其是全局命名空间中的）加 `g` 或 `g_` 前缀，以区别于局部变量与形参。
- **Key insight**：命名空间内声明的变量也是全局变量。
- **Author's note**：有人质疑 `g_` 之类前缀是匈牙利命名法、而"匈牙利命名法不好"。反对主要针对把**类型**编码进名字（如 `nAge` 的 `n` 表示 `int`），在现代 C++ 中没什么用；而用前缀表达**作用域/存储期**（`g`/`g_`、`s`/`s_`、`m`/`m_`）是有价值的。
- **Warning**：非 const 全局变量的使用 "should generally be avoided altogether!"（总体上应完全避免）。原因见 7.8。
- **延伸阅读**：全局常量详见 7.10。

## 代码示例

- [7-04-example1.cpp](7-04-example1.cpp)：全局命名空间里的 `g_x`，被两个函数使用，输出 3、3、5（对应原文 Example 1）。
- [7-04-example2.cpp](7-04-example2.cpp)：把 `g_x` 移入 `Foo` 命名空间，用 `Foo::g_x` 访问（对应原文 Example 2）。
- [7-04-example3.cpp](7-04-example3.cpp)：非 const 全局变量的三种初始化写法，输出 `0 0 1`（对应原文 Example 3）。
- [7-04-example4.cpp](7-04-example4.cpp)：`const` / `constexpr` 全局变量示例，输出 1、2、1、2（对应原文 Example 4 有效部分）。
- [7-04-example4-error.cpp](7-04-example4-error.cpp)：**预期编译失败**——未初始化的 `const` / `constexpr` 全局变量（对应原文 Example 4 错误部分）。

### 原文 Quick Summary（速查，仅供参考）

```cpp
// Non-constant global variables
int g_x;                 // defines non-initialized global variable (zero initialized by default)
int g_x {};              // defines explicitly value-initialized global variable
int g_x { 1 };           // defines explicitly initialized global variable

// Const global variables
const int g_y;           // error: const variables must be initialized
const int g_y { 2 };     // defines initialized global const

// Constexpr global variables
constexpr int g_y;       // error: constexpr variables must be initialized
constexpr int g_y { 3 }; // defines initialized global constexpr
```

> 说明：本节示例代码为按原文清单与站点标准写法**忠实重建**，以保证可用 `g++ -std=c++20 -Wall` 编译运行；原文代码块本身未逐字获取。
