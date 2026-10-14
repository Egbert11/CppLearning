// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：二级指针可以是空指针；以及动态分配"元素为指针"的数组。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期输出：10
// 备注：本节代码为按原文描述重建（原文 Example 5/6）。
// ============================================================
#include <iostream>

int main()
{
    int** ptrptr { nullptr }; // a pointer to a pointer may be a null pointer
    (void)ptrptr;

    // 最常见的用途：动态分配一个元素为 int* 的数组
    int** array { new int*[10] }; // allocate an array of 10 int pointers

    int value { 10 };
    array[0] = &value; // 注意：元素是"指针"，可指向外部变量

    std::cout << *array[0] << '\n';

    delete[] array; // 只释放指针数组本身（元素指向的不是动态内存）

    return 0;
}
