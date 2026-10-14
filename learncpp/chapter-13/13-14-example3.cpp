// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：字面量后缀 f、u 会改变 CTAD 推导出的类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <utility> // for std::pair
#include <typeinfo> // for typeid (演示推导结果)

int main()
{
    // --- 原文示例片段（原 Example 3）---
    std::pair p1 { 3.4f, 5.6f }; // deduced to pair<float, float>
    std::pair p2 { 1u, 2u };     // deduced to pair<unsigned int, unsigned int>

    std::cout << "p1.first is " << p1.first << " (type: "
              << (typeid(p1.first) == typeid(float) ? "float" : "other") << ")\n";
    std::cout << "p2.first is " << p2.first << " (type: "
              << (typeid(p2.first) == typeid(unsigned int) ? "unsigned int" : "other") << ")\n";

    return 0;
}

// 预期输出：
// p1.first is 3.4 (type: float)
// p2.first is 1 (type: unsigned int)
