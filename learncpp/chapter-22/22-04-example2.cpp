// ============================================================
// 来源小节：22.4 std::move
// 示例说明：移动版交换函数 mySwapMove()——用 std::move 把 a、b 转成
//           右值，从而调用移动构造与移动赋值，三次移动取代三次拷贝。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdmove/
// 预期输出（与拷贝版相同）：
//   x: abc
//   y: de
//   x: de
//   y: abc
// 备注：本节代码为按原文描述重建（原 Example 2）。
// ============================================================
#include <iostream>
#include <string>
#include <utility> // for std::move

template <typename T>
void mySwapMove(T& a, T& b)
{
    T tmp{ std::move(a) }; // invokes move constructor
    a = std::move(b);      // invokes move assignment
    b = std::move(tmp);    // invokes move assignment
}

int main()
{
    std::string x{ "abc" };
    std::string y{ "de" };

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    mySwapMove(x, y);

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    return 0;
}
