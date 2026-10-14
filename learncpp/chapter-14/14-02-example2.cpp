// ============================================================
// 来源小节：14.2 Introduction to classes
// 示例说明：Pair 的两个成员可以各自独立地赋成任意值，因此它**没有**
//           类不变量（class invariant）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
// 备注：本节代码为按原文描述忠实重建。原文仅给出类型定义，此处补一个
//       空的 main() 使其可独立编译。
// ============================================================
struct Pair
{
    int first {};
    int second {};
};

int main()
{
    [[maybe_unused]] Pair p{};
    return 0;
}
