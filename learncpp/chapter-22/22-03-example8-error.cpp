// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：Name 允许拷贝（= default）、但删除移动。getJoe() 按值返回
//           一个局部对象；重载决议会优先选择"已删除的移动构造"，
//           即使拷贝构造可用也仍报错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期错误：编译失败（勿修复）。典型报错：
//   error: use of deleted function 'Name::Name(Name&&)'
//   （原文描述为 "error: Move constructor was deleted"）
// 备注：本节代码为按原文描述重建（原 Example 8）。
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

    Name(const Name& name) = default;
    Name& operator=(const Name& name) = default;
    Name(Name&& name) = delete;
    Name& operator=(Name&& name) = delete;

    const std::string& get() const { return m_name; }
};

Name getJoe()
{
    Name joe{ "Joe" };
    return joe; // 返回局部对象 -> 优先选择已删除的移动构造 -> 报错
}

int main()
{
    Name n{ getJoe() };
    std::cout << n.get() << '\n';

    return 0;
}
