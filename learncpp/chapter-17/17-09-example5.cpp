// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：下标与指针算术的等价关系（原 Example 5）。
//           地址输出依平台而定，元素值输出固定为 3 2 1。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出（值部分）：
//   3 2 1
//   3 2 1
// ============================================================
#include <iostream>

int main()
{
    int arr[]{ 3, 2, 1 };

    // 取每个元素的地址
    std::cout << &arr[0] << ' ' << &arr[1] << ' ' << &arr[2] << '\n';

    // 用下标取值
    std::cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';

    // 下标只是指针算术的简写：arr[0] == *(arr + 0)
    std::cout << *(arr + 0) << ' ' << *(arr + 1) << ' ' << *(arr + 2) << '\n';

    // 等价的解引用写法
    std::cout << *arr << ' ' << *(arr + 1) << ' ' << *(arr + 2) << '\n';

    return 0;
}
