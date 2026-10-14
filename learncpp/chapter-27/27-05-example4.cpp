// ============================================================
// 来源小节：27.5 Exceptions, classes, and inheritance
// 示例说明：把派生类处理器放在前面——同样的 throw Derived() 现在由 Derived
//           处理器捕获。这是正确的写法：派生类处理器必须列在基类处理器之前。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
// 预期输出：caught Derived
// 备注：本示例逐字取自原文（含 main）。
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
    catch (const Derived& derived)
    {
        std::cerr << "caught Derived";
    }
    catch (const Base& base)
    {
        std::cerr << "caught Base";
    }

    return 0;
}
