// ---------------------------------------------------------------------------
// 来源小节：25.9 Object slicing
// 原文链接：https://www.learncpp.com/cpp-tutorial/object-slicing/
// 示例说明：std::vector<Base> 的元素类型是 Base，push_back(Derived{6}) 会切片，
//           派生部分丢失，多态失效。
// 预期输出：
//   I am a Base with value 5
//   I am a Base with value 6
// 原文该例的 main() 为逐字提取；Base/Derived 定义取自原文同一小节前例。
// ---------------------------------------------------------------------------

#include <iostream>
#include <string_view>
#include <vector>

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
	std::vector<Base> v{};
	v.push_back(Base{ 5 });    // add a Base object to our vector
	v.push_back(Derived{ 6 }); // add a Derived object to our vector

        // Print out all of the elements in our vector
	for (const auto& element : v)
		std::cout << "I am a " << element.getName() << " with value " << element.getValue() << '\n';

	return 0;
}
