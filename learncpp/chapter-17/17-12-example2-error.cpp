// ============================================================
// 来源小节：17.12 Multidimensional C-style Arrays
// 示例说明：非法地同时省略两个维度（原 Example 11 的反例）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays/
// 预期错误：只能省略最左边那一维的长度；这里两维都省略，编译失败，例如
//           "declaration of 'array' as multidimensional array must have bounds for all dimensions except the first"。
//           此处用 -error 后缀表示预期编译失败，请勿"修复"。
// ============================================================
#include <iostream>

int main()
{
    int array[][]
    {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 }
    };

    std::cout << array[1][2] << '\n';

    return 0;
}
