// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：（可选内容）constexpr 引用只能绑定具有静态存储期的对象
//           （全局或静态局部），因为其内存地址在编译期已知；不能绑定
//           非静态局部变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// !! -error：预期编译失败，勿修复。
//   预期错误：ref3 绑定到非静态对象 x，binding reference of type ... to
//             a non-static object is not a constant expression。
// 备注：本节代码为按原文描述忠实重建（原 Example 9）。
// ============================================================
int g_x { 5 };

int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] constexpr int& ref1 { g_x }; // ok, can bind to global

    static int s_x { 6 };
    [[maybe_unused]] constexpr int& ref2 { s_x }; // ok, can bind to static local

    int x { 6 };
    [[maybe_unused]] constexpr int& ref3 { x }; // compile error: can't bind to non-static object
    // --- 原文示例片段结束 ---

    return 0;
}
