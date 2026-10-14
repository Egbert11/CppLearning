// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：std::size() 对数组可用，但对退化后的指针无法编译（原 Example 10）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期错误：在 printArrayLength 中 std::size(arr) 无法作用于指针 arr，
//           形成编译错误（no matching function / 无法推断 N）。请勿"修复"。
// 说明：文件包含 -error 后缀表示预期编译失败，保留原样以展示该教学点。
// ============================================================
#include <iostream>

int printArrayLength(int arr[])
{
    std::cout << std::size(arr) << '\n'; // compile error: std::size() won't work on a pointer
}

int main()
{
    int arr[]{ 3, 2, 1 };

    std::cout << std::size(arr) << '\n'; // prints 3

    printArrayLength(arr);

    return 0;
}
