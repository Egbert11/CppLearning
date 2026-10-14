// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：无法推导的情形——无初始化式、空初始化式、用 void 函数的结果初始化，
//           三者都会编译失败。
//           编译器报错形如：
//             error: declaration of 'auto a' has no initializer
//             error: cannot deduce 'auto' type from empty braces
//             error: variable 'c' with deduced type 'auto' cannot be used before it is defined
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example5-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

void foo()
{
}

int main()
{
    // --- 原文示例片段 ---
    auto a;        // 错误：没有初始化式
    auto b{ };     // 错误：空花括号，无法推导
    auto c{ foo() }; // 错误：foo() 返回 void，无法用不完整类型推导
    // --- 原文示例片段结束 ---

    (void)a; (void)b; (void)c;
    return 0;
}
