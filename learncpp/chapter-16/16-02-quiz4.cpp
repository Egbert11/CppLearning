// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：Quiz #4 解答——用长度构造函数建 3 个 int 的 vector，
//           读入 3 个整数并输出它们的和与积。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出（输入 3 4 5 时）：
//   Enter 3 integers: 3 4 5
//   The sum is: 12
//   The product is: 60
// 备注：本节代码为按原文描述重建（需要标准输入）。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr(3); // vector of length 3

    std::cout << "Enter 3 integers: ";
    std::cin >> arr[0] >> arr[1] >> arr[2];

    std::cout << "The sum is: " << arr[0] + arr[1] + arr[2] << '\n';
    std::cout << "The product is: " << arr[0] * arr[1] * arr[2] << '\n';

    return 0;
}
