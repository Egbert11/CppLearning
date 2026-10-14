// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：非法用法 —— main() 不允许被程序显式调用，而且 main() 的返回类型必须是 int。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: 'main' cannot be used as a function   （或 'main' was not declared / 返回类型错误）
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example5-error.cpp -o a   （会报错，属预期）

void foo()
{
    main(); // Compile error: main cannot be called from within a program
}

void main() // Compile error: the return type for main() must be int, not void
{
    foo();
}
