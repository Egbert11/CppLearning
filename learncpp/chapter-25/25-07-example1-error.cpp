// ---------------------------------------------------------------------------
// 来源小节：25.7 Pure virtual functions, abstract base classes, and interface classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
// 示例说明：演示「纯虚函数」（`= 0`），以及把 `= 0` 用在非虚函数上会产生的编译错误。
// 预期错误（GCC）：error: initializer specified for non-virtual method 'int Base::doSomething()'
//           —— 即非虚函数不能置 0；同时 Base 因含有纯虚函数 getValue() 而成为抽象类。
//           编译命令：g++ -std=c++20 -Wall 25-07-example1-error.cpp
//           该文件按设计无法编译，请勿修复。
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <string_view>

class Base
{
public:
    std::string_view sayHi() const { return "Hi"; } // a normal non-virtual function

    virtual std::string_view getName() const { return "Base"; } // a normal virtual function

    virtual int getValue() const = 0; // a pure virtual function

    int doSomething() = 0; // Compile error: can not set non-virtual functions to 0
};
