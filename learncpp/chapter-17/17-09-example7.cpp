// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：负下标——ptr[-1] 等价于 *(ptr-1)，返回前一个对象（原 Example 7）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出：
//   6 6
//   7 7
// ============================================================
#include <iostream>

int main()
{
    int arr[]{ 9, 8, 7, 6, 5 };
    int* ptr{ &arr[3] }; // set ptr to point at element 3 (value 6)

    std::cout << *ptr << ' ' << ptr[0] << '\n';       // element 3
    std::cout << *(ptr - 1) << ' ' << ptr[-1] << '\n'; // element 2

    return 0;
}
