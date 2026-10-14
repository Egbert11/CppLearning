// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：不带初始化器的元素被默认初始化（通常是不确定值）；应当用空花括号
//           {} 做值初始化，使元素被清零。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：0
// 备注：本节代码为按原文描述重建。arr1 的元素值未定义，请勿读取。
// ============================================================
#include <iostream>

int main()
{
    [[maybe_unused]] int arr1[5];  // elements are default initialized (uninitialized!)
    int arr2[5] {};                // elements are value initialized (zero initialized) (preferred)

    std::cout << arr2[0] << '\n';

    return 0;
}
