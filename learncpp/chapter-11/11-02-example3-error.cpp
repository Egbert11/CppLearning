// 来源小节：11.2 Function overload differentiation
// 示例说明：类型别名/typedef 不会产生新的类型，因此这三个 print() 视为同一个函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/
//
// 编译：g++ -std=c++20 -Wall 11-02-example3-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：重定义 'void print(int)'（redefinition of 'void print(int)'）。
//   Age/Height 都只是 int 的别名，与 print(int) 不是可区分的重载。
//
// 本节代码为按原文描述重建。

typedef int Height; // typedef
using Age = int; // type alias

// 只有定义（而非重复的声明）才会暴露"它们是同一个函数"这一点。
void print(int value)
{
}

void print(Age value) // not differentiated from print(int) -> redefinition
{
}

void print(Height value) // not differentiated from print(int) -> redefinition
{
}

int main()
{
    return 0;
}
