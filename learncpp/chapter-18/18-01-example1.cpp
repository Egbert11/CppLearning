// ============================================================
// 来源小节：18.1 Sorting an array using selection sort
// 示例说明：用 std::swap() 交换两个整型变量的值，演示排序中反复用到的“交换”操作。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/
// 预期输出：
//   Before swap: x = 2, y = 4
//   After swap:  x = 4, y = 2
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <utility> // for std::swap

int main()
{
    int x{ 2 };
    int y{ 4 };

    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y); // swap the values of x and y
    std::cout << "After swap:  x = " << x << ", y = " << y << '\n';

    return 0;
}
