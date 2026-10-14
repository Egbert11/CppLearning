// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：std::to_array（C++20）通过函数模板实参推导，可只给类型或不给
//           任何模板实参；也可用它在元素类型没有字面量后缀（如 short）时
//           明确元素类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：2
//           915
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    // Specify the type and size
    constexpr auto myArray1 { std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) };
    // Specify the type only
    constexpr auto myArray2 { std::to_array<int>({ 9, 7, 5, 3, 1 }) };
    // Deduce the type and size
    constexpr auto myArray3 { std::to_array({ 9, 7, 5, 3, 1 }) };

    // Useful when the element type has no literal suffix (short has none)
    constexpr auto shortArray { std::to_array<short>({ 9, 7, 5, 3, 1 }) };
    std::cout << sizeof(shortArray[0]) << '\n'; // 2 on typical platforms

    std::cout << myArray1[0] << myArray2[4] << myArray3[2] << '\n';

    return 0;
}
