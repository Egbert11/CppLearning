// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：Quiz #2 解答——指出下面程序中的三处错误：(a) 数组长度必须是编译期
//           常量，而 length 是普通 int；(b) arr[length] 越界，是未定义行为；
//           (c) 元素是 const int，不能对 arr[0] 赋值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期错误：编译错误——(a) 'length' is not a constant expression；
//           (c) assignment of read-only location 'arr[0]'。
//           (b) 是运行期的越界访问（未定义行为），不会报编译错误。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <iostream>

int main()
{
    int length{ 5 };
    const int arr[length] { 9, 7, 5, 3, 1 }; // error (a): length is not a constant expression
    std::cout << arr[length];                // error (b): out-of-bounds index -> undefined behavior
    arr[0] = 4;                              // error (c): arr elements are const int

    return 0;
}
