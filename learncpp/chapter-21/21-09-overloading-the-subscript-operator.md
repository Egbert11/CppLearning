# 21.9 Overloading the subscript operator

> 原文：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/

## 核心概念

- **动机**：数组用 `[]` 取元素，但类的数组成员通常是私有的，外部无法访问。用 `setItem(index, value)` / `getItem(index)` 这类访问函数可行，却不易一眼看出参数含义；返回裸指针 `int* getList()` 再写 `list.getList()[2] = 3` 又很怪异。
- **重载 `operator[]`**：必须作为**成员函数**实现，且只接受**一个**参数——方括号里的下标。对 `IntList`，参数是 `int`，返回 `int`。
- **调用机制**：写 `list[2]` 时，编译器查找重载的 `operator[]`，把方括号内的值作为实参传入。
- **默认参数无用**：虽然可以给参数默认值，但不写下标地调用 `[]` 不是合法语法。
- **为什么返回引用**：`[]` 的优先级高于赋值，`list[2]` 先求值、结果要能放在 `=` 左边，因此必须是**左值**；引用总是左值，所以返回 `int&`。若按值返回 `int`，`list[2] = 3` 会变成类似 `6 = 3`，编译器报“左操作数必须是左值”。
- **const 重载**：非 const 对象走非 const 版本（可写），const 对象走 const 版本（只读）。const 版本若复制开销小可按值返回。
- **消除重复**：实现很短时，两个重载各写一遍即可；实现较长时，把逻辑写在 const 版本里，让非 const 版本先 `std::as_const(*this)` 取 const 引用调用它，再用 `const_cast` 去掉返回值的 const。此路径只可能由非 const 对象触发，故去 const 是安全的。
- **C++23 写法**：用显式对象参数 `this auto&& self` 配合 `auto&&` 返回，单个函数同时服务 const / 非 const。
- **越界检查**：内建数组下标不做边界检查；重载的 `operator[]` 可以 `assert` 下标合法，或用 `if` + 抛异常 / `std::exit` 处理。
- **指针陷阱**：对**指针**使用 `[]` 会被当作“对该类型数组做下标访问”，而不是调用重载。应先解引用并加括号：`(*list)[2]`。
- **参数类型不限**：下标参数可以是 `double`、`std::string`、`std::string_view` 等，适合以单词为键的映射。
- **测验**：`GradeMap` 用 `std::vector<StudentGrade>` 存储键值对，`operator[](std::string_view)` 借 `std::find_if` + lambda 查找；标准库的 `std::map` 是更省事的替代。

## 最佳实践

- 提示：C++23 起支持为 `operator[]` 传入多个下标。
- 规则（Rule）：**不要试图对“指向对象的指针”调用你重载的 `operator[]`**（应先解引用）。
- 推荐：需要“键值映射”时优先用 `std::map`，而不是自己写 `operator[]`。

## 代码示例

- [21-09-example1.cpp](21-09-example1.cpp) — 用 `setItem()`/`getItem()` 访问私有数组（重载前的窘境）。
- [21-09-example2.cpp](21-09-example2.cpp) — 返回 `int* getList()` 的裸指针访问方式（语法怪异）。
- [21-09-example3.cpp](21-09-example3.cpp) — 重载 `operator[]` 返回 `int&`，支持 `list[2] = 3`（输出 `3`）。
- [21-09-example4.cpp](21-09-example4.cpp) — 同时提供 const 与非 const 两个 `operator[]` 重载。
- [21-09-example5.cpp](21-09-example5.cpp) — 用 `std::as_const` + `const_cast` 去重的写法。
- [21-09-example6-cpp23.cpp](21-09-example6-cpp23.cpp) — C++23 显式对象参数版本（需 `-std=c++23`）。
- [21-09-example7.cpp](21-09-example7.cpp) — 用 `assert` + `std::size` 做越界检查。
- [21-09-example8-error.cpp](21-09-example8-error.cpp) — 对指针误用 `[]`，**预期编译失败**。
- [21-09-example9.cpp](21-09-example9.cpp) — 下标参数为 `std::string_view` 的非整型示例。
- [21-09-quiz1.cpp](21-09-quiz1.cpp) — 测验 1：`GradeMap` 姓名→成绩映射。

说明：本节代码为按原文描述重建（原文长代码块受抓取工具逐字引用上限所限）。
