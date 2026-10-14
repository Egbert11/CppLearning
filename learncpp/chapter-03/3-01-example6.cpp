// 来源小节：3.1 Syntax and semantic errors
// 示例说明：运行期语义错误——return 语句之后的代码永远不会执行（不可达代码）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
//
// 说明：本节示例为按原文描述重建。该程序含原文故意保留的 bug（这正是被调试的对象）。
//
// 预期行为：main() 在 return 0; 处就返回了，后面的 std::cout 永远不会执行，
//           因此屏幕上没有任何输出（部分编译器会对不可达代码给出警告）。

#include <iostream>

int main()
{
    return 0; // the function returns here

    std::cout << "Hello, world!\n"; // unreachable code: this statement never executes
}
