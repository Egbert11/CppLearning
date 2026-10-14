// ---------------------------------------------------------------------------
// 来源小节：25.9 Object slicing
// 原文链接：https://www.learncpp.com/cpp-tutorial/object-slicing/
// 示例说明：按值传参也会切片——形参是 Base（不是引用），实参 Derived 被切掉派生部分。
// 预期输出：I am a Base
// 原文该例的 printName() 与 main() 为逐字提取；Base/Derived 定义取自原文同一小节前例。
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
void printName(const Base base) // note: base passed by value, not reference
{
    std::cout << "I am a " << base.getName() << '\n';
}

int main()
{
    Derived d{ 5 };
    printName(d); // oops, didn't realize this was pass by value on the calling end

    return 0;
}
