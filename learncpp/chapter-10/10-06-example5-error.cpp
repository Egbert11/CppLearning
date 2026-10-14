// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：无效转换——编译器不知道怎么把字符串字面量（const char*）转成 int，
//           因此编译失败。
//           编译器报错形如：error: invalid 'static_cast' from type 'const char*' to type 'int'
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example5-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    // --- 原文示例片段 ---
    int x{ static_cast<int>("Hello") }; // invalid: will produce compilation error
    // --- 原文示例片段结束 ---

    (void)x;
    return 0;
}
