// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：避免枚举量冲突的一招是给枚举量加前缀（如 color_red、
//           feeling_happy）。这样仍然会污染命名空间，但降低了冲突概率。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
enum Color
{
    color_red,
    color_green,
    color_blue,
};

enum Feeling
{
    feeling_happy,
    feeling_tired,
    feeling_blue,
};

int main()
{
    [[maybe_unused]] Color paint { color_blue };
    [[maybe_unused]] Feeling me { feeling_tired };

    return 0;
}
