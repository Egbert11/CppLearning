// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：Name 的四个特殊成员函数全部 = delete。对临时对象赋值
//           （joe = Name{ "Bob" }）会命中"已删除的移动赋值"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期错误：编译失败（勿修复）。典型报错：
//   error: use of deleted function 'Name& Name::operator=(Name&&)'
// 备注：本节代码为按原文描述重建（原 Example 7）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Name
{
private:
    std::string m_name{};

public:
    Name(std::string_view name) : m_name{ name } {}

    Name(const Name& name) = delete;
    Name& operator=(const Name& name) = delete;
    Name(Name&& name) = delete;
    Name& operator=(Name&& name) = delete;

    const std::string& get() const { return m_name; }
};

int main()
{
    Name joe{ "Joe" };

    joe = Name{ "Bob" }; // 临时对象 -> 命中已删除的移动赋值

    std::cout << joe.get() << '\n';

    return 0;
}
