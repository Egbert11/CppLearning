// ---------------------------------------------------------------------------
// 来源小节：25.7 Pure virtual functions, abstract base classes, and interface classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
// 示例说明：演示「含纯虚函数的类成为抽象基类，不能实例化」。
// 预期错误：error: cannot declare variable 'base' to be of abstract type 'Base'
//           （Base 中有未实现的纯虚函数 getValue()）。
//           编译命令：g++ -std=c++20 -Wall 25-07-example2-error.cpp
//           该文件按设计无法编译，请勿修复。
// 说明：为隔离错误，此处 Base 省略了原文 Example 1 中那行会先报错的
//       `int doSomething() = 0;`（原文 Example 2 假定了该定义）。
//       main() 为原文逐字提取。
// ---------------------------------------------------------------------------

#include <string_view>

class Base
{
public:
    std::string_view sayHi() const { return "Hi"; } // a normal non-virtual function
    virtual std::string_view getName() const { return "Base"; } // a normal virtual function
    virtual int getValue() const = 0; // a pure virtual function
};

int main()
{
    Base base {}; // We can't instantiate an abstract base class, but for the sake of example, pretend this was allowed
    base.getValue(); // what would this do?

    return 0;
}
