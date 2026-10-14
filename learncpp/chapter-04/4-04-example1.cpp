// 来源小节：4.4 Signed integers
// 示例说明：首选写法 —— 用简写类型名定义四种有符号整数类型，不用带 int 后缀的写法。
//           这是原文的示例片段，本身不输出任何内容；下方用 (void) 抑制 -Wall 的未使用变量警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/signed-integers/
//
// 编译：g++ -std=c++20 -Wall 4-04-example1.cpp -o a

int main()
{
    // --- 原文示例片段 ---
    short s;      // prefer "short" instead of "short int"
    int i;
    long l;       // prefer "long" instead of "long int"
    long long ll; // prefer "long long" instead of "long long int"
    // --- 原文示例片段结束 ---

    // 【非原文】仅为让 -Wall 下无“未使用变量”警告而添加：
    (void)s;
    (void)i;
    (void)l;
    (void)ll;

    return 0;
}
