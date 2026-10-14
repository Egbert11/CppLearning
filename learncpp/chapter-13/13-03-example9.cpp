// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：C++17 起，若枚举显式指定了底层类型，则允许用整数做列表（花括号）
//           初始化。本例只演示这个合法用法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。其他非法形式见 13-03-example9-error.cpp。
// ============================================================
enum Pet : int // we've specified a base
{
    cat,   // assigned 0
    dog,   // assigned 1
    pig,   // assigned 2
    whale, // assigned 3
};

int main()
{
    Pet pet1 { 2 }; // ok: can brace initialize unscoped enumeration with specified base with integer (C++17)

    (void)pet1;
    return 0;
}
