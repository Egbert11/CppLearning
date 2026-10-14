// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：把遍历逻辑放进函数——只传 begin/end 指针，不传数组本身（原 Example 9）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出：9 7 5 3 1
// ============================================================
#include <iostream>
#include <iterator> // for std::size

void printArray(const int* begin, const int* end)
{
    for (; begin != end; ++begin) // iterate from begin up to (but excluding) end
    {
        std::cout << *begin << ' '; // dereference our pointer to access the element
    }
}

int main()
{
    constexpr int arr[]{ 9, 7, 5, 3, 1 };

    printArray(arr, arr + std::size(arr)); // 并未传入 arr 本身，只传了 begin/end

    return 0;
}
