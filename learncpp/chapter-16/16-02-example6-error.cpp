// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：拷贝初始化 `std::vector<int> v1 = 10;` 无法把 10 当作长度来构造——
//           长度构造函数是 explicit 的，且 10 也不是初始化列表，故编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期错误：编译错误——无法从 int 拷贝初始化 std::vector<int>
//           （GCC 形如 "conversion from 'int' to non-scalar type ... requested"）。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <vector>

int main()
{
    std::vector<int> v1 = 10; // copy init: compilation error -- the length constructor is explicit

    return 0;
}
