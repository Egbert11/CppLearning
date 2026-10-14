// 来源小节：11.2 Function overload differentiation
// 示例说明：按值参数上的顶层 const 会被忽略，因此这两个 print() 不是不同的重载。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/
//
// 编译：g++ -std=c++20 -Wall 11-02-example4-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：重定义 'void print(int)'（redefinition of 'void print(int)'）。
//
// 本节代码为按原文描述重建。

// 只有定义（而非重复的声明）才会暴露"它们是同一个函数"这一点。
void print(int)
{
}

void print(const int) // not differentiated from print(int) -> redefinition
{
}

int main()
{
    return 0;
}
