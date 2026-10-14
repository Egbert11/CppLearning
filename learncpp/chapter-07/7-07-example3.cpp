// 来源小节：7.7 External linkage and variable forward declarations
// 示例说明：定义具有外部链接的全局变量——非 const 全局变量默认外部链接（无需 extern）；
//           const / constexpr 全局变量用 extern 可赋予外部链接（constexpr 情形"没什么用"）。
//           （对应原文 Example 3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
//
// ※ 本节示例为按原文描述重建，语义与原文一致。
//   这些变量在别的文件中被引用（见 7-07-example4/）。

int g_x { 2 }; // non-constant globals are external by default (no need to use extern)

extern const int g_y { 3 }; // const globals can be defined as extern, making them external
extern constexpr int g_z { 3 }; // constexpr globals can be defined as extern (pretty useless; see warning below)

int main()
{
    return 0;
}
