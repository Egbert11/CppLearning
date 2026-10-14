// 来源小节：4.5 Unsigned integers, and why to avoid them
// 示例说明：声明四种无符号整数类型 —— unsigned 关键字按惯例放在类型前。
//           这是原文的示例片段，本身不输出任何内容；下方用 (void) 抑制 -Wall 的未使用变量警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
//
// 编译：g++ -std=c++20 -Wall 4-05-example1.cpp -o a

int main()
{
    // --- 原文示例片段 ---
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    unsigned long long ull;
    // --- 原文示例片段结束 ---

    // 【非原文】仅为让 -Wall 下无“未使用变量”警告而添加：
    (void)us;
    (void)ui;
    (void)ul;
    (void)ull;

    return 0;
}
