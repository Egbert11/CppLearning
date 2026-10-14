// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：把 1000 个元素的数组传给形如 int arr[1000] 的参数（原 Example 2）。
//           形参其实被当作指针，不会真正拷贝整个数组。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：5
// ============================================================
#include <iostream>

void printElementZero(int arr[1000])
{
    std::cout << arr[0]; // print the value of the first element
}

int main()
{
    int x[1000] { 5 };   // define an array with 1000 elements, x[0] is initialized to 5
    printElementZero(x);

    return 0;
}
