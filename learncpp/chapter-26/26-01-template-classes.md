# 26.1 Template classes

> 原文：https://www.learncpp.com/cpp-tutorial/template-classes/

## 核心概念

- **模板能把代码泛化到多种类型**：前面的课程用函数模板做到了这一点，模板类（template classes）则对类做同样的事。
- **容器类的重复劳动问题**：`IntArray` 与 `DoubleArray` 几乎逐行相同，唯一的实质差别是存储的数据类型；为每种类型再写一个类既费事又易错。
- **模板类的定义语法**：在类定义之前写一行模板声明 `template <typename T>`，类中原本写具体类型的地方改成 `T`。
- **类外定义成员函数要自带模板声明**：在类外定义的每个成员函数，都必须各自再写一行 `template <typename T>`。
- **命名规则**：模板类叫 `Array<T>`，而不是 `Array`；在类内部，裸写 `Array` 表示当前这个实例化，而在类外部裸写 `Array` 会被当作一个非模板类。
- **实例化是按需进行的**：只有实际用到某个类型时，编译器才会"拓印（stencil out）"出一份副本；若模板类从未被使用，它根本不会被编译。
- **模板特别适合容器类**：容器最好能配合多种数据类型工作，模板能在不重复代码的前提下做到这点。语法丑、报错信息晦涩，但它是最有用的特性之一。
- **把模板拆成头文件/源文件会失败**：与普通类不同，把成员函数定义搬到单独的 `.cpp` 会得到链接错误，而不是正常工作。
- **失败原因**：实例化时编译器必须同时看到模板完整定义和具体类型，而它是逐个翻译单元编译的；只含定义的 `.cpp` 里没有任何地方需要实例化，于是什么都不会被实例化。
- **方案一（首选）**：把所有模板类代码都放进头文件、写在类下方。简单直接；局部重复实例化会拖慢编译/链接（链接器会去掉重复，所以可执行文件不会膨胀）。除非构建时间成问题，推荐此法。
- **方案二（.inl）**：把实现移到一个叫 `Array.inl` 的文件里，再在头文件末尾、头文件保护之内把它 include 进来。效果相同，组织更清爽。
- **方案三（三文件）**：类留在头文件、成员定义放 `.cpp`，再加第三个文件用 `template class` 命令做显式实例化。可能更高效，但每个程序都得额外维护这个文件。
- **不推荐的做法**：直接 `#include` `.cpp` 文件，因为它依赖非标准用法。

## 最佳实践

本节没有严格标注为 Best practice / Warning 的方框，但有若干建议性提示：

- **Tip（关于 .inl）**：若使用 `.inl` 方案后看到重复定义错误，多半是编译器把 `.inl` 当成代码文件一起编译了，导致内容被编两遍而违反一次定义规则。应把头文件排除出构建——Visual Studio 里把 "Exclude From Build" 设为 "Yes"；Code::Blocks 里取消勾选 "Compile file" 和 "Link file"。
- **作者推荐**：把全部模板代码放进头文件是首选方案，除非编译或链接时间成为问题。
- **注意**：不推荐 `#include` `.cpp` 文件，因为那是非标准用法。

## 代码示例

- [26-01-example1.cpp](26-01-example1.cpp)：`IntArray` 与 `DoubleArray` 两个几乎相同的类，展示重复劳动（原 Example 1/2）。
- [26-01-example2/](26-01-example2/)：泛化后的 `Array<T>`（`Array.h` + `main.cpp`），同时实例化 `Array<int>` 与 `Array<double>` 并反向打印（原 Example 3/4；输出 `11	11.5` … `0	0.5`，制表符分隔）。
- [26-01-example3-linkerror/](26-01-example3-linkerror/)：把 `operator[]` 定义搬到 `Array.cpp` 的拆分版（`Array.h` + `Array.cpp` + `main.cpp`），预期**链接失败**：`undefined reference to 'Array<int>::operator[](int)'`（原 Example 6/7）。
- [26-01-example4/](26-01-example4/)：三文件方案（`Array.h` + `Array.cpp` + `templates.cpp`），用 `template class` 显式实例化，可正常链接（原 Example 8）。

> 说明：本节代码取自原文 HTML 逐字抽取（`<pre>` 块），与原文一致；example1 为便于单文件编译额外补了一段 `main`。
