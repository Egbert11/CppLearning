// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：指针的指针（双星号）的声明与两次解引用取值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期输出：
//   5
//   5
// 备注：本节代码为按原文描述重建（合并原文 Example 1/2/3）。
// ============================================================
#include <iostream>

int main()
{
    int value { 5 };

    int* ptr; // pointer to an int, one asterisk
    ptr = &value;

    int** ptrptr; // pointer to a pointer to an int, two asterisks
    ptrptr = &ptr;

    std::cout << *ptr << '\n'; // Dereference pointer to int to get int value
    std::cout << **ptrptr << '\n'; // dereference to get pointer to int, dereference again to get int value

    // 更深的间接层级也是合法的（见原文末尾；此处仅作声明演示）
    int*** ptrx3;    // triple pointer
    int**** ptrx4;   // quadruple pointer
    (void)ptrx3;
    (void)ptrx4;

    return 0;
}
