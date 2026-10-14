// 来源小节：10.1 Implicit type conversion
// 示例说明：用字符串字面量 "14" 初始化 int —— 字符串字面量的类型是 const char*，
//           从 const char* 到 int 没有标准转换，因此编译失败。
//           编译器报错形如：error: invalid conversion from 'const char*' to 'int' [-fpermissive]
// 原文链接：https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/
//
// 编译：g++ -std=c++20 -Wall 10-01-example4-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    // --- 原文示例片段 ---
    int x{ "14" }; // compile error: no standard conversion from const char* to int
    // --- 原文示例片段结束 ---

    return 0;
}
