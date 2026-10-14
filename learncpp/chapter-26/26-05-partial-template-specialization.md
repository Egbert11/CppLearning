# 26.5 Partial template specialization

> 原文：https://www.learncpp.com/cpp-tutorial/partial-template-specialization/

## 核心概念

- **可选/进阶话题**：本节与下一节是给想深入了解模板的人准备的可选阅读，因为偏特化"用得并不算多"。
- **回顾表达式参数**：26.2 讲了如何用非类型（表达式）参数化模板类；`StaticArray` 示例带一个类型参数和一个表达式参数。
- **设计问题**：为 `StaticArray<T, size>` 写的通用 `print()` 会在元素间插入空格；对 `char` 数组你更想让它像 C 字符串那样连成一片。
- **全特化的局限**：全特化"必须把全部模板参数都显式写死"，于是每种数组长度（14、12、5、22……）都得单独写一个重载，太冗余。
- **偏特化的定义**：它让你特化类——"但不能特化单个函数！"——其中只有部分（而非全部）模板参数被显式定义。
- **应用到本问题**：把元素类型显式写成 `char`、让 `size` 保持模板化，就得到一个能服务任意长度 char 数组的函数。
- **函数不能被偏特化**：模板函数只能全特化；那个能工作的 `print(StaticArray<char, size>&)` 之所以合法，是因为它是一个**重载的函数模板**，其参数恰好是部分特化类类型。
- **成员函数问题**：不能只偏特化某一个成员函数（如 `StaticArray<double, size>::print()`）；这种尝试不被允许。
- **方案 A——特化整个类**：提供一个部分特化的 `StaticArray<double, size>`，其 `print()` 就成了"部分特化类中的普通成员函数"——但复制了大量代码。
- **方案 B——公共基类**：让 `StaticArray<double, size>` 从共享的 `StaticArray_Base<T, size>` 继承，避免重复。直接写 `class StaticArray<double, size>: public StaticArray<T, size>` 会失败，因为 `T` 未定义；即便定义了，也变成类继承自己。
- **作者关于 `this->` 的注释**：在派生特化里，访问基类成员必须加 `this->` 前缀（模板中的非依赖名字查找）。
- **作者关于析构函数的注释**：若要用到虚函数解析，别忘了虚析构函数。
- **这种继承没有可行语法**：原文明确说，没有任何语法允许那种直接继承的写法。

## 最佳实践

本节没有形式化的 Best practice / Warning / Author's note 方框。以下内联说明起到类似作用：

- **关于派生特化里的 `this->`**：原文指出该前缀"是必需的"，并给出非依赖名字查找的参考链接。
- **关于基类设计**：注释提醒，若使用虚函数解析要记得虚析构函数。
- **关于失败的继承写法**：原文说"没有任何语法允许我们这样继承"，并解释即使定义了 `T`，特化也会变成继承自己。

## 代码示例

- [26-05-example1.cpp](26-05-example1.cpp)：`StaticArray<T, size>` 与通用 `print()`，打印 int 数组；输出 `0 1 2 3`（原 Example 3）。
- [26-05-example2.cpp](26-05-example2.cpp)：同样的通用 `print()` 打印 char 数组，字符被空格隔开（设计缺陷）；输出 `H e l l o ,   w o r l d !`（原 Example 4）。
- [26-05-example3.cpp](26-05-example3.cpp)：为恰好 `StaticArray<char, 14>` 做函数模板全特化；输出 `Hello, world!`（原 Example 5）。
- [26-05-example4.cpp](26-05-example4.cpp)：以部分特化类为参数的重载 `print(char, size)`，一个函数服务任意长度的 char 数组；输出 `Hello, world! Hello, mom!`（原 Example 8）。
- [26-05-example5-error.cpp](26-05-example5-error.cpp)：试图偏特化成员函数 `StaticArray<double, size>::print()`，**预期编译失败**（原 Example 10）。
- [26-05-example6.cpp](26-05-example6.cpp)：方案 A——部分特化整个 `StaticArray<double, size>`（原 Example 11）。
- [26-05-example7.cpp](26-05-example7.cpp)：方案 B——公共基类 `StaticArray_Base<T, size>`，避免重复（原 Example 13）。

> 关于原文示例 12 的失败继承写法：原文给出
> `template <int size> class StaticArray<double, size>: public StaticArray<T, size>`
> 这一段无法作为独立文件构建（`T` 未定义，且即便定义也会变成类继承自身），原文用它说明"不存在直接继承的语法"，故不生成不可构建的源文件，仅在此说明。

> 说明：本节代码取自原文 HTML 逐字抽取（`<pre>` 块），与原文一致；example2 为把原片段补全上下文以便独立编译。
> 预期错误的实测信息（GCC 15.2）：example5 报 `error: invalid use of incomplete type 'class StaticArray<double, size>'`——GCC 以“用偏特化类类型定义成员函数”不合法的方式表达“函数/成员函数不能被偏特化”。
