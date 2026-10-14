# 20.7 Lambda captures

> 原文：https://www.learncpp.com/cpp-tutorial/lambda-captures/

## 核心概念

- **lambda 不会像嵌套代码块那样自动看到外层局部变量**：lambda 只能使用未显式捕获的对象中具有静态（或线程局部）存储期的对象，或 constexpr 对象；其它一切都需要捕获。
- **Tip**：lambda 只能访问"某些种类的"外部对象，包括静态存储期对象（全局、静态局部）和 constexpr 对象。
- **捕获子句（capture clause）**：用来间接让 lambda 访问它本来访问不到的周边作用域变量；把你想要的实体列进去。
- **捕获的原理**：捕获**不是**对原变量的直接访问，这个区别很重要。
- **Key insight**：被捕获的变量是外层变量的**副本**，而不是外层变量本身。
- **进阶阅读**：lambda 实际上是可像函数一样调用的对象（仿函数）。编译器生成一个自定义对象类型；每个被捕获的变量成为一个数据成员，在 lambda 对象实例化时初始化。
- **捕获默认是 const**：lambda 的 `operator()` 把捕获当作 const，所以不修改 `mutable` 就无法修改它们。
- **Warning**：因为被捕获的变量是 lambda 对象的成员，它们的值会在多次调用之间持续存在。
- **按引用捕获**：在变量前加 `&` 即按引用捕获；除非被捕获的变量本身是 const，否则引用捕获是非 const 的。当你本来就会按引用传递时（例如非基本类型），应优先按引用捕获。
- **多重捕获**：用逗号分隔，可以混用按值和按引用。
- **默认捕获**：`=` 按值捕获所有**被用到**的变量；`&` 按引用捕获所有被用到的变量。未被使用的变量不会被捕获。默认捕获可以与显式捕获混用，但每个变量只能被捕获一次，且默认捕获必须写在前面。
- **在捕获里定义新变量**：可以声明一个不带类型的变量，其类型会被推导；它在 lambda 被定义时计算一次。
- **悬垂的捕获变量**：按引用捕获可能在变量先于 lambda 消亡时悬垂，导致未定义行为。
- **Warning**：对引用捕获要格外小心，尤其是默认引用捕获——被捕获的变量必须比 lambda 活得久。
- **mutable lambda 的意外拷贝**：lambda 是对象，可以被拷贝；拷贝会复制当时的状态，于是状态可能分叉。把 lambda 传给 `std::function` 形参时可能会静默地拷贝它。
- **变通办法**：把 lambda 立即存进 `std::function`，或用 `std::ref` / `std::reference_wrapper` 包一层。
- **Rule**：标准库函数可能拷贝函数对象；如果 lambda 有 mutable 捕获，请用 `std::ref` 按引用传递。

## 最佳实践

- **Best practice**：只有在该值很短、且类型显而易见时，才在捕获里初始化变量；否则先把变量定义在外面再捕获它。
- **Best practice**：尽量避免 mutable lambda——非 mutable 的 lambda 更容易推理，也避免了拷贝与并行执行方面的隐患。
- **Warning**：被捕获的变量是 lambda 的成员，所以它们的值会跨多次调用持续存在。
- **Warning**：使用引用捕获（尤其是默认引用捕获 `[&]`）时要格外小心，被捕获的变量必须比 lambda 活得久。
- **Key insight**：捕获得到的是外层作用域变量的副本，而不是变量本身。
- **Tip**：lambda 可以不捕获就访问的外部对象只有：具有静态存储期的对象，以及 constexpr 对象。
- **For advanced readers**：lambda 是编译器生成的函数对象（仿函数），捕获变量是其数据成员，在实例化时初始化。
- **Rule**：库函数可能拷贝函数对象，所以含有 mutable 捕获的 lambda 应用 `std::ref` 按引用传递。

## 代码示例

- [20-07-example1.cpp](20-07-example1.cpp)：无捕获的 lambda 只能使用自己的参数。
- [20-07-example2-error.cpp](20-07-example2-error.cpp)：未捕获就使用外层变量 `search`（预期编译失败）。
- [20-07-example3.cpp](20-07-example3.cpp)：按值捕获 `[search]`。
- [20-07-example4-error.cpp](20-07-example4-error.cpp)：捕获默认是 const，直接修改会编译失败。
- [20-07-example5.cpp](20-07-example5.cpp)：用 `mutable` 修改捕获的副本（`main` 不受影响）。
- [20-07-example6.cpp](20-07-example6.cpp)：按引用捕获 `[&ammo]`，直接修改外层变量。
- [20-07-example7.cpp](20-07-example7.cpp)：按引用捕获统计排序比较次数。
- [20-07-example8.cpp](20-07-example8.cpp)：在捕获子句中定义并初始化新变量。
- [20-07-example9-ub.cpp](20-07-example9-ub.cpp)：悬垂引用（`makeWalrus` 返回按引用捕获局部变量的 lambda），**未定义行为**。
- [20-07-example10.cpp](20-07-example10.cpp)：拷贝 mutable lambda 导致状态分叉（输出 `1 2 2`）。
- [20-07-example11.cpp](20-07-example11.cpp)：把 mutable lambda 传给 `const std::function&` 形参，每次都被拷贝（输出 `1 1 1`）。
- [20-07-example12.cpp](20-07-example12.cpp)：先存进 `std::function` 再传递（输出 `1 2 3`）。
- [20-07-example13.cpp](20-07-example13.cpp)：用 `std::ref` 包装后传递（输出 `1 2 3`，即使形参按值传递）。
- [20-07-quiz2.cpp](20-07-quiz2.cpp)：Quiz 2 解答——按值捕获 `[=]`，输出 `I like grapes`。
- [20-07-quiz3.cpp](20-07-quiz3.cpp)：Quiz 3 解答——"平方数猜谜"游戏完整程序。

> 本节代码为按原文描述重建（原文中的长代码块未能逐字获取）；Quiz 3 解答依据原文解答思路重建。
>
> Quiz 1 是概念题（哪些变量无需捕获即可使用），答案是：具有静态存储期或为 constexpr 的对象
> 无需捕获即可使用，其它局部变量都需要捕获。该题不需要代码文件。
