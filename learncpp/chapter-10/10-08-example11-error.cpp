// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：auto 强制初始化——int x; 可能不报警告却未初始化；auto y; 因为无从推导
//           直接编译失败，从而杜绝"忘记初始化"。
//           编译器报错形如：error: declaration of 'auto y' has no initializer
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example11-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    int x; // 可能不报警告的未初始化变量
    (void)x;

    // --- 原文示例片段 ---
    auto y; // 编译错误：没有可推导的类型
    // --- 原文示例片段结束 ---

    return 0;
}
