// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：声明一个 std::array 与一个 std::vector 的对比——std::array 需要
//           两个模板实参（元素类型 int、长度 5），std::vector 则在运行时用
//           长度参数构造。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：（无输出，仅演示声明）
// 备注：本节代码为按原文描述重建；变量未使用故加 [[maybe_unused]] 以避免警告。
// ============================================================
#include <array>  // for std::array
#include <vector> // for std::vector

int main()
{
    [[maybe_unused]] std::array<int, 5> a {}; // a std::array of 5 ints

    [[maybe_unused]] std::vector<int> b(5);   // a std::vector of 5 ints

    return 0;
}
