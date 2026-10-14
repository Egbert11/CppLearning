// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：从“指向 const 的 const 指针”推导，涵盖两种 const 的各种组合；
//           其中把 const 施加两次（const auto const）是非法的，会编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// !! -error：预期编译失败，请勿修复。
//    预期错误：duplicate 'const'（ptr7 一行重复了 const）。
// 备注：本节代码为按原文清单忠实重建（原 Example 16）。
// ============================================================
#include <string>

int main()
{
    // --- 原文示例片段 ---
    std::string s{};
    const std::string* const ptr { &s };

    auto ptr1{ ptr };  // const std::string*
    auto* ptr2{ ptr }; // const std::string*

    auto const ptr3{ ptr };  // const std::string* const
    const auto ptr4{ ptr };  // const std::string* const

    auto* const ptr5{ ptr }; // const std::string* const
    const auto* ptr6{ ptr }; // const std::string*

    const auto const ptr7{ ptr };  // error: const qualifer can not be applied twice
    const auto* const ptr8{ ptr }; // const std::string* const
    // --- 原文示例片段结束 ---

    return static_cast<int>(ptr1->size() + ptr2->size() + ptr3->size() + ptr4->size()
                          + ptr5->size() + ptr6->size() + ptr8->size());
}
