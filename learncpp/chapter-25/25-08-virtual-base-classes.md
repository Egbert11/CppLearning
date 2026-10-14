# 25.8 Virtual base classes

> 原文：https://www.learncpp.com/cpp-tutorial/virtual-base-classes/

> 注：原文标明本节为进阶主题，可按需略读。

## 核心概念

- **钻石问题（diamond problem）**：当两个类（如 `Scanner`、`Printer`）都继承同一个公共基类（`PoweredDevice`），再由第四个类（`Copier`）同时继承这两者时，默认结果是 `Copier` 中出现**两份**公共基类子对象。
- **问题的表现**：创建一个 `Copier` 对象会产生两个 `PoweredDevice` 子对象——一份经由 `Printer`，一份经由 `Scanner`——因此基类被构造了两次。
- **虚基类（virtual base class）**：在继承列表中加入 `virtual` 关键字，使该基类只存在一份；整棵继承树中只有一个基类对象，并且只被构造一次。
- **谁来构造它**：基类被共享后，由**最派生类**负责创建它；因此 `Copier` 的构造函数可以直接初始化 `PoweredDevice`，即调用「非直接父类」的构造函数。
- **构造顺序规则**：对最派生类的构造函数而言，虚基类总是**先于**非虚基类被构造，这保证了所有基类都在其派生类之前创建。
- **哪些初始化被忽略/使用**：`Scanner`、`Printer` 的构造函数仍然写着 `PoweredDevice{...}`；构造 `Copier` 时这些调用被忽略（但它们仍是直接构造 `Scanner`/`Printer` 时所需的），直接构造 `Scanner`/`Printer` 时则照常按普通规则使用。
- **最派生类总是负责**：只要一个类继承了任何带虚父类的类，最派生类就负责构造虚基类。单继承也成立：若 `Copier` 只继承自「以虚方式继承 `PoweredDevice` 的 `Printer`」，仍由 `Copier` 构造虚基类。
- **虚表/大小后果**：每个继承虚基类的类都会获得一张虚表——「即使它本来不会拥有虚函数」——因此对象大小增加了一个指针。
- **为什么需要这个指针**：`Scanner` 和 `Printer` 都需要知道自己到那个共享的 `PoweredDevice` 子对象的偏移量，才能访问其成员；这通常由虚表机制保存该偏移来实现。

## 最佳实践

本节无（原文仅有「本节为进阶主题，可略读」的提示，没有 Best practice / Warning 等标注）。

## 代码示例

- [25-08-example1.cpp](25-08-example1.cpp)：钻石继承问题——`Copier` 中有两份 `PoweredDevice`，基类被构造两次。
- [25-08-example2.cpp](25-08-example2.cpp)：改用 `virtual` 继承后，只有一份 `PoweredDevice`，且由 `Copier` 负责构造。

代码说明：两个文件均为原文逐字提取。原文此外还给出一段「最小语法示意」（只写 `class Scanner: virtual public PoweredDevice {...};` 等空类），此处不单独生成文件，其要点已并入上表与核心概念。
