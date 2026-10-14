// ============================================================
// 来源小节：24.7 Calling inherited functions and overriding behavior（原 Example 6）
// 示例说明：基类的友元函数不是成员，作用域解析对它无效。要在派生类友元里触达
//           基类版本，需用 static_cast 把派生对象临时当作基类引用来处理。
// 原文链接：https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior/
// 预期输出：
//   In DerivedIn Base
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Base&)
    {
        out << "In Base";
        return out;
    }
};

class Derived : public Base
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Derived& d)
    {
        out << "In Derived";
        // to call the base class friend, cast to base reference (not by value, to avoid a copy)
        out << static_cast<const Base&>(d);
        return out;
    }
};

int main()
{
    Derived d{};
    std::cout << d << '\n';

    return 0;
}
