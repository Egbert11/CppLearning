# 2.12 Header guards

> 原文：https://www.learncpp.com/cpp-tutorial/header-guards/

## 核心概念

- **单一定义规则的重复定义问题**：一个变量或函数标识符只能有一个定义，再定义一次就是编译错误。
- **头文件让重复很容易发生**：因为一个头文件常会 `#include` 另一个头文件，头文件里的定义可能被多次复制进同一个翻译单元。
- **header guard（include guard）**：一组条件编译指令，阻止头文件的内容被多次复制进同一个文件。形式为：`#ifndef SOME_UNIQUE_NAME_HERE` / `#define SOME_UNIQUE_NAME_HERE`，之后是内容，最后 `#endif`。
- **预处理器如何判断**：**首次**包含时该宏未定义，内容被包含且宏被定义；**再次**包含时宏已定义，`#ifndef` 为假，内容被跳过。
- **命名约定**：用头文件全名的大写形式，把空格/标点换成下划线（如 `square.h` → `SQUARE_H`）。所有头文件都应有 guard。标准库头文件也用 guard（例如 Visual Studio 的 `iostream` 里可见 `_IOSTREAM_`）。
- **guard 不能阻止"被不同代码文件各包含一次"**：每个 `.cpp` 各得一份拷贝，若头文件里放了函数定义，链接期就会看到多个定义。正确做法是把定义放进**一个** `.cpp`，头文件里只保留前置声明。
- **为什么 guard 仍然重要**：你自己定义的类型通常声明在头文件里，没有 guard 的话，一个文件可能收到多份同样的类型定义，编译器会报错。
- **`#pragma once`**：现代编译器提供的替代方案，效果相同，由编译器负责去重而非开发者。
- **进阶提醒**：当一个头文件存在于多个位置、且两份都被包含时，`#pragma once` 通常会失效；传统 header guard 仍能对"内容相同的头文件"去重。
- **小结**：guard 保证头文件内容在每个文件中只被复制一次；重复的**声明**是允许的，但对只含声明的头文件也仍推荐加 guard；guard 有意"不"阻止头文件在项目的每个不同文件里各被包含一次。

## 最佳实践

- 每个头文件都应有 header guard。
- 重复声明是允许的，但仍推荐加 guard。
- 由于 `#pragma once` 并非 C++ 标准规定，部分开发者（如 Google）更青睐传统 header guard；不过 `#pragma once` 支持广泛，现代 C++ 中一般也被接受。
- **Warning**：`#pragma` 是实现相关的——不同编译器支持哪些 pragma、含义如何都不同；除 `#pragma once` 外，在某个编译器上有效的 pragma 未必被另一个支持。
- **进阶提醒（guard 名冲突）**：不同目录下的两个头文件可能同名，于是 guard 名也相同，后一个文件的内容会被跳过，通常导致编译错误。可用 `PROJECT_PATH_FILE_H`、`FILE_LARGE-RANDOM-NUMBER_H`、`FILE_CREATION-DATE_H` 之类的唯一命名来避免。

## 代码示例

- [2-12-example1/square.h](2-12-example1/square.h) + [2-12-example1/wave.h](2-12-example1/wave.h) + [2-12-example1/main.cpp](2-12-example1/main.cpp)：演示 header guard 生效——`main.cpp` 直接包含 `square.h` 又（经 `wave.h`）间接包含它，因 guard 去重，预处理后定义只出现一次，程序可编译。
- [2-12-example2/square.h](2-12-example2/square.h) + [2-12-example2/square.cpp](2-12-example2/square.cpp) + [2-12-example2/main.cpp](2-12-example2/main.cpp)：修正版——头文件只放前置声明、定义放 `.cpp`，避免多文件链接期的重复定义。输出：`a square has 4 sides` / `a square of length 5 has perimeter length 20`。
- [2-12-example3/square.h](2-12-example3/square.h) + [2-12-example3/square.cpp](2-12-example3/square.cpp) + [2-12-example3/main.cpp](2-12-example3/main.cpp)：用 `#pragma once` 的等价写法。
- [2-12-example4/add.h](2-12-example4/add.h) + [2-12-example4/add.cpp](2-12-example4/add.cpp) + [2-12-example4/main.cpp](2-12-example4/main.cpp)：课后测验解答——给 `add.h` 加上 `ADD_H` guard。

### 原文中的"问题演示"（会报错，仅说明，不生成文件）

- 同一作用域里两次 `int x;` → 编译错误（重复定义）。
- 两次定义 `int foo()` → 编译错误。
- 不带 guard 的 `square.h`（内含 `getSquareSides()` 定义）+ `wave.h`（包含 `square.h`）+ `main.cpp`（两个都包含）→ 预处理后 `getSquareSides` 出现两次，编译错误。

> 作者注：原文示例为演示方便把函数定义写进了头文件，并提醒"通常不应这样做"。
