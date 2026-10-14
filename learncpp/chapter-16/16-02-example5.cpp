// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：对比各种初始化形式如何选择构造函数：
//   v2(10) 直接初始化 -> 单参长度构造函数，10 个值初始化的 0
//   v3{ 10 } / v4 = { 10 } / v5({ 10 }) -> 列表构造函数，1 个值为 10 的元素
//   v6{} / v7 = {} -> 默认构造函数，空 vector
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：v2 size 10 / v3 size 1 ... 等（见程序输出）。
// 备注：本节代码为按原文描述重建。
//       原 Example 8 中的 `std::vector<int> v1 = 10;`（拷贝初始化）编译失败，
//       见 16-02-example6-error.cpp。
//       原 Example 5 的 `{ 0, 0, ..., 0 }` 是"用列表构造长度 10"的笨办法，
//       原 Example 7 `{ 10 }` 是提出"这到底做什么"的提问。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    // std::vector<int> v1 = 10;     // copy init: compilation error (see 16-02-example6-error.cpp)
    std::vector<int> v2(10);         // direct init: single-argument constructor -> 10 value-initialized elements
    std::vector<int> v3{ 10 };       // list init: list constructor -> 1 element with value 10
    std::vector<int> v4 = { 10 };    // copy list init: list constructor -> 1 element with value 10
    std::vector<int> v5({ 10 });     // same as v4 (copy list init)
    std::vector<int> v6 {};          // default constructor: empty vector
    std::vector<int> v7 = {};        // default constructor: empty vector

    std::cout << "v2 size: " << v2.size() << ", v2[0]: " << v2[0] << '\n';
    std::cout << "v3 size: " << v3.size() << ", v3[0]: " << v3[0] << '\n';
    std::cout << "v4 size: " << v4.size() << ", v4[0]: " << v4[0] << '\n';
    std::cout << "v5 size: " << v5.size() << ", v5[0]: " << v5[0] << '\n';
    std::cout << "v6 size: " << v6.size() << '\n';
    std::cout << "v7 size: " << v7.size() << '\n';

    return 0;
}
