// ============================================================
// 来源小节：23.3 Aggregation
// 示例说明：std::reference_wrapper 可在容器中"存引用"：
//           用 std::vector<std::reference_wrapper<std::string>>
//           保存字符串引用，修改对原对象可见。
// 原文链接：https://www.learncpp.com/cpp-tutorial/aggregation/
// 预期输出：
//   Tom Beam
//   Berta Beam
//   Jim Beam
// 备注：本节代码为按原文描述重建（原 Example 6）。
// ============================================================
#include <functional> // std::reference_wrapper
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string tom{ "Tom" };
    std::string berta{ "Berta" };
    std::string jim{ "Jim" };

    std::vector<std::reference_wrapper<std::string>> names{ tom, berta }; // these strings are stored by reference, not value

    names.emplace_back(jim);

    // Modifying the values of the strings via the references
    for (auto& name : names)
        name.get() += " Beam";

    for (const auto& name : names)
        std::cout << name.get() << '\n';

    return 0;
}
