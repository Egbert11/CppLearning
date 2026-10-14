// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：成员按**声明顺序**初始化——m_bad1 与 m_bad2 在 m_data 之前声明，
//           却用 m_data / fcn()（内部读 m_data）去初始化它们，此时 m_data
//           尚未初始化，构成未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。可编译，但含有未定义行为；实际数值
//       依实现而定，请勿据此推断具体输出。
//       遵守规则：不要在默认成员初始化器里使用其它成员。
// ============================================================
struct Bad
{
    int m_bad1 { m_data }; // undefined behavior: m_data not initialized yet
    int m_bad2 { fcn() };  // undefined behavior: fcn() uses m_data (not initialized yet)
    int m_data { 5 };
    int fcn() { return m_data; }
};

int main()
{
    [[maybe_unused]] Bad b{};
    return 0;
}
