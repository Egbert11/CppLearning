// ============================================================
// 来源小节：22.4 std::move
// 示例说明：拷贝版交换函数 mySwapCopy()——形参是左值引用，因此
//           T tmp{ a }、a = b、b = tmp 全部走拷贝路径（共三次拷贝）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdmove/
// 预期输出：
//   x: abc
//   y: de
//   x: de
//   y: abc
// 备注：本节代码为按原文描述重建（原 Example 1）。
// ============================================================
#include <iostream>
#include <string>

template <typename T>
void mySwapCopy(T& a, T& b)
{
    T tmp{ a }; // invokes copy constructor
    a = b;      // invokes copy assignment
    b = tmp;    // invokes copy assignment
}

int main()
{
    std::string x{ "abc" };
    std::string y{ "de" };

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    mySwapCopy(x, y);

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    return 0;
}
