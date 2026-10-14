// ============================================================
// 来源小节：14.2 Introduction to classes
// 示例说明：测验第 1 题——给出 minMax 结构体，问它的类不变量是什么。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
// 备注：本节代码为按原文描述忠实重建。原文的"解答"只有文字说明（不变量
//       为 min <= max；一旦 min > max，使用该结构体的代码就可能出错），
//       并没有给出解答代码；此处保留题目中的结构体定义以便编译验证。
// ============================================================
struct minMax
{
    int min; // holds the minimum value seen so far
    int max; // holds the maximum value seen so far
};

int main()
{
    [[maybe_unused]] minMax m{};
    return 0;
}

// 解答要点：不变量是 min <= max。若某个 minMax 对象的 min 大于 max，
// 依赖该不变量工作的代码就可能表现异常。
