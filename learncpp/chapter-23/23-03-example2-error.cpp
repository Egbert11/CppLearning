// ============================================================
// 来源小节：23.3 Aggregation
// 示例说明：故意演示编译错误——std::vector 不能持有引用，
//           因此 std::vector<const Teacher&> 无法编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/aggregation/
// 预期错误：编译失败。本机 g++ 15.2.0 的报错为：
//   error: forming pointer to reference type 'const Teacher&'
//   （出现在 new_allocator.h / allocator.h 中）
//   不同编译器措辞不同；本题教学重点即"容器不能存引用"。
// 备注：-error 后缀 = 预期编译失败。请勿"修复"此错误。
// ============================================================
#include <vector>
#include <string>
#include <string_view>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(std::string_view name)
        : m_name{ name }
    {
    }

    std::string_view getName() const { return m_name; }
};

class Department
{
private:
    // 非法：容器元素不能是引用类型
    std::vector<const Teacher&> m_teachers{};

public:
    Department() = default;
};

int main()
{
    Department department{};
    return 0;
}
