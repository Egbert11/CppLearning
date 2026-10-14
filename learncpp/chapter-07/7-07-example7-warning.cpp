// 来源小节：7.7 External linkage and variable forward declarations
// 示例说明：带初始化式的 `extern` 会触发编译器警告——"extern by default" 与 "explicitly extern"
//           语义等价，但显式 extern 版本会被提示"初始化了却声明为 extern"，暗示这更像定义。
//           （对应原文 Example 7）
// 原文链接：https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
//
// ※※※ 预期产生警告（但可编译）※※※
// 预期警告（GCC）：warning: 'g_x2' initialized and declared 'extern'
// 本文件用于演示该警告，属正常现象，勿"修复"。

int g_x1 { 1 };        // extern by default
extern int g_x2 { 1 }; // explicitly extern (GCC warns: initialized and declared 'extern')

int main()
{
    return 0;
}
