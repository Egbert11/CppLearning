// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：相对寻址——ptr[n] 表示"从 ptr 当前位置往后第 n 个对象"，而非绝对下标（原 Example 6）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出：
//   8 8
//   7 7
//   6 6
//   5 5
// ============================================================
#include <iostream>

int main()
{
    int arr[]{ 9, 8, 7, 6, 5 };
    int* ptr{ &arr[1] }; // set ptr to point at element 1 (value 8)

    std::cout << *ptr << ' ' << ptr[0] << '\n';       // element 1
    std::cout << *(ptr + 1) << ' ' << ptr[1] << '\n'; // element 2

    ptr = &arr[3]; // set ptr to point at element 3 (value 6)
    std::cout << *ptr << ' ' << ptr[0] << '\n';       // element 3
    std::cout << *(ptr + 1) << ' ' << ptr[1] << '\n'; // element 4

    return 0;
}
