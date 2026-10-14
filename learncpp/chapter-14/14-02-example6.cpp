// ============================================================
// 来源小节：14.2 Introduction to classes
// 示例说明：用 class 关键字定义类型的最简形式。class 的成员默认是
//           private，且习惯上数据成员加 m_ 前缀。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
// 备注：本节代码为按原文描述忠实重建。原文仅给出类型定义，此处补一个
//       空的 main() 使其可独立编译。
// ============================================================
class Employee
{
    int m_id {};
    int m_age {};
    double m_wage {};
};

int main()
{
    [[maybe_unused]] Employee e{};
    return 0;
}
