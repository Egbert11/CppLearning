# 12.6 Pass by const lvalue reference

> 原文：https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/

## 核心概念

- **const 引用的绑定灵活性**：非 const 引用只绑定可修改左值，而对 const 的引用可绑定可修改左值、不可修改左值和右值。因此把引用形参设为 const，它就能接受任意种类的实参。
- **按 const 引用传递的好处**：与按非 const 引用传递一样，主要优势是**不拷贝实参**；外加一项保证——函数不能改动被引用值。
- **为何右值可绑定 const 左值引用**：若没有这条规则，就无法把字面量或其他右值交给使用按引用传递的函数。
- **类型不同的实参**：const 左值引用可以绑定到类型不同但可转换的值，会创建引用类型的临时量并绑定它。这条规则主要是为了调用方在"按值"和"按 const 引用"两种形参下能用同样方式传值。
- **性能注意**：按值传递本来就预期拷贝一次，额外的转换拷贝通常无害（且常被优化掉）；但按引用传递本意是避免拷贝，隐式转换"通常会导致一次（可能昂贵的）拷贝"，并不理想。
- **混合传递方式**：一个函数可对每个形参分别决定按值还是按引用传递。
- **如何选择值/引用**：基本类型和枚举类型拷贝廉价，通常按值；类类型拷贝可能昂贵，通常按 const 引用。
- **廉价拷贝的定义**：粗略地说，对象占用不超过 2 个"字"（字≈地址大小）且无额外初始化开销，就是廉价拷贝（示例 5 给出宏测试）。
- **string_view vs const std::string&**：多数情况下 `std::string_view` 是更好的形参类型，因为它能高效处理更多实参类型，并允许传入子串而无需先拷贝进自己的 string。
- **例外（偏好 const std::string&）**：用 C++14 或更早（无 `std::string_view`）；或函数内部调用需要 C 风格字符串或 `std::string` 的东西——因为 `std::string_view` "不保证以空字符结尾"，也不能廉价地转回 `std::string`。
- **高级：拷贝开销**：拷贝成本与对象大小及初始化开销（开关文件/数据库、动态分配）相关。绑定引用总是很快，约等于拷贝一个基本类型。
- **高级：使用开销**：小的按值实参可放进 CPU 寄存器，每次用值形参是一次寄存器/内存访问；引用形参需要额外一次访问来找到被引用对象，所以每次用是一次访问加第二次内存访问。
- **高级：别名（aliasing）**：当两个指针/引用可能指向同一对象时，优化器必须保守；按值传递拷贝实参，别名不可能，从而允许更激进的优化。
- **为何不一切皆引用**：对廉价拷贝对象，拷贝成本与绑定相当，而访问更快、优化更好；对昂贵拷贝对象，拷贝成本占主导。
- **旁注（宏）**：用函数式宏让 `isSmall` 既能接收对象也能接收类型名，因为 C++ 函数不能把类型作为参数。
- **高级：效率对比**：`std::string_view` 形参对 `std::string` 实参（廉价转换）、`std::string_view` 实参（廉价拷贝）、C 风格字符串/字面量（廉价转换）都高效；`const std::string&` 形参只对 `std::string` 实参廉价，对 `std::string_view` 实参需显式 `static_cast` 产生昂贵的 `std::string` 临时量，对 C 风格字符串/字面量也隐式转换为 `std::string`，同样昂贵。
- **高级：访问与子串**：`std::string_view` 形参是普通对象，其"所视字符串"直接访问；而 `std::string&` 需要一次间接步骤；构造并传入子串视图也很廉价，相比把子串拷进 `std::string` 便宜得多。

## 最佳实践

- **Best practice**：**除非有特定理由，否则优先按 const 引用传递，而不是按非 const 引用传递。**
- **Best practice**：**经验法则：基本类型按值传递，类类型按 const 引用传递。** 若拿不准，就用按 const 引用传递，因为出现意外行为的可能更小。
- **Best practice**：**优先用 `std::string_view`（按值）传字符串，而不是 `const std::string&`**，除非被调用的其他函数需要 C 风格字符串或 `std::string`。
- **Warning**：**按引用传递时，务必让实参类型与引用类型匹配，否则会发生意外（且可能昂贵）的转换。**
- **As an aside**：函数式宏让 `isSmall` 可传对象或类型名，普通函数做不到；未知实现细节时，假定多数标准库类都有初始化开销。
- **Tip——通常按值传递**（更高效）：枚举类型（无/有作用域）；视图与 span 如 `std::string_view`、`std::span`；模仿引用/非拥有指针的类型（迭代器、`std::reference_wrapper`）；拷贝廉价、具值语义的类类型（由基本类型构成的 `std::pair`、`std::optional`、`std::expected`）。
- **Tip——使用按引用传递**：函数必须修改的实参；不可拷贝的类型（如 `std::ostream`）；拷贝涉及所有权语义的类型（`std::unique_ptr`、`std::shared_ptr`）；带虚函数或可能被继承的类型（避免对象切片）。

## 代码示例

- [12-06-example1.cpp](12-06-example1.cpp)：const 引用形参绑定可修改左值、不可修改左值、右值三种实参（输出 5、5、5）（原 Example 1）。
- [12-06-example2-error.cpp](12-06-example2-error.cpp)：修改 const 引用形参不被允许 —— 预期编译失败（原 Example 2）。
- [12-06-example3.cpp](12-06-example3.cpp)：把 `int` 传给按值 `double` 形参与 `const double&` 形参（输出 5、5）（原 Example 3）。
- [12-06-example4.cpp](12-06-example4.cpp)：同一函数混合按值、按引用、按 const 引用三种形参（原 Example 4）。
- [12-06-example5.cpp](12-06-example5.cpp)：用宏 `isSmall` 测试类型/对象是否拷贝廉价（输出 true、true、false）（原 Example 5）。
- [12-06-example6-error.cpp](12-06-example6-error.cpp)：`std::string` / `string_view` / 字面量传给两种形参 —— `printS(sv)` 行预期编译失败（原 Example 6）。
- [12-06-example7.cpp](12-06-example7.cpp)：`const std::string&` 与 `std::string_view` 两种重载声明（原 Example 6 之后的重载声明）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。
