// 来源小节：4.11 Chars
// 示例说明：不推荐的字符初始化——用整数 97（虽然可行，但可读性差）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/

int main()
{
    // --- 原文示例片段 ---
    char ch1{ 97 }; // initialize with integer 97 ('a') (not preferred)
    // --- 原文示例片段 ---

    (void)ch1;
    return 0;
}
