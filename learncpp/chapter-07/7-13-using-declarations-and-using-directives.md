# 7.13 Using declarations and using directives

> 原文：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/

## 核心概念

- **为何不推荐 `using namespace std;`**：看到经典 Hello World 里写着 `using namespace std;` 就该"快跑"，因为源码多半过时了。（Tip：有些 IDE 会自动生成这样的程序，让你一上来就能编译。）
- **简史**：命名空间出现之前，如今 `std` 里的一切都在全局命名空间中，程序名与库名容易冲突。命名空间 1995 年标准化，标准库被移入 `std`，导致使用无限定名的旧代码失效。给每个名字加 `std::` 前缀被认为风险巨大，于是有人要求提供解决方案。如今反复敲 `std::` 既繁琐又影响可读性，C++ 因此提供了 using 语句。
- **限定名（qualified name）**：包含关联作用域的名字，最常见的是通过作用域解析运算符 `::` 关联命名空间。进阶：名字也可由类名（经 `::`）或类对象/指针（经 `.` 或 `->`）限定。
- **非限定名（unqualified name）**：不含作用域限定符的名字，例如 `cout`、`x`。
- **using 声明（using declaration）**：让一个非限定名作为某个限定名的别名。自其声明点到所在作用域末尾有效，每个名字各需一条。在 `.cpp` 中被认为是安全、可接受的（有一个例外，见下）。
- **using 指令（using directive）**：让某命名空间的所有标识符在该指令所在的作用域内无需限定即可引用。进阶：严格来说 using 指令并不把名字引入当前作用域，而是引入外层作用域。
- **为何避免 using 指令（两个因素）**：① 它让命名空间里**所有**名字都可无限定访问，包括你永远不会用到的；② 它**不会**优先选择被识别命名空间中的名字。
- **冲突与歧义**：两个命名空间都定义 `x`，各用一条 using 指令导入，则 `x` 有歧义、编译失败（"ambiguous symbol"）。同理，用户自定义 `cout()` 函数在导入 `std` 时会与 `std::cout` 冲突。改用 using 声明或显式 `std::` 前缀即可避免。
- **未来的脆弱性与静默的行为变化**：即便当前无冲突，using 指令也使代码脆弱：若被包含的库日后新增名字，可能冒出新冲突。更糟的是，若新函数是更好的重载匹配，行为会**静默改变**——例如新增的 `get(int)` 因字面量 `0` 精确匹配而胜过原有的 `get(long)`。using 声明或显式限定可避免此问题。
- **可读性**：有 using 指令时，`foo()` 究竟是库函数还是用户函数难以判断；写成显式 `NS::foo()` 则库调用一目了然。现代 IDE 可悬停消歧，但逐个名字这么做很费事。
- **using 语句的作用域**：在块内声明的名字只作用于该块（普通块作用域），降低冲突风险。在命名空间（含全局命名空间）内声明的名字作用于文件其余部分（文件作用域）。
- **不要在头文件、也不要在 `#include` 之前使用 using 语句**：一条好规则是，绝不把它放在能影响别的文件、或会被别的文件影响的地方。头文件全局命名空间里的 using 语句会传播到每个包含它的文件。在头文件中定义的函数里用 using 语句也不安全，因为其行为取决于当前已可见的标识符，变得依赖顺序——把 `using Foo::print;` 移到某 `#include` 之前，就会改变被调用的重载。唯一真正安全的位置是 `.cpp` 文件内、所有 `#include` 之后。
- **无法取消或替换**：一旦声明，在其作用域内没有办法取消或替换该 using 语句；最多只能用嵌套块限制其作用域。

## 最佳实践

- **Best practice**：优先使用显式命名空间限定符，而非 using 语句。
- **Best practice**：应彻底避免使用 using 指令——唯一例外是 `using namespace std::literals;` 以获得 `s` 与 `sv` 字面量后缀。
- **Best practice**：using **声明**在 `.cpp` 文件中、`#include` 之后使用是可以的。
- **Best practice**：不要在**头文件**中使用 using 语句——尤其不要在头文件的全局命名空间中使用。
- **相关**：`using` 关键字也用于类型别名，与 using 语句无关。

## 代码示例

> 说明：本节的抓取工具限制了长代码块的逐字输出，以下 cpp 为按原文描述与该站标准示例忠实重建，语义与预期输出一致。原文多数示例为若干行片段或"预期编译失败"的教学片段；此处能独立成文件的都给出，纯片段在下方列出。

- [7-13-example1-broken.cpp](7-13-example1-broken.cpp) — 用 using 指令的 Hello World（过时写法，可编译但为坏实践；对应 Example 1）。
- [7-13-example2.cpp](7-13-example2.cpp) — 改用 using 声明 `using std::cout;` 的 Hello World（对应 Example 2）。
- [7-13-example3-error.cpp](7-13-example3-error.cpp) — 两条 using 指令导入两个都定义 `x` 的命名空间，`x` 产生歧义，**预期编译失败**（对应 Example 5）。
- [7-13-example4-error.cpp](7-13-example4-error.cpp) — 用户 `int cout()` 与 `std::cout` 冲突，**预期编译失败**（对应 Example 6）。
- [7-13-example5.cpp](7-13-example5.cpp) — 静默的行为变化：库新增 `get(int)` 后，`get(0)` 由旧的 `1` 变为 `2`（对应 Example 9）。
- [7-13-example6.cpp](7-13-example6.cpp) — 用嵌套块限制 using 指令的作用域（对应 Example 14）。
- [7-13-example7/](7-13-example7/) — using 声明的正确位置：先包含两个头文件再用 `using Foo::print;`，`print(5)` 调用 `Foo::print(int)`（对应 Example 11）。若把 `using Foo::print;` 移到 `#include "FooInt.h"` 之前，则会改为调用 `Foo::print(double)`（对应 Example 12，见 md 说明）。
  - [FooDouble.h](7-13-example7/FooDouble.h)、[FooInt.h](7-13-example7/FooInt.h)、[main.cpp](7-13-example7/main.cpp)

仅以片段出现的示例（不单独成文件）：

- Example 3：限定名示例 `std::cout`（由命名空间 `std` 限定）、`::foo`（由全局命名空间限定）。
- Example 4：进阶——由类/对象/指针限定：`C::s_member;`、`obj.x;`、`ptr->y;`。
- Example 7/8：第三方 `Foo::a` 经 using 指令访问可正常编译；但库更新新增 `Foo::print()` 后，原先对 `print()` 的调用变歧义，**不再能编译**（无法用一个文件表达"更新前/更新后"两个状态，故不生成文件）。
- example7 的反面（Example 12）：把 `using Foo::print;` 放在 `#include "FooInt.h"` **之前**，则 `print(5)` 会调用 `Foo::print(double)`——这正是"using 语句依赖顺序"的陷阱。
- Example 13：在其作用域内无法取消 using 语句。
