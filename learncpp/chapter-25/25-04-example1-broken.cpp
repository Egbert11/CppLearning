// ============================================================
// 来源小节：25.4 Virtual destructors, virtual assignment, and overriding virtualization（原 Example 1）
// 示例说明：坏实践 —— 非虚析构函数。通过 Base* 删除 Derived 对象时只调用 Base::~Base()，
//           Derived::~Derived() 不执行，m_array 永不释放（内存泄漏）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/
// 预期输出：
//   Calling ~Base()
// 备注：故意使用非虚析构（坏实践），编译器可能给出警告，勿"修复"。
// ============================================================
#include <iostream>

class Base
{
public:
    ~Base() // note: not virtual
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

    ~Derived() // note: not virtual (your compiler may warn you about this)
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main()
{
    Derived* derived{ new Derived(5) };
    Base* base{ derived };

    delete base; // Calls ~Base(), not ~Derived() --> m_array leaks

    return 0;
}
