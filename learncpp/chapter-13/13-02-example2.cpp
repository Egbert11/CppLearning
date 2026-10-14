// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：改用命名的符号常量（symbolic constant）表示颜色，读起来更清楚；
//           但没有任何机制强制变量只使用这几个值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
constexpr int red { 0 };
constexpr int green { 1 };
constexpr int blue { 2 };

int main()
{
    [[maybe_unused]] int appleColor { red };   // Our apple is red (represented as 0)
    [[maybe_unused]] int shirtColor { green }; // Our shirts are green (represented as 1)
    [[maybe_unused]] int cupColor { blue };    // Our cup is blue (represented as 2)

    return 0;
}
