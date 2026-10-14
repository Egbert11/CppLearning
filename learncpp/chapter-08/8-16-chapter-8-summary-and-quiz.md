# 8.x Chapter 8 summary and quiz

> 官方编号为 8.x；本文件按整章小节数顺延编号为 8-16。
> 原文：https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/

## 核心概念

- **执行路径（execution path）**：CPU 实际执行的语句顺序。**直线程序（straight-line program）** 每次运行都走同一条路线。
- **控制流语句（flow control statements）**：让程序员改变正常执行路径的工具。跳入非顺序序列称为**分支（branch）**。
- **条件语句（conditional statement）**：决定其关联语句是否运行的语句。
- **if / else 语句**：条件为 `true` 时运行 if 的语句体；为 `false` 时运行 else 的语句体。可以链式串联多组 if/else。
- **dangling else（悬垂 else）**：某个 else 究竟属于哪个 if 的歧义。规则是：else 绑定到"同一块中最后一个尚未匹配的 if 语句"，因此把 if 体包进块即可轻松避免。
- **空语句（null statement）**：一个单独的分号，什么都不做；在语法要求语句但无需动作处有用。
- **switch 语句**：在多个匹配值之间做选择的一种更清晰、更快的方式。只接受**整型**。**case 标签**标记匹配值，**default 标签**处理无匹配的情况。
- **fallthrough（贯穿）**：控制流从一个标签的语句流入下一个标签的语句。`break`（或 `return`）可阻止它，`[[fallthrough]]` 属性可记录有意的贯穿。
- **goto 语句**：向前或向后跳到代码的其他位置。一般不建议，因为它会产生**意大利面代码（spaghetti code）**——形似"一碗意大利面"的执行路径。
- **while 循环**：条件成立时重复；每次执行前检查条件。
- **无限循环**：条件永远为 `true` 的循环；除非被其他控制流语句中止，否则无限运行。
- **循环变量（计数器）与迭代**：跟踪循环已运行次数的整型变量；循环体的每次执行称为一次迭代。
- **do while 循环**：类似 while，但条件在循环体**之后**求值。
- **for 循环**：最常用的循环，在需要特定重复次数时最合适。**off-by-one 错误**指循环运行次数多一次或少一次。
- **break 与 continue**：`break` 退出 `switch`、`while`、`do while`、`for`（以及范围 for）；`continue` 直接跳到下一次迭代。
- **halt**：结束程序的语句。**正常终止（normal termination）** 指预期的退出，用状态码报告成功或失败；`std::exit()` 在 `main` 末尾运行，也可显式调用——它执行部分清理，但不清理局部变量、不展开调用栈。**异常终止（abnormal termination）** 发生在意外错误之后，`std::abort` 可触发它。
- **算法（algorithm）**：解决问题或产生有用结果的有限指令序列。若算法在调用之间保留信息则是有状态的，否则是无状态的；**状态（state）** 指这些有状态变量所持有的值。
- **确定性算法**：对给定输入（供给 `start` 的值）总得到相同的输出序列。
- **伪随机数生成器（PRNG）**：产生模拟随机性序列的算法。其初始值是**随机种子（seed）**；一旦提供种子，PRNG 便已**播种（seeded）**。若种子比 PRNG 状态小，则为**播种不足（underseeded）**。重复出现前产生的输出数量是**周期（period）**。
- **随机数分布（distribution）**：把 PRNG 输出转换成另一种分布。**均匀分布**以相等概率产生 X 到 Y（含端点）之间的值。

## 最佳实践

本节为总结/测验小节，无独立的 Best practice / Warning 提示框。仅有的提示：

- **Warning**：关于测验——"The quizzes start getting harder from this point forward, but you can do it."（测验从此刻起会变难，但你能做到。）

## 代码示例

- [`8-16-quiz1.cpp`](8-16-quiz1.cpp)：测验 1 解答——把第 4 章的落体程序改为循环到球落地（使用命名空间与 `constexpr`）。
- [`8-16-quiz2.cpp`](8-16-quiz2.cpp)：测验 2 解答——用 for 循环实现 `isPrime()`，配合基于 `assert` 的测试骨架。
- [`8-16-quiz2-extra.cpp`](8-16-quiz2-extra.cpp)：测验 2 额外加分——优化版 `isPrime()`（跳过偶数、只检查到平方根）。
- 多文件示例（放在子目录 [`8-16-quiz3/`](8-16-quiz3/) 中）：
  - [`8-16-quiz3/Random.h`](8-16-quiz3/Random.h)：全局随机数头文件（同 8.15）。
  - [`8-16-quiz3/main.cpp`](8-16-quiz3/main.cpp)：测验 3 解答——猜数字（Hi-Lo）游戏，`playHiLo()` + `playAgain()` + `main()`。

编译：`g++ -std=c++20 -Wall 8-16-quiz3/*.cpp`

## 本章知识速览

- **控制流**：执行路径、分支、条件语句；`if`/`else`（含 dangling else 与块的作用）；空语句。
- **switch**：只用整型；case/default 标签；fallthrough 与 `[[fallthrough]]`；`break` 阻止贯穿。
- **goto**：可前后跳转，但易产生 spaghetti code，一般避免。
- **循环**：
  - `while`：先检查条件。
  - `do while`：后检查条件，体至少执行一次。
  - `for`：最常用，适合已知重复次数；注意 off-by-one。
  - 无条件循环即无限循环；循环变量即计数器；每遍为一次迭代。
- **break / continue**：`break` 退出 switch/循环；`continue` 跳到下一次迭代（在 while/do-while 中慎用，可能死循环）。
- **halt**：`std::exit`（正常终止、不清理局部变量）、`std::atexit`（注册终止时回调）、`std::abort`（异常终止）、`std::terminate`（异常相关，默认调用 abort）。基本不用 halt，优先异常。
- **随机数**：算法 / 有状态 / 无状态 / 确定性；PRNG、seed、seeded、underseeded、period；分布（均匀分布）；`<random>`；`std::mt19937` / `mt19937_64`；`std::uniform_int_distribution`；用 `std::random_device` 播种且只播种一次；`std::seed_seq` 避免播种不足；`Random.h` 提供全局共享 PRNG。

## 测验

**测验 1**：修改第 4 章的落体程序，让球一直下落直到落地。运用当前最佳实践（命名空间、`constexpr` 等）。解答见 [`8-16-quiz1.cpp`](8-16-quiz1.cpp)。

**测验 2**：用 for 循环完成 `isPrime()`，使基于 `assert` 的测试骨架打印 `"Success!"`。`assert` 是一个预处理宏，若其参数求值为 false 则终止程序（例如 `assert(!isPrime(0))` 表示若 `isPrime(0)` 为真则终止）。额外加分：优化实现，避免检测偶数除数，且只检查到 `x` 的平方根。解答见 [`8-16-quiz2.cpp`](8-16-quiz2.cpp)，优化版见 [`8-16-quiz2-extra.cpp`](8-16-quiz2-extra.cpp)。

**测验 3**：实现猜数字游戏——在 1 到 100 中随机选一个整数，给用户 7 次机会，提示"太高/太低"，最后宣布胜利或失败（并给出正确答案），并反复询问 `y`/`n` 直到输入合法。使用 `Random.h`。额外加分：把最小值、最大值和猜测次数做成可配置参数。解答见 [`8-16-quiz3/main.cpp`](8-16-quiz3/main.cpp)。
