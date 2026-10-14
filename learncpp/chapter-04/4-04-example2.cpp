// 来源小节：4.4 Signed integers
// 示例说明：可选的 signed 关键字写法 —— 合法但冗余，因为整数默认就是有符号的，应避免使用。
//           这是原文的示例片段，本身不输出任何内容；下方用 (void) 抑制 -Wall 的未使用变量警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/signed-integers/
//
// 编译：g++ -std=c++20 -Wall 4-04-example2.cpp -o a

int main()
{
    // --- 原文示例片段 ---
    signed short ss;
    signed int si;
    signed long sl;
    signed long long sll;
    // --- 原文示例片段结束 ---

    // 【非原文】仅为让 -Wall 下无“未使用变量”警告而添加：
    (void)ss;
    (void)si;
    (void)sl;
    (void)sll;

    return 0;
}
