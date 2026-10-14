# 13.y Using a language reference

> 原文：https://www.learncpp.com/cpp-tutorial/using-a-language-reference/
>
> 说明：本小节为 Chapter 13 末尾的 y 编号小节，官方编号为 **13.y**；按本仓库约定，其文件编号取顺延号，即 **17**。

## 核心概念

- **教程有局限**：LearnCpp.com 以初学者友好的方式讲解概念，但无法覆盖语言的每一处，最终仍需要外部资源。
- **Stack Overflow 是第一站**：可以在那里提问，或阅读别人问过同样问题后已给出的答案。
- **参考指南 vs 教程**：教程用非正式语言强调最重要的主题；参考指南用正式术语精确描述 C++，通常全面而准确，但不易读。
- **Cppreference**：广泛使用的标准参考，本教程也常引用它，并用三个例子做演示。
- **总览页**：进入 cppreference 的总览页可找到它提供的一切，但直接搜索更方便；页面上半部列出语言中已有的特性，下半部列出技术规范。
- **技术规范（technical specifications）**：可能在未来版本加入、或已被部分接受的特性；用于预览即将到来的能力。
- **标准版本标记**：自 C++11 起，cppreference 用其加入的标准版本给特性打标记；链接旁的绿色数字即该版本，没有数字的特性可追溯到 C++98/03。
- **版本号随处可见**：它们不限于总览页，因此可以确切知道某 C++ 版本中什么可用。
- **定位 `std::string`**：搜索 "string" 会进入 Strings 库页面，其中 `std::basic_string` 段落列出各 typedef，包括 `std::string`。
- **`std::string` 是个 typedef**：没有专门的 `std::string` 页面，因为它就是 `std::basic_string<char>`（见 typedef 列表）。
- **`<char>` 参数的含义**：表示字符串中每个字符都是 `char` 类型；其它字符串用不同字符类型，有助于处理 Unicode 而非 ASCII。
- **成员函数列表**：同页更下方有一张成员函数表（类型的各种行为），是"该类型能做什么"的便捷索引。
- **`length` 与 `size`**：都在该列表中出现，按其共享的详情页，"两者做的是同一件事"。
- **参考页的解剖**：顶部是简短摘要加语法/重载/声明；标题给出类与函数及全部模板参数；接着是各重载及其适用标准；再是参数与返回值含义。
- **读看不懂的示例**：示例常用到没见过的特性；看多了仍能把握用法，示例里陌生的函数/类型还可以点进去读它们自己的参考页。
- **查找 `std::cin.ignore`**：直接搜索不清晰，教程改从 `std::cin` 进入并沿链接走到 `std::istream`。
- **`istream` 也是 typedef**：`std::istream` 原来是 `basic_istream` 的 typedef 名，所以之前的搜索结果并不算错。
- **`cin` 声明页**：它给出 `std::cin` 与 `std::wcin` 的声明，指明 `std::cin` 是 `std::istream` 类型的对象，并说明应包含哪个头文件。
- **默认实参**：形参后面的 `=` 表示默认实参（见 11.5）；若未给该形参提供实参，就用默认值。
- **`max()` 的特殊值**：`std::numeric_limits<std::streamsize>::max()` 对 `std::cin.ignore` 有特殊含义：它**关闭**字符计数检查，于是忽略会一直进行到分隔符或输入字符耗尽为止。
- **参数描述是简略的**：参数/返回值的简述省略了特殊处理与停止条件，只能当提醒用。
- **语法文档**：除标准库外，cppreference 也记录 C++ 语言语法。
- **`if` 中的 init-statement**：语法 `if ( init-statement condition ) statement-true`（可有 else 形式）包含一个可选的 `init-statement`，通常是一个带初始化器的变量声明。
- **作用域规则**：`init-statement` 里的名字在**真、假两个分支**都可见，这可能让"以为只在真分支可见"的读者感到意外。
- **对付难例**：太绕的先跳过，直到找到能用的示例；`std::lock_guard` 那个例子把机制讲清楚了——定义一个变量，然后分号，然后是条件。
- **Cppreference 是 wiki**：它不是官方文档；内容来自社区，可能出现错误，但通常会被迅速发现并删除，因此相当可靠。
- **唯一官方来源**：C++ 标准（正式、不易用作参考）才是唯一的官方来源；标准草案可免费获取。

## 最佳实践

本节无 Best practice / Author's note 条目。相关 callout：

- **Warning（搜索引擎）**：某个规范刚被标准采纳后不久，搜索引擎可能把你带到技术规范而非正式参考页，而两者可能不同。
- **Tip（C 与 C++ 参考）**：由于 C++ 与 C 共用一些函数名，搜索可能落到 C 参考页；URL 与顶部导航栏总能表明你身处哪个参考。
- **Tip（测验 1 处理 `erase`）**：在 cppreference 找到 `erase` 后，"可以忽略那些使用迭代器的重载"。
- **Tip（测验 1 下标）**：C++ 下标从 0 开始："House" 的下标 0 是 'H'，下标 1 是 'o'，以此类推。
- **Warning（cppreference 的准确性）**：cppreference 不是官方文档，而是任何人都可编辑的 wiki；错误信息通常会被迅速发现并移除，因此较可靠，但 C++ 标准仍是唯一官方来源，且"是一份正式文档，不易用作参考"。

## 代码示例

- [13-17-example1.cpp](13-17-example1.cpp)：在 `if` 条件中使用变量定义（init-statement）（原 Example 1）。
- [13-17-example2.cpp](13-17-example2.cpp)：`std::lock_guard lock(mx)` 作为 init-statement（教程选出的最清晰一例）（原 Example 3）。
- [13-17-quiz1.cpp](13-17-quiz1.cpp)：测验 1 解答——`str.erase(4, 11)`，预测输出（打印 "The king"）（原 Example 4）。
- [13-17-quiz2.cpp](13-17-quiz2.cpp)：测验 2 解答——用一次 `str.replace(8, 3, "blue")` 把 "red" 换成 "blue"（原 Example 6）。

> 说明：本节代码为按原文清单与站点标准写法重建。原文 Example 2 是一串渐进难读的 init-statement 片段（引用未定义的 `m`、`it`、`s` 等），无法独立编译，故不生成文件；Example 5 只是测验 2 的起始模板，不单独建文件。

## 测验

- **Q1**：预测下面程序的输出，并解释。答案：`The rice is cooking` 执行 `str.erase(4, 11)` 后打印 **"The king"**——`erase` 的该重载从下标 4 起删除 `min(count, size() - index) = min(11, 19 - 4) = 11` 个字符。见 [13-17-quiz1.cpp](13-17-quiz1.cpp)。
- **Q2**：把 `"I saw a red car yesterday."` 中的 "red" 换成 "blue"，只用一次对 `str` 的调用。答案：`str.replace(8, 3, "blue");`。见 [13-17-quiz2.cpp](13-17-quiz2.cpp)。
