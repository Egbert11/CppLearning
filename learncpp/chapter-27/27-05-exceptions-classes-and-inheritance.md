# 27.5 Exceptions, classes, and inheritance

> 原文：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

## 核心概念

- **成员函数与运算符中也能用异常**：异常在成员函数里很有用，在**重载运算符**中"更是如此"，因为运算符很难返回错误码。
- **`operator[]` 中 assert 与 throw 的对比**：断言可以守护非法下标，但会中止程序；抛异常对调用者更友好。
- **重载运算符签名受限**：它们不能再加参数、也不能额外返回错误码或布尔值，而异常不改变函数签名，正好契合。
- **构造函数可抛出以表示失败**：若构造函数必须失败（例如输入非法），抛异常会中止构造；此时已构造完成的成员仍会被正常析构。
- **构造失败时本类自己的析构函数不会运行**：因为对象从未构造完成，所以它无法清理构造函数体内分配的资源。
- **成员会自我清理**：既然成员在构造失败时也会被析构，就把资源放进成员对象里管理（而不是直接在构造函数体里分配），由成员负责清理——这正是 RAII 的理念。
- **优先用标准 RAII 类型**：与其手写管理资源的成员，不如使用库提供的类型，如 `std::fstream`、`std::unique_ptr` 等智能指针。
- **基本类型不适合做异常类型**：含义模糊；在一个多操作的 try 块里，`catch (int)` 无法告诉你究竟是哪一步操作失败了。
- **异常类的定义**：一个"异常类"就是被设计成用来作为异常抛出的普通类。
- **按（const）引用捕获类异常**：可避免拷贝，并防止派生异常类型发生对象切片；一般不推荐按指针捕获。
- **继承同样适用于处理器**：处理器不仅匹配其精确类型，也匹配由它派生出的类型，因此若基类处理器在前，派生类异常会被它捕获。
- **顺序很重要——派生类在前**：编译器按顺序逐个检查处理器，把基类处理器列在前面会让后面的派生类处理器永远得不到机会。
- **`std::exception`**：定义在 `<exception>` 中，是一个小型接口类，作为标准库异常的基类（C++20 时有 28 个，之后还在增加）。
- **`what()`**：`std::exception` 有一个虚函数 `what()`，返回一段 C 风格描述串，多数派生类会重写它。该字符串仅用于描述性文字——**绝不要比较它**，因为它不保证跨编译器一致。
- **分层处理器**：可以用专门的处理器针对某个异常类型，再用一个放在最后的 `std::exception` 处理器兜住"其余一切"。
- **不要直接抛 `std::exception`**：没有人这么做，你也不该——但抛出其他标准异常没问题，其中 `std::runtime_error`（来自 `<stdexcept>`）是很受欢迎、可接受自定义消息的通用选择。
- **自定义异常可派生自 `std::exception` 或 `std::runtime_error`**：派生自 `std::runtime_error` 可以省去自己写字符串处理与 `what()` 重写。
- **`what()` 是 `noexcept` 的**：重写时说明符必须与之匹配。
- **异常对象的生存期**：抛出时，编译器把异常对象拷贝到调用栈之外的某处内存，使其在展开过程中存活到被处理；因此被抛出的对象通常必须可拷贝（某些编译器可能改为移动或省略拷贝）。
- **不要有悬垂引用**：异常对象不应持有指向栈上对象的指针或引用，因为展开可能销毁那些对象。

## 最佳实践

- **Best practice**（捕获异常）：基本类型的异常可以按值捕获（拷贝开销小）；类类型的异常应按（const）引用捕获，以防昂贵的拷贝与对象切片。
- **Rule**（处理器排序）：派生异常类的处理器应列在基类处理器之前。
- **Tip**（生存期）：异常对象必须可拷贝。

（本节无 Author's note / Warning 标注。）

## 代码示例

- [27-05-example1.cpp](27-05-example1.cpp)：构造函数抛出后成员被正常析构、本类析构函数不执行，输出 `Member allocated some resources` / `Member cleaned up` / `Oops`。
- [27-05-example2.cpp](27-05-example2.cpp)：自定义异常类 `ArrayException` 配合重载 `operator[]`，输出 `An array exception occurred (Invalid index)`。
- [27-05-example3.cpp](27-05-example3.cpp)：基类处理器在前——输出 `caught Base`（用 -Wall 会有 -Wexceptions 警告，正对应原文的"反例"）。
- [27-05-example4.cpp](27-05-example4.cpp)：派生类处理器在前——输出 `caught Derived`。
- [27-05-example5.cpp](27-05-example5.cpp)：用 `catch (const std::exception&)` 捕获标准异常，输出 `Standard exception: <what()>`。
- [27-05-example6.cpp](27-05-example6.cpp)：抛出 `std::runtime_error("Bad things happened")`，输出 `Standard exception: Bad things happened`。
- [27-05-example7.cpp](27-05-example7.cpp)：自定义异常派生自 `std::exception` 并重写 `what()`，输出 `An array exception occurred (Invalid index)`。
- [27-05-example8.cpp](27-05-example8.cpp)：自定义异常改派生自 `std::runtime_error`（无需重写 `what()`），输出 `An array exception occurred (Invalid index)`。
- [27-05-example9-error.cpp](27-05-example9-error.cpp)：拷贝构造函数被删除、`throw d;` 无法拷贝异常对象 → 编译失败（-error）。

> 说明：以上示例均逐字取自原文。原文中另有 `operator[]` 的三种写法（无检查 / 用 `assert` / 用 `throw index`）、用原生指针与 `std::unique_ptr` 管理的 `Foo`、以及"多操作 try 块里 `catch(int)` 分不清哪步出错"等**片段**，因其不是可独立运行的程序，本目录未生成对应文件。example5 的 `what()` 文本依实现而定：作者在 MSVC 下得到 `string too long`，本机 MinGW/libstdc++ 下为 `basic_string::_M_replace_aux`（属正常现象，切勿依赖该文本内容）。
