// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：std::vector<int> 上同样的"直接初始化 vs 花括号初始化"
//           区分：vector<int> array(5) 得到 5 个值初始化为 0 的元素；
//           vector<int> array{ 5 } 得到 1 个值为 5 的元素。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   {} size: 5
//   [0]: 0
//   {} size: 1
//   [0]: 5
// 备注：本节代码为按原文描述重建（原 Example 9）。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> array(5); // Calls std::vector::vector(count, value)
                               // -> 5 value-initialized (zero) elements
    std::cout << "{} size: " << array.size() << '\n';
    std::cout << "[0]: " << array[0] << '\n';

    std::vector<int> array2{ 5 }; // Calls std::vector::vector(std::initializer_list)
                                  // -> 1 element with value 5
    std::cout << "{} size: " << array2.size() << '\n';
    std::cout << "[0]: " << array2[0] << '\n';

    return 0;
}
