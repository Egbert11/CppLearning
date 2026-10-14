# 14.6 Access functions

> 原文：https://www.learncpp.com/cpp-tutorial/access-functions/

## 核心概念

- **数据成员默认 private**：类通常把数据成员保持为 private，而"private 成员不能被 public 直接访问"。例子里的 `Date` 能打印自己，但外部任何东西都读不到也改不了 `m_year`。
- **为什么可能需要访问函数**：对某些类来说，考虑到它自身的职责，允许使用者读取或设置某个私有成员的值是合理的。
- **访问函数（access function）的定义**：它是一个平凡的 public 成员函数，职责就是读取（retrieve）或修改（change）某个私有成员变量的值。
- **两个品种：getter 与 setter**："getter"（又叫 accessor）是返回私有成员值的 public 成员函数；"setter"（又叫 mutator）是设置私有成员值的 public 成员函数。
- **术语澄清**："mutator" 常与 "setter" 混用，但更广义地说，mutator 是任何修改（mutate）对象状态的成员函数。setter 只是 mutator 中的一种，也存在不是 setter 的 mutator。
- **getter / setter 的 const 规则**：getter 通常标为 const，从而能同时用于 const 与非 const 对象；setter 应当是非 const，以便修改数据成员。
- **命名约定：get/set 前缀**：优点是清楚表明这是访问函数、"调用起来应当很廉价"。
- **命名约定：不带前缀**：更简洁，getter 与 setter 复用同一个名字、靠函数重载区分；C++ 标准库就用这种约定。缺点是看代码的人不易察觉值正在被修改。
- **关于 `m_` 前缀的 Key insight**：给私有数据成员加 `m_` 前缀的最好理由之一，是避免数据成员与 getter 同名（C++ 不支持同名，Java 等语言则允许）。
- **命名约定：只给 setter 加 set 前缀**：getter 可以不带前缀，setter 保留 "set"。
- **setter 命名 Tip**：给 setter 加 "set" 前缀，能更明显地表明它会改变对象状态；getter 则可用 "get" 前缀或不用前缀。
- **getter 的返回类型**：getter 应提供只读访问，因此最佳实践是——拷贝成员代价低时按值返回，代价高时按 const 左值引用返回。按引用返回成员将在 14.7 讲解。
- **关于访问函数的争论**：何时该用、何时该避免访问函数存在争议，许多开发者认为它们违反良好的类设计。原文建议采取务实做法：
  - 若一个类没有不变量、却需要大量访问函数，可考虑改成带 public 成员的 struct；
  - 优先实现"行为/动作"而非访问函数，例如实现 `kill()` 与 `revive()`，而不是提供一个 `setAlive(bool)`；
  - 只有当 public 确实需要获取或设置某个单独成员时，才提供访问函数。
- **既然有公开访问器，为什么还要把数据设为 private？**：原文把这个问题留到 14.8（数据隐藏 / 封装的好处）回答。

## 最佳实践

- 本节无 Best practice / Warning 条目。原文出现的是两条方框：
  - **Key insight**：给私有数据成员加 `m_` 前缀的最佳理由之一，是避免数据成员与 getter 同名（C++ 不支持同名，Java 等语言支持）。
  - **Tip**：给 setter 加 "set" 前缀，使它们改变对象状态这一点更明显；getter 可用 "get" 前缀或不用前缀。

## 代码示例

- [14-06-example1.cpp](14-06-example1.cpp)：`Date` 私有成员 + `print()`，外部无法直接访问数据，输出 `2020/10/14`。
- [14-06-example2.cpp](14-06-example2.cpp)：为一整套 getter / setter 的示例，输出 `The year is: 2021`。
- [14-06-example3.cpp](14-06-example3.cpp)：命名约定——get / set 前缀。
- [14-06-example4.cpp](14-06-example4.cpp)：命名约定——不带前缀，靠重载区分（并演示其可读性缺点 `d.day(5);`）。
- [14-06-example5.cpp](14-06-example5.cpp)：命名约定——只有 setter 保留 set 前缀。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具对长代码块有逐字引用上限）。示例 3~5 原文以片段形式给出，此处各补一个最小类与 `main()` 以便独立编译。
