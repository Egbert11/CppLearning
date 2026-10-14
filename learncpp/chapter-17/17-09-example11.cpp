// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：范围 for 循环的"展开"等价形式，展示其内部就是 begin/end 指针循环（原 Example 11）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出：9 7 5 3 1
// 备注：__begin/__end 这类含双下划线的名字实际为保留标识符，此处仅为演示编译器展开后的形态。
// ============================================================
#include <iostream>
#include <iterator> // for std::size

int main()
{
    constexpr int arr[]{ 9, 7, 5, 3, 1 };

    auto __begin = arr;
    auto __end = arr + std::size(arr);

    for ( ; __begin != __end; ++__begin)
    {
        auto e = *__begin; // dereference the pointer and assign to loop variable

        std::cout << e << ' ';
    }

    return 0;
}
