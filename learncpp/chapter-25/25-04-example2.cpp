// ============================================================
// 来源小节：25.4 Virtual destructors, virtual assignment, and overriding virtualization（原 Example 2）
// 示例说明：把析构函数声明为 virtual 后，通过 Base* 删除 Derived 对象会先调用
//           ~Derived() 再调用 ~Base()，资源得到正确释放。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/
// 预期输出：
//   Calling ~Derived()
//   Calling ~Base()
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Base
{
public:
    virtual ~Base() // note: virtual
    {
        std::cout << "Calling ~Base()\n";
    }
};

class Derived : public Base
{
private:
    int* m_array{};

public:
    Derived(int length)
        : m_array{ new int[length] }
    {
    }

    ~Derived() // note: virtual (implicitly virtual because Base's destructor is virtual)
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main()
{
    Derived* derived{ new Derived(5) };
    Base* base{ derived };

    delete base; // Calls ~Derived() then ~Base()

    return 0;
}
