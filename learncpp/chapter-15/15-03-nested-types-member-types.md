# 15.3 Nested types (member types)

> 原文：https://www.learncpp.com/cpp-tutorial/nested-types-member-types/

## 核心概念

- **动机**：把枚举放在类外面、由使用它的类来用，虽然能工作，但没有任何东西暗示这两者应该配套使用。
- **嵌套类型（成员类型）定义**：除了数据成员和成员函数，类还可以容纳类型；在类体内、按所需访问级别书写类型定义即可创建嵌套类型。
- **定义顺序有讲究**：嵌套类型的名字必须先完整定义才能被使用，因此它通常写在类的最前面。
- **访问规则照常生效**：声明为 public 的嵌套类型任何代码可用，声明为 private 的则不行。
- **类是作用域区域**：和命名空间一样，类为其内部声明的名字划定作用域，于是 `Type` 的完全限定名是 `Fruit::Type`，枚举值是 `Fruit::apple`。
- **类内与类外的限定**：类的成员可以用非限定名（如成员函数内的 `cherry`）；类外面的代码必须写完全限定名。
- **示例中的命名建议**：作者把旧的 `FruitType` 改名为 `Type`，使它写成 `Fruit::Type` 而不是重复的 `Fruit::FruitType`。
- **限定枚举与非限定枚举**：既然类本身已提供作用域，再用限定枚举就多余了；改用非限定枚举后可以写 `Fruit::apple` 而非 `Fruit::Type::apple`。
- **嵌套 typedef/类型别名**：类里也可以放 `using` 别名（或 typedef）；规则相同——类内用非限定名，类外用完全限定名（`Employee::IDType`）。
- **嵌套类与外层 `this`**：嵌套类没有外层对象的 `this` 指针，不能直接访问外层成员；嵌套类也可以被单独实例化，此时根本不存在外层对象。
- **嵌套类与私有访问**：由于嵌套类是外层类的成员，它可以访问作用域内外层类的私有成员（通常靠接收一个外层对象作为参数）。
- **典型真实用途**：标准库的迭代器类常嵌套在被迭代的容器里，例如 `std::string` 里的 `std::string::iterator`。
- **外层类内允许前向声明嵌套类型**：嵌套类型可以在其外层类中前向声明，之后再定义——定义既可在该类内，也可在该类之后。
- **外层类之前不能前向声明嵌套类型**：在外层类存在之前声明其嵌套类型是错误；必须先定义外层类。
- **多余警告**：在外层类定义之后再前向声明其嵌套类型虽然合法，但没有意义，因为类定义本身已经声明了它。

## 最佳实践

- **Best practice**：把任何嵌套类型定义在类类型的最前面（顶部的 public 区域）。

本节无其他 Best practice / Warning 条目。

## 代码示例

- [15-03-example1.cpp](15-03-example1.cpp)：枚举定义在类外的"嵌套之前"版本，输出 `I am an apple`（原 Example 1）。
- [15-03-example2.cpp](15-03-example2.cpp)：把枚举移入 `Fruit` 成为嵌套类型，改用非限定枚举，输出 `I am an apple`（原 Example 2）。
- [15-03-example3.cpp](15-03-example3.cpp)：`Employee` 中的嵌套类型别名 `IDType`，输出 `John has id: 1`（原 Example 3）。
- [15-03-example4.cpp](15-03-example4.cpp)：嵌套类 `Printer` 接收外层对象以读取其私有成员，输出 `John has id: 1`（原 Example 4）。
- [15-03-example5.cpp](15-03-example5.cpp)：嵌套类型在外层类内前向声明、在类内或类后定义（原 Example 5）。
- [15-03-example6-error.cpp](15-03-example6-error.cpp)：在外层类定义之前前向声明其嵌套类型——预期编译失败（原 Example 6）。

> 说明：本节代码为按原文描述重建。

## 编译说明

单文件示例使用：

```
g++ -std=c++20 -Wall 15-03-example1.cpp -o example1
```

`15-03-example6-error.cpp` 为预期编译失败示例，请勿修复。
