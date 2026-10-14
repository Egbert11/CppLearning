// ============================================================
// 来源小节：22.2 R-value references
// 示例说明：按引用类型重载函数——左值实参选择 const 左值引用版本，
//           右值实参选择右值引用版本（右值引用被认为匹配得更好）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rvalue-references/
// 预期输出：
//   l-value reference to const: 5
//   r-value reference: 5
// 备注：本节代码为按原文描述重建（原 Example 4）。
// ============================================================
#include <iostream>

void fun(const int& lref) // l-value arguments will select this function
{
    std::cout << "l-value reference to const: " << lref << '\n';
}

void fun(int&& rref) // r-value arguments will select this function
{
    std::cout << "r-value reference: " << rref << '\n';
}

int main()
{
    int x{ 5 };
    fun(x); // l-value argument calls l-value version of function
    fun(5); // r-value argument calls r-value version of function

    return 0;
}
