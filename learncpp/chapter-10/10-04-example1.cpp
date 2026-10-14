// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：函数调用中存在窄化转换（double 实参传给 int 形参）时，隐式版本会产生
//           警告；用 static_cast 显式表达"这是有意的窄化"，警告消失。
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example1.cpp -o a
//
// 本节代码为按原文描述重建。

void someFcn(int i)
{
    (void)i;
}

int main()
{
    // --- 原文示例片段 ---
    double d{ 5.0 };

    someFcn(d); // bad: implicit narrowing conversion will generate compiler warning

    // good: we're explicitly telling the compiler this narrowing conversion is intentional
    someFcn(static_cast<int>(d)); // no warning generated
    // --- 原文示例片段结束 ---

    return 0;
}
