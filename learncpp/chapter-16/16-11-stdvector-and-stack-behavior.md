# 16.11 std::vector and stack behavior

> 原文：https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/

## 核心概念

- **要解决的问题**：程序需要接受"数量未知"的用户输入（例如测验成绩）时，个数在编译期未知、每次运行还可能不同，但仍要把这些值存进 `std::vector`。
- **方案一：先让用户给出个数**：按该个数创建 vector，再读入那么多值。这要求用户事先数对，一旦超过十个二十个就很繁琐。
- **方案二：假设一个固定上限**：按某个上限（如 30）分配或 resize，读完后缩到实际个数。上限是任意的，用户还可能不够用。
- **方案三：按需增长**：容量用完就扩展 vector 虽然可行，但把尺寸管理混进程序逻辑，增加了复杂度与出错风险。
- **真正的问题**：靠猜测元素个数来确定 vector 尺寸是错误策略；对数量确实未知的情形另有一套办法。
- **什么是栈**：用"食堂盘子"类比（沉重的盘子只能一个个从顶上取放），栈只允许在顶端添加或移除，不允许改动中间/底部，顺序是**后进先出（LIFO）**。
- **编程中的栈**：一种容器类型，插入与移除都按 LIFO 顺序，通常提供 **push**（把新元素放到顶——必需）与 **pop**（移除顶元素——必需；可返回被移除元素也可返回 void）。
- **可选的栈操作**：**Top/Peek**（读取顶元素但不移除）、**Empty**（判断是否为空）、**Size**（元素个数）。
- **调用栈**：函数调用也用栈来跟踪——调用时压入一条记录，返回时弹出，所以栈顶总是当前正在执行的函数。
- **push/pop 序列示意**：从空开始——Push 1 → `1`；Push 2 → `1 2`；Push 3 → `1 2 3`；Pop → `1 2`；Push 4 → `1 2 4`；Pop → `1 2`；Pop → `1`；Pop → 空。
- **C++ 中的栈**：标准库没有单独的"栈容器"（那会限制灵活性），而是把栈操作作为成员函数加到那些能在一端高效插入/移除的标准容器上：`std::vector`、`std::deque`、`std::list`。
- **信箱类比（旁注）**：一列每个只能放一件物品、顶端带尖杆的信箱；一个标记指向"最下面那个空格"作为栈顶。push 填满标记处并把标记上移；pop 把标记下移并清空该格。这个标记就是 `length`，信箱总数就是 `capacity`。
- **`std::vector` 的栈接口**：`push_back()`（push，追加到尾部）、`pop_back()`（pop，返回 void，移除最后一个元素）、`back()`（top/peek，不移除）、`emplace_back()`（另一种 push，可能更高效）。
- **Key insight（重新分配）**：`push_back()` 与 `emplace_back()` 都会增大 vector 长度，并在容量不足时触发重新分配。与 `operator[]` / `at()` 不同，它们会改变尺寸。
- **增长时多分配一点**：重新分配时通常会多分配一些空间（超出新增的那一个元素），以免紧接着又触发一次重新分配。多分配多少由实现定义：GCC/Clang 把容量翻倍（2 → 4），Visual Studio 2022 乘 1.5（2 → 3），因此输出可能因编译器而异。
- **直接 resize 不适合栈式行为**：重新分配的代价与长度成正比，所以预先定尺寸看似诱人——但括号初始化与 `resize()` 会同时设置容量**和长度**，于是你的数据下面垫着一堆默认（零）元素。
- **Key insight（resize vs reserve）**：`resize()` 改变 vector 的长度（必要时也改变容量）；`reserve()` 只改变容量（必要时）。
- **Tip**：用下标访问时用 `resize()` 增长 vector（保证下标合法）；用栈操作访问时用 `reserve()`（增加容量但不增加元素）。
- **`push_back()` vs `emplace_back()`**：对象已存在时二者等价，此时应优先 `push_back()`。当需要构造一个 vector 元素类型的临时对象再 push 时，`emplace_back()` 更高效：它转发构造函数参数，让对象直接在 vector 内构造，省去一次复制。`push_back()` 不会使用 explicit 构造函数，`emplace_back()` 会——因此前者更"低调安全"，后者更容易意外触发非预期的转换。另外，C++20 之前 `emplace_back()` 不能配合聚合初始化使用。
- **解决挑战**：用栈操作后，无需计数、下标或维护长度，vector 负责存储，程序专注逻辑。

## 最佳实践

- **Key insight（重新分配）**：`push_back()` 与 `emplace_back()` 会增大长度，并在容量不够时触发重新分配。
- **Key insight（resize vs reserve）**：`resize()` 改变长度（必要时也改变容量）；`reserve()` 只改变容量（必要时）。
- **Tip**：用下标方式增长用 `resize()`；用栈式方式增长用 `reserve()`。
- **Best practice（push_back vs emplace_back）**：当需要创建新临时对象加入容器、或需要使用 explicit 构造函数时，优先 `emplace_back()`；其他情况优先 `push_back()`。
- **Of note（emplace_back 的注意点）**：因为 `emplace_back()` 接受 explicit 构造函数而 `push_back()` 不接受，它"更危险"，可能混入非预期的转换；且在 C++20 之前不支持聚合初始化。
- **Author's aside**：信箱纵列的类比比"盘子"更能说明数组如何实现栈，其中标记对应 `length`，格子总数对应 `capacity`。

## 代码示例

- [16-11-example1.cpp](16-11-example1.cpp)：`push_back()` / `back()` / `pop_back()` 配合容量与长度跟踪（原 Example 1）。
- [16-11-example2.cpp](16-11-example2.cpp)：把初始化改为括号 `(3)`，长度一开始就是 3、垫着三个 0（原 Example 2）。
- [16-11-example3.cpp](16-11-example3.cpp)：用 `reserve(6)` 只增加容量、不改变长度（原 Example 3）。
- [16-11-example4.cpp](16-11-example4.cpp)：`push_back()` 与 `emplace_back()` 的对比，含 explicit 构造函数的情形（原 Example 4；原例中 `stack.push_back({ 2 });` 为预期编译错误，此处已注释并注明）。
- [16-11-example5.cpp](16-11-example5.cpp)：用栈操作解决"数量未知的成绩"问题（原 Example 5，交互式）。
- [16-11-quiz1.cpp](16-11-quiz1.cpp)：测验解答——输出指定的 push/pop 序列。

> 说明：本节代码为按原文描述重建。capacity 因实现而异，GCC/Clang 与 MSVC 的增长策略不同（翻倍 vs ×1.5），示例输出以 GCC/Clang 为准。
