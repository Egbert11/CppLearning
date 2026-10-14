// 来源小节：2.7 Forward declarations and definitions
// 示例说明：违反 ODR 第 1 条 —— 同一个文件中重复定义 add(int, int) 与变量 x。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: redefinition of 'int add(int, int)'
//           error: redefinition of 'int x'
//           （Visual Studio: C2084 function already has a body / C2086 redefinition）
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example9-error.cpp -o a   （会报错，属预期）

int add(int x, int y)
{
     return x + y;
}

int add(int x, int y) // violation of ODR, we've already defined function add(int, int)
{
     return x + y;
}

int main()
{
    int x{};
    int x{ 5 }; // violation of ODR, we've already defined x

    return 0;
}
