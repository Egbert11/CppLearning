// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：证明数组会退化为 int*，且该指针保存首元素地址（原 Example 4）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：
//   true
//   true
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iomanip> // for std::boolalpha
#include <iostream>
#include <typeinfo> // for typeid

int main()
{
    int arr[5]{ 9, 7, 5, 3, 1 }; // our array has elements of type int

    // First, let's prove that arr decays into an int* pointer

    auto ptr{ arr }; // evaluation causes arr to decay, type deduction should deduce type int*
    std::cout << std::boolalpha << (typeid(ptr) == typeid(int*)) << '\n'; // Prints true if the type of ptr is int*

    // Now let's prove that the pointer holds the address of the first element of the array

    std::cout << std::boolalpha << (&arr[0] == ptr) << '\n';

    return 0;
}
