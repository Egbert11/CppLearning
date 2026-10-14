# 17.6 std::array and enumerations

> 原文：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/

## 核心概念

- **CTAD 从初始化列表推导长度**：`constexpr std::array` 用类模板实参推导时，长度由初始化器个数决定。
- **初值太少很危险**：给的值少于预期会得到一个更短的数组，越过其末尾访问就是未定义行为。
- **用 static_assert 校验初值个数**：凡是能合理检查个数的地方，都可以用静态断言把数组长度与 `max_students` 之类的枚举项比较。
- **断言失败即停止编译**：报错 "static_assert condition failed"，于是新增枚举项却忘了写初值就变成编译期错误。
- **两个数组也可互相校验**：同样的机制能保证两个 `constexpr std::array` 长度一致。
- **用数组替代 switch/if 链做名字查找**：对于取值从 0 开始、每次加 1 的枚举（大多数如此），可用数组保存每个枚举项的名字，取代重复的字符串字面量与手写的 case 逻辑。
- **由此带来两种能力**：一是可以用枚举值作下标取名字；二是遍历名字数组就能用名字反查枚举（通过其下标）。
- **`sv` 后缀与字面量命名空间**：引入 `std::string_view_literals` 并使用 `sv` 后缀，可让 `std::array` 推导出 `std::string_view` 作为元素类型。
- **为名字数组加校验**：用 static_assert 比较 `std::size(colorName)` 与 `max_colors`，确认每个颜色都有字符串。
- **用 `operator<<` 支持输出**：为枚举类型定义 `operator<<` 会借助查找函数打印名字；返回与参数都用引用以免拷贝。
- **用 `operator>>` 支持输入**：提取运算符读入一行，在名字数组中查找，匹配到的下标用 `static_cast` 转换为枚举类型；没有匹配则通过 `setstate(std::ios_base::failbit)` 让流进入失败状态。
- **提取失败的注意点**：提取失败时 `operator>>` 会把基本类型零初始化；注释行展示了如何让自定义运算符也表现相同行为。
- **基于范围的 for 不能作用于枚举**：对枚举类型写范围 for 是编译错误——"can't traverse enumeration"。
- **下标循环需要转换**：用整型计数器遍历枚举可行，但要反复 static_cast 回枚举类型。
- **变通办法：枚举项数组**：因为范围 for 能作用于数组，推荐用一个 `constexpr std::array` 保存每个枚举项，再遍历它；只有枚举项取值互不相同时才成立。
- **循环变量类型自动推导**：当 `Color::types` 的元素类型是 `Color::Type` 时，循环变量 `c` 推导为 `Color::Type`，正是所需结果。

## 最佳实践

- 本节无 Best practice / Warning / Author's note 条目。要点以行内说明给出：提取失败会把基本类型零初始化（并给出可选的一行代码来模仿该行为）；枚举项数组技巧"仅在枚举项取值互不相同时成立"。

## 代码示例

- [17-06-example1-ub.cpp](17-06-example1-ub.cpp)：CTAD 只给 4 个成绩而枚举有 5 项 → 越界未定义行为（-ub）。
- [17-06-example2-error.cpp](17-06-example2-error.cpp)：`static_assert` 校验长度 → 编译失败（-error）。
- [17-06-example3.cpp](17-06-example3.cpp)：`getPetName` / `getPetFromString` 重复字符串字面量的坏味道。
- [17-06-example4.cpp](17-06-example4.cpp)：`Color` 名字数组 + 完整 `operator<<` / `operator>>`。
- [17-06-example5.cpp](17-06-example5.cpp)：用整型计数器遍历枚举并 static_cast。
- [17-06-example6-error.cpp](17-06-example6-error.cpp)：对枚举类型写范围 for → 编译失败（-error）。
- [17-06-example7.cpp](17-06-example7.cpp)：枚举项数组 + 范围 for，输出 `black`/`red`/`blue`。
- [17-06-quiz1.cpp](17-06-quiz1.cpp)：Quiz 解答——`Animal` 枚举 + 并行数组 + 自定义 `operator>>`。

> 说明：本节代码为按原文描述重建；quiz/动物的具体数据按原文描述重拟。
