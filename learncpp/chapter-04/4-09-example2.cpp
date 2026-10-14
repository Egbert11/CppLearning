// 来源小节：4.9 Boolean values
// 示例说明：布尔变量的初始化、赋值与默认初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/

int main()
{
    // --- 原文示例片段 ---
    bool b1 { true };
    bool b2 { false };
    b1 = false;
    bool b3 {}; // default initialize to false
    // --- 原文示例片段 ---

    (void)b1; (void)b2; (void)b3; // 仅为消除 unused 警告
    return 0;
}
