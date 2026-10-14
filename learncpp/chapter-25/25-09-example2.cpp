// ---------------------------------------------------------------------------
// 来源小节：25.9 Object slicing
// 原文链接：https://www.learncpp.com/cpp-tutorial/object-slicing/
// 示例说明：对象切片（object slicing）——把 Derived 对象直接赋值给 Base 对象，
//           只有 Base 部分被复制，派生部分被「切掉」；对象的虚表指针仍指向 Base，
//           所以 getName() 解析到 Base::getName()。
// 预期输出：base is a Base and has value 5
// 原文该例的主片段为逐字提取；Base/Derived 定义取自原文同一小节前例。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string_view>

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual ~Base() = default;

    virtual std::string_view getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

   std::string_view getName() const override { return "Derived"; }
};

// --- 原文示例片段 ---
int main()
{
    Derived derived{ 5 };
    Base base{ derived }; // what happens here?
    std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';

    return 0;
}
