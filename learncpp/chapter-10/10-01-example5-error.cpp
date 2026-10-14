// 来源小节：10.1 Implicit type conversion
// 示例说明：花括号初始化禁止会丢失数据的窄化转换 —— int x { 3.5 } 中的 3.5 是
//           double，转换为 int 会丢掉小数部分，因此编译失败。
//           编译器报错形如：error: narrowing conversion of '3.5e+0' from 'double' to 'int'
// 原文链接：https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/
//
// 编译：g++ -std=c++20 -Wall 10-01-example5-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    // --- 原文示例片段 ---
    int x{ 3.5 }; // brace-initialization disallows conversions that result in data loss
    // --- 原文示例片段结束 ---

    return 0;
}
