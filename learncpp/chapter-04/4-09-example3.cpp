// 来源小节：4.9 Boolean values
// 示例说明：使用逻辑非运算符 !。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/

int main()
{
    // --- 原文示例片段 ---
    bool b1 { !true };  // b1 will be initialized with the value false
    bool b2 { !false }; // b2 will be initialized with the value true
    // --- 原文示例片段 ---

    (void)b1; (void)b2; // 仅为消除 unused 警告
    return 0;
}
