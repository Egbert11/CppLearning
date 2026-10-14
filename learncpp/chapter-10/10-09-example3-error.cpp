// 来源小节：10.9 Type deduction for functions
// 示例说明：auto 返回类型下，两条 return 语句返回不同类型（int 与 double），
//           违反一致性规则，编译失败。
//           编译器报错形如：error: inconsistent deduction for return type 'auto':
//             'int' and then 'double'
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example3-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

// --- 原文示例片段 ---
auto someFcn(bool b)
{
    if (b)
        return 5; // return type int
    else
        return 6.7; // return type double
}
// --- 原文示例片段结束 ---

int main()
{
    someFcn(true);
    return 0;
}
