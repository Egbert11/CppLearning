# 2.8 Programs with multiple code files

> 原文：https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/

## 核心概念

- **把程序拆成多个文件**：程序变大后，为了便于组织或复用，会把代码分散到多个文件中。IDE 让多文件管理轻松很多；在项目里新增的代码文件应使用 `.cpp` 扩展名。
- **各 IDE 添加文件的方式**：Visual Studio 里右键 *Source Files* → *Add > New Item…* 选 "C++ File (.cpp)"；若是从 File 菜单建的文件不会自动加入项目，需用 *Add > Existing Item* 手动加入。Code::Blocks 用 *File > New > File…* 选 "C/C++ source"，文件名带 `.cpp`，并点 *All* 选中所有构建目标；gcc 命令行则需自己建文件并把每个相关文件都列到编译行。
- **VS Code 设置**：用 Explorer 或 *File > New File* 建文件（若落到 `.vscode` 里就拖出来），再编辑 `tasks.json`——可以显式列出文件，或用通配符一次性编译目录下所有 `.cpp`。
- **编译是逐文件独立进行的**：编译器一次只处理一个文件，不认识其它文件的内容，也不记得之前编译过的文件。
- **这样设计是有意的**：好处是源文件可按任意顺序编译、只改动过的文件才需重编译、并能减少文件之间的命名冲突。
- **跨文件调用要用前置声明**：函数定义在另一个文件里时无法靠调整顺序解决，于是在调用处写前置声明（函数原型），告诉编译器该标识符在别处定义。
- **链接（linking）**：链接器把某文件里的调用和另一文件里的定义匹配起来，于是各文件能使用其它文件定义的函数。
- **包含是"各自独立"的**：因为每个文件独立编译，任何用到 `std::cout` / `std::cin` 的文件都必须自己 `#include <iostream>`。
- **关键理解：标识符必须连到它的定义**。若编译器在本文件里既没见过前置声明也没见过定义，就会在使用处报错；此时若定义在别的文件、且对链接器可见，则由链接器来建立连接；否则链接器报"找不到定义"。
- **排错**：若出现关于 `add` 的**编译错误**，通常是 `main.cpp` 里漏写了前置声明；若出现关于 `add` 的**链接错误**，最可能是那个 `.cpp` 未加入项目或编译命令（也可能是加到了别的项目、或被设为不参与编译/链接）。
- **永远不要 `#include` 一个 `.cpp` 文件**：从别的文件包含 `.cpp` 或许能编过，但随着程序变大，会增加命名冲突和意料之外问题的风险。

## 最佳实践

- 项目里新增代码文件时，一律给它 `.cpp` 扩展名。
- 每个新 `.cpp` 文件都必须加入项目，否则它不会被真正编译。
- 每个文件必须自行 `#include` 它用到的头文件（例如用了 `std::cout` 就包含 `<iostream>`），不要指望其它文件已经包含。
- 不要 `#include` `.cpp` 文件。

## 代码示例

- [2-08-example1/main.cpp](2-08-example1/main.cpp) + [2-08-example1/add.cpp](2-08-example1/add.cpp)：多文件程序——`add()` 定义在 `add.cpp`，`main.cpp` 用前置声明调用它，编译时两个文件一起交给编译器再链接。
- [2-08-example2/main.cpp](2-08-example2/main.cpp) + [2-08-example2/input.cpp](2-08-example2/input.cpp)：课后测验解答——把 `getInteger()` 拆到 `input.cpp`，`main.cpp` 自带 `<iostream>` 并前置声明 `getInteger()`。

> 编译多文件示例：`g++ -std=c++20 -Wall 2-08-example1/main.cpp 2-08-example1/add.cpp -o main`

### 原文中"无法编译"的示例（仅说明，不生成文件）

- 把 `add()` 定义放在 `main()` **之后**的单文件程序会编译失败（`add` 在定义前被使用）。
- `main.cpp` 调用 `add()` 却不写前置声明 → 编译错误：`'add': identifier not found`。
- `add.cpp` 未加入编译/项目 → 链接错误：`unresolved external symbol "int __cdecl add(int,int)"`。
