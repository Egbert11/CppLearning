// ============================================================
// 来源小节：22.4 std::move
// 示例说明：往 vector<string> 里填充——左值 str 走 push_back 的左值重载
//           （拷贝）；std::move(str) 走右值重载（移动）。之后 str 处于
//           "有效但未指定"状态（作者机器上为空，但这不是标准保证）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdmove/
// 预期输出（作者机器）：
//   Copying str
//   str: Knock
//   vector: Knock
//
//   Moving str
//   str:
//   vector: Knock Knock
// 备注：本节代码为按原文描述重建（原 Example 3）。
//       最后一行 str 的内容依实现而定（可能为空，也可能保留原值）。
// ============================================================
#include <iostream>
#include <string>
#include <utility> // for std::move
#include <vector>

int main()
{
    std::vector<std::string> v;

    std::string str{ "Knock" };

    std::cout << "Copying str\n";
    v.push_back(str); // calls l-value version of push_back, which copies str into the array element

    std::cout << "str: " << str << '\n';
    std::cout << "vector: " << v[0] << '\n';

    std::cout << "\nMoving str\n";

    v.push_back(std::move(str)); // calls r-value version of push_back, which moves str into the array element

    std::cout << "str: " << str << '\n'; // 结果是不确定的（valid but unspecified）
    std::cout << "vector: " << v[0] << ' ' << v[1] << '\n';

    return 0;
}
