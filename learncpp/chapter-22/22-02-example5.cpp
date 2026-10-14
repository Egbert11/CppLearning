// ============================================================
// 来源小节：22.2 R-value references
// 示例说明：具名的右值引用变量在被当作表达式使用时是"左值"，
//           因此 fun(ref) 匹配 const 左值引用版本，而不是右值引用版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rvalue-references/
// 预期输出：
//   l-value reference to const: 5
// 备注：本节代码为按原文描述重建（原 Example 5）。
//       若要真正走右值分支，需写成 fun(std::move(ref))。
// ============================================================
#include <iostream>
#include <utility> // for std::move

void fun(const int& lref)
{
    std::cout << "l-value reference to const: " << lref << '\n';
}

void fun(int&& rref)
{
    std::cout << "r-value reference: " << rref << '\n';
}

int main()
{
    int&& ref{ 5 };
    fun(ref);              // ref 是具名的、类型为 int&& 的变量 -> 作为表达式是左值
    fun(std::move(ref));   // 显式转换为右值才会走右值引用重载

    return 0;
}
