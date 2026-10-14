// ============================================================
// 来源小节：17.x Chapter 17 summary and quiz（测验 1(b)）
// 示例说明：一段有 bug 的代码——C 风格数组形参退化为指针，范围 for 无法求出长度。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
// 预期错误：array 参数实际是 int*，对指针做范围 for 会因找不到 begin()/end()
//           而编译失败（"no matching function for call to 'begin(int*&)'" 之类）。
//           此处用 -error 后缀表示预期编译失败。
// 修法：改用 std::array（按长度做模板参数）或 std::vector 等能携带长度的类型。
// ============================================================
#include <iostream>

void printArray(int array[])
{
    // compile error: array has decayed into a pointer, so range-based for can't determine its length
    for (auto e : array)
        std::cout << e << ' ';
}

int main()
{
    int arr[]{ 0, 1, 2, 3 };
    printArray(arr);

    return 0;
}
