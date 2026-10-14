// ============================================================
// 来源小节：14.2 Introduction to classes
// 示例说明：更复杂的不变量——两个成员必须彼此关联：firstInitial 应始终
//           等于 name 的首字符。struct 无法强制这种约束。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
// 备注：本节代码为按原文描述忠实重建。原文仅给出类型定义，此处补一个
//       空的 main() 使其可独立编译。
// ============================================================
#include <string>

struct Employee
{
    std::string name { };
    char firstInitial { }; // should always hold first character of `name` (or `0`)
};

int main()
{
    [[maybe_unused]] Employee e{};
    return 0;
}
