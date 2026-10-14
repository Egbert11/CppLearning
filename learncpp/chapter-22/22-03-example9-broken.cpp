// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：坏实践演示——在移动构造/移动赋值里调用 std::swap(*this, name)。
//           std::swap 自身又会调用该类类型的移动操作，于是无限递归，
//           不断打印 "Move assign"/"Move ctor"，最终栈溢出崩溃。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期输出：反复输出 "Move assign" 与 "Move ctor" 直到栈溢出（segfault）。
// 备注：本节代码为按原文描述重建（原 Example 9）。请勿运行。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

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
        std::swap(*this, name); // bad!
    }

    Name& operator=(Name&& name) noexcept
    {
        std::cout << "Move assign\n";
        std::swap(*this, name); // bad!
        return *this;
    }

    const std::string& get() const { return m_name; }
};

void swap(Name& a, Name& b) noexcept
{
    std::swap(a, b); // bad: 又走 std::swap -> Name 的移动操作 -> 无限递归
}

int main()
{
    Name joe{ "Joe" };
    Name bob{ "Bob" };

    swap(joe, bob); // 触发无限递归

    return 0;
}
