// ============================================================
// 来源小节：23.3 Aggregation
// 示例说明：std::reference_wrapper 的 const 版本——
//           std::vector<std::reference_wrapper<const std::string>>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/aggregation/
// 预期输出：
//   Tom
//   Berta
//   Jim Beam
// 备注：本节代码为按原文描述重建（原 Example 7，仅给出声明）。
//       这里让它可运行：通过 const 引用观察被修改的原字符串。
// ============================================================
#include <functional> // std::reference_wrapper
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string tom{ "Tom" };
    std::string berta{ "Berta" };
    std::string jim{ "Jim Beam" };

    // const 引用：只能读取，不能通过该引用修改
    std::vector<std::reference_wrapper<const std::string>> names{ tom, berta };
    names.emplace_back(jim);

    for (const auto& name : names)
        std::cout << name.get() << '\n';

    return 0;
}
