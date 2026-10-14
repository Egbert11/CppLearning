// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：修复版——写一个只交换底层成员（m_name）的自由 swap，
//           让移动构造/移动赋值调用它而不是 std::swap，从而避免递归。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期输出：
//   Move assign
//   Joe
// 备注：本节代码为按原文描述重建（原 Example 10）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>
#include <utility> // for std::swap, std::move

class Name
{
private:
    std::string m_name{};

public:
    Name(std::string_view name) : m_name{ name } {}

    Name(const Name& name) = delete;
    Name& operator=(const Name& name) = delete;

    Name(Name&& name) noexcept
    {
        std::cout << "Move ctor\n";
        swap(*this, name); // 调用下面只交换成员的自由函数
    }

    Name& operator=(Name&& name) noexcept
    {
        std::cout << "Move assign\n";
        swap(*this, name); // 调用下面只交换成员的自由函数
        return *this;
    }

    const std::string& get() const { return m_name; }

    // 注意：只交换成员，而不是对 Name 本身调用 std::swap
    friend void swap(Name& a, Name& b) noexcept
    {
        std::swap(a.m_name, b.m_name);
    }
};

int main()
{
    Name joe{ "Joe" };
    Name bob{ "Bob" };

    bob = std::move(joe);

    std::cout << bob.get() << '\n';

    return 0;
}
