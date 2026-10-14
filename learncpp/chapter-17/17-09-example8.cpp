// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：用 begin/end 指针对数组进行遍历（原 Example 8）。
//           注意：指针算术必须始终停留在数组元素内或末尾后一个位置，越界即 UB。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出：9 7 5 3 1
// ============================================================
#include <iostream>
#include <iterator> // for std::size

int main()
{
    constexpr int arr[]{ 9, 7, 5, 3, 1 };

    const int* begin{ arr };               // points to element 0
    const int* end{ arr + std::size(arr) }; // points one past the last element

    for (; begin != end; ++begin) // iterate from begin up to (but excluding) end
    {
        std::cout << *begin << ' '; // dereference our pointer to access the element
    }

    return 0;
}
