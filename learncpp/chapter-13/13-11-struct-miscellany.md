# 13.11 Struct miscellany

> 原文：https://www.learncpp.com/cpp-tutorial/struct-miscellany/

## 核心概念

- **结构体可含程序定义类型的成员**：struct（和 class）的成员本身可以是程序定义类型，有两种做法。
- **做法一：复用全局作用域中定义的类型**：先在一个全局作用域定义某个 struct，再把它作为另一个 struct 的成员。
- **嵌套初始化**：初始化外层 struct 时，用嵌套的初始化列表初始化内层 struct 成员。
- **重复成员选择**：访问嵌套成员需要两次成员选择运算符，例如 `myCompany.CEO.wage`。
- **做法二：把一个类型嵌套在另一个类型内部**：若某类型只作为另一类型的一部分存在，可将其嵌套，再用 `Company::Employee` 访问。
- **嵌套类型在类中更常见**：细节留待 15.3（嵌套/成员类型）。
- **拥有者 vs 观察者**：拥有者（owner）管理自己的数据并控制其销毁；观察者（viewer）只是查看别人的数据，不控制其生命周期。
- **优先使用拥有型 struct**：struct/class 通常应拥有其持有的数据；拥有型成员在 struct 存活期间始终有效，且不会意外改变。
- **如何让 struct 成为拥有者**：给每个数据成员一个拥有型类型（而非观察者、指针或引用）；若所有成员都是拥有者，则该 struct 本身也是拥有者。
- **悬垂风险**：观察者成员可能比它所观察的对象活得更久，从而成为悬垂成员；访问它是未定义行为。
- **字符串通常用 `std::string`**：因为 `std::string` 拥有其数据，而 `std::string_view` 只是观察。
- **临时对象生命周期示例**：返回临时 `std::string` 的函数，其返回值在包含该调用的完整表达式结束时被销毁；拷贝进拥有者没问题，但用观察者去观察它就会悬垂。
- **struct 的大小不一定等于成员之和**：大小**至少**是成员大小总和，但可能更大。
- **填充（padding）**：出于性能原因，编译器有时会在 struct 中插入空隙（填充字节）。
- **对齐背景（进阶）**：可选阅读维基百科"数据结构对齐"条目；不是理解 struct 的必需内容。
- **填充可能很显著**：同样成员换个顺序，struct 大小就会变，因为编译器自己**不会**重排成员。
- **Tip：减少填充**：手动按成员大小**递减**的顺序声明成员，因为编译器无法替你重排。

## 最佳实践

- **Best practice**：struct 和 class 通常应是拥有者；最简单的方法是保证每个数据成员都是拥有型（而不是观察者、指针或引用）。
- **Author's note**：Practice safe structs. Don't let your member dangle.（写出安全的 struct，别让成员悬垂。）
- **Tip**：You can minimize padding by defining your members in decreasing order of size.（按大小递减顺序定义成员可最小化填充。）
- **For advanced readers**：填充原因超出本节范围，好奇者可查阅链接的维基百科条目，非必读。

## 代码示例

- [13-11-example1.cpp](13-11-example1.cpp)：`Employee` 定义在全局，作为 `Company` 的成员；用嵌套初始化列表初始化并打印工资（原 Example 1）。
- [13-11-example2.cpp](13-11-example2.cpp)：把 `Employee` 嵌套进 `Company`（经 `Company::Employee` 访问），同样方式初始化（原 Example 2）。
- [13-11-example3-ub.cpp](13-11-example3-ub.cpp)：拥有者 vs 观察者——把 `getName()` 返回的临时 `std::string` 交给 `Owner`（安全）与 `Viewer`（悬垂，未定义行为）（原 Example 3）。
- [13-11-example4.cpp](13-11-example4.cpp)：`sizeof` 各基本类型与含它们的 struct，观察填充（原 Example 4）。
- [13-11-example5.cpp](13-11-example5.cpp)：相同成员不同顺序导致 struct 大小不同（填充）（原 Example 5）。

> 说明：本节代码为按原文清单与站点标准写法重建。Example 3 打印 `Viewer` 的 `string_view` 属于未定义行为，输出依实现而定。
