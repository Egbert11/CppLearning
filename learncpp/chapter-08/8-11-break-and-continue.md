# 8.11 Break and continue

> 原文：https://www.learncpp.com/cpp-tutorial/break-and-continue/

## 核心概念

- **break 语句**：结束 `while`、`do-while`、`for` 或 `switch`，执行从被跳出结构之后的下一条语句继续。
- **在 switch 中 break**：通常放在每个 case 末尾，表示该 case 结束、阻止 fallthrough（贯穿）到后续 case。
- **在循环中 break**：在循环内 `break` 会提前结束循环，控制流在该循环结束之后继续。
- **跳出有意的无限循环**：常见模式是 `while (true)` 配一个由某条件触发的 `break`。
- **break vs return**：`break` 只跳出 switch/循环；`return` 结束整个所在函数并返回调用者。
- **continue 语句**：只结束**当前这一次迭代**，而非整个循环。它把执行跳转到当前循环体的底部。
- **for 与 continue**：`continue` 之后 end-statement（如 `++count`）仍会执行，因为它在循环体末尾执行。
- **while / do-while 配 continue 的陷阱**：这两类循环通常在循环体内更新条件变量；如果 `continue` 跳过了这些更新，循环可能变成死循环。
- **break/continue 之争**：批评者认为它让控制流跳来跳去、容易被忽略；支持者认为恰当使用可减少嵌套与复杂逻辑。
- **continue 的最佳用法**：最适合放在 for 循环顶部，满足条件时跳过本次迭代，从而避免嵌套块。
- **提前返回之争**：有人偏好函数底部单一 return 以求简洁；有人偏好提前退出（避免阅读不必要的逻辑、减少嵌套块）。折中方案：只在开头做参数校验时提前返回。
- **本节观点**：恰当地使用时，break/continue 与提前返回利大于弊。

## 最佳实践

- Use break and continue when they simplify your loop logic.
- Use early returns when they simplify your function's logic.
- **Warning**：Be careful when using a `continue` statement with while or do-while loops.（这些循环通常在循环体内改变条件变量，用 `continue` 跳过这些行可能使循环永远运行。）

## 代码示例

- [`8-11-example1.cpp`](8-11-example1.cpp)：在每个 switch case 末尾使用 `break` 防止 fallthrough。
- [`8-11-example2.cpp`](8-11-example2.cpp)：累加最多 10 个输入，输入 0 时用 `break` 提前退出。
- [`8-11-example3.cpp`](8-11-example3.cpp)：用 `break` 跳出一个 `while (true)` 无限循环。
- [`8-11-example4.cpp`](8-11-example4.cpp)：对比无限循环内 `break` 与 `return` 的行为。
- [`8-11-example5.cpp`](8-11-example5.cpp)：用 `continue` 跳过能被 4 整除的迭代。
- [`8-11-example6-broken.cpp`](8-11-example6-broken.cpp)：`while` 循环中 `continue` 导致的死循环 bug（**不要运行到结束**）。
- [`8-11-example7.cpp`](8-11-example7.cpp)：用 `bool` 标志控制循环退出（不使用 `break`）。
- [`8-11-example8.cpp`](8-11-example8.cpp)：同样行为，用单个 `break` 简化。
- [`8-11-example9.cpp`](8-11-example9.cpp)：条件取反 + 嵌套块的写法（不使用 `continue`）。
- [`8-11-example10.cpp`](8-11-example10.cpp)：同一逻辑用 `continue` 实现，无需嵌套块。
