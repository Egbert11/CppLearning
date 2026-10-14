# 8.9 Do while statements

> 原文：https://www.learncpp.com/cpp-tutorial/do-while-statements/

## 核心概念

- **重新提示菜单的问题**：程序显示菜单、输入非法时重新询问，需要循环。但选择哪种循环很关键：`while` 循环在循环体执行**之前**检查条件，在这里用起来"有点别扭"，因为第一次检查时还没有任何用户输入。
- **方案一（哨兵初值 + while）**：先给 selection 一个非法初值，保证循环体至少执行一次。只有当 `0` 不是合法选项时才可行。
- **哨兵方案的缺点**：如果 `0` 也是合法选项，就得换一个"非法"初值，引入魔术数字。
- **方案二（额外合法性变量 + while）**：用一个独立的 `bool` 变量控制循环是否继续，避免魔术数字，但"为了确保循环只运行一次而新增了一个变量"，增加了复杂度和出错可能。
- **do-while 语法**：

  ```
  do
      statement; // 单条语句或复合语句
  while (condition);
  ```

- **do-while 定义**：与 while 循环类似，"不同之处在于其语句**至少执行一次**"。条件只在语句执行**之后**才检查；若为真，执行跳回顶部。
- **好处**：示例中 do-while "既避免了魔术数字，也避免了额外的变量"。
- **条件中变量的作用域规则**：selection 变量必须在 `do` 块**之外**声明。因为在块内声明的变量会在块结束时销毁——那发生在条件求值之前——而条件还需要用到它。
- **实际使用说明**：do-while 循环"并不常用"；把条件放在循环体底部会掩盖条件的位置，"容易导致错误"。有些开发者建议完全避免使用；作者的立场是：在其他一切相同时，更倾向于 while 循环。

## 最佳实践

> Favor while loops over do-while when given an equal choice.
> （在其他条件相同时，优先使用 while 循环而非 do-while。）

本节无其他 Author's note / Warning。

## 代码示例

- [`8-09-example1.cpp`](8-09-example1.cpp)：用 `while` 循环 + 非法初值（哨兵）强制菜单至少显示一次。
- [`8-09-example2.cpp`](8-09-example2.cpp)：用额外的 `bool invalid` 变量控制 `while` 循环。
- [`8-09-example3.cpp`](8-09-example3.cpp)：同一菜单逻辑改用 `do-while` 实现。
