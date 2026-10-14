// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：基类处理器先于派生类处理器时，抛出的 Derived 异常会被 Base 捕获
//           ——因为处理器按顺序匹配，Base 也能匹配其派生类，于是排在后面的
//           Derived 处理器永远得不到机会。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期输出：caught Base
// 备注：本示例逐字取自原文（含 main）。这段代码本身就是教学上的"反例"：g++ -Wall
//       会给出一条 -Wexceptions 警告——'Derived' will be caught by earlier handler，
//       正是原文想说明的"基类处理器在前会拦住派生类"。
// ============================================================
#include <iostream>

class Base
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

int main()
{
    try
    {
        throw Derived();
    }
    catch (const Base& base)
    {
        std::cerr << "caught Base";
    }
    catch (const Derived& derived)
    {
        std::cerr << "caught Derived";
    }

    return 0;
}
