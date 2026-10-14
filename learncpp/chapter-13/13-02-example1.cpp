// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：用"魔法数字"（magic number）表示颜色——0 表示红、1 表示绿、
//           2 表示蓝。可以工作，但不直观，读者需要靠注释才知道数字含义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================

int main()
{
    // 0 = red, 1 = green, 2 = blue
    [[maybe_unused]] int appleColor { 0 }; // Our apple is red
    [[maybe_unused]] int shirtColor { 1 }; // Our shirts are green
    [[maybe_unused]] int cupColor { 2 };   // Our cup is blue

    return 0;
}
