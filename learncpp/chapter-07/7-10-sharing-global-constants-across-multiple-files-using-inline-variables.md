# 7.10 Sharing global constants across multiple files (using inline variables)

> 原文：https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/

## 核心概念

- **为何集中共享常量**：像 pi、阿伏伽德罗常数、调参系数等值，多个文件都要用。只定义一次可避免违反 DRY 原则（"不要重复自己"），改动只需一处。
- **方式一：全局常量作为内部变量（C++17 之前）**：最简单的旧办法——在头文件里放一个装满 `constexpr` 常量的命名空间，需要处包含该头文件。因为 const 全局变量默认内部链接，每个 `.cpp` 都得到一份链接器看不见的私有副本。
- **该方式的问题**：头文件保护（include guard）只防止同一文件内重复包含，不能防止"每文件一份"。若在 20 个文件里包含该头文件，每个变量就有 20 份副本，会引起大范围重编译，并可能浪费内存。
- **方式二：全局常量作为外部变量**：在某个 `.cpp` 中用 `extern constexpr` 定义一次，头文件中放前向声明（写成 `extern const`，因为前向声明不能是 `constexpr`）。好处是只有一份实例、全程序共享，改值只需重编译那一个 `.cpp`。
- **外部方式的缺点**：在定义文件之外，编译器只看到非 constexpr 的前向声明，因此这些常量**无法用于常量表达式**，优化也可能较差。
- **关键要点（编译期可见性）**：要让变量用于编译期语境（如数组长度），编译器必须看到它的**定义**而非仅前向声明。由于文件单独编译，`constexpr` 变量无法头/源分离，必须定义在头文件中。
- **由此得到的建议**：常量优先定义在头文件中（上面任一方式或 inline 方式），只有那些"总在变、很麻烦"的常量才临时移到 `.cpp`。
- **方式三：全局常量作为内联变量（C++17）**：给 `constexpr` 变量加 `inline`，就能在头文件中定义并被任意处包含，允许多份完全相同的定义。既避免 ODR 违规，也避免变量重复。
- **隐式内联的提醒**：`constexpr` **函数**是隐式内联的，但 `constexpr` **变量**默认不是隐式内联的。
- **关键要点（链接性）**：**内联变量默认外部链接**，以便链接器可见（去重需要）；相反，非内联的 `constexpr` 变量是内部链接。
- **内联方式仍有的缺点**：改动头文件中的常量，仍会迫使所有包含它的文件重编译。
- **相关**：作用域、持久期与链接的总结见 7.12。

## 最佳实践

- **Best practice**：若可用 C++17，优先在头文件中定义 **inline constexpr** 全局变量。
- **关键要点（编译期可见性）**：变量必须被**定义**（而非仅前向声明），编译器才能在编译期语境（如数组长度）中使用它。
- **关键要点（链接性）**：内联变量默认外部链接，以便链接器去重；非内联 `constexpr` 变量则是内部链接，每个翻译单元一份私有副本。
- **提醒（inline 语义）**：`constexpr` 函数隐式内联，`constexpr` 变量不隐式内联；要得到内联的 `constexpr` 变量必须显式写 `inline`。
- **提醒（字符串）**：`constexpr` 字符串请使用 `std::string_view`。

## 代码示例

> 说明：本节的抓取工具限制了长代码块的逐字输出，以下 cpp 为按原文描述与该站标准示例忠实重建，语义与预期输出一致。
>
> 三种做法同名文件不同内容，故各自放入独立子文件夹。三个 `main.cpp` 均需交互输入半径。

- 方式一（内部链接，C++17 之前）：
  - [7-10-example1/constants.h](7-10-example1/constants.h) — 命名空间 `constants` 内 `constexpr` 常量（默认内部链接，对应 Example 1）。
  - [7-10-example1/main.cpp](7-10-example1/main.cpp) — 包含头文件并用 `constants::pi` 计算周长（对应 Example 2）。
- 方式二（外部链接，在 .cpp 中定义一次）：
  - [7-10-example2/constants.h](7-10-example2/constants.h) — 命名空间内的前向声明 `extern const double ...`（对应 Example 4）。
  - [7-10-example2/constants.cpp](7-10-example2/constants.cpp) — `extern constexpr double ...` 定义（对应 Example 3）。
  - [7-10-example2/main.cpp](7-10-example2/main.cpp) — 用法不变（对应 Example 5）。
- 方式三（内联变量，C++17）：
  - [7-10-example3/constants.h](7-10-example3/constants.h) — `inline constexpr double ...`（对应 Example 6）。
  - [7-10-example3/main.cpp](7-10-example3/main.cpp) — 用法不变，可被任意多个文件包含而只实例化一次（对应 Example 7）。

预期输出（输入半径 2 时）：`The circumference is: 12.5664`
