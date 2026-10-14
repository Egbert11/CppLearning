// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：把只有 7 个元素的数组传给形如 int arr[1000] 的参数，竟然也能编译运行
//           （因为数组名退化为指针，长度信息被丢弃）（原 Example 3）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：5
// ============================================================
#include <iostream>

void printElementZero(int arr[1000]) // doesn't make a copy
{
    std::cout << arr[0]; // print the value of the first element
}

int main()
{
    int x[7] { 5 };      // define an array with 7 elements
    printElementZero(x); // somehow works!

    return 0;
}
