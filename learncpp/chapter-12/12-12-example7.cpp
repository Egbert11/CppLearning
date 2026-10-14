// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：返回对**非 const** static 局部的引用，且被两个引用同时引用。
//           id1 与 id2 都绑定到同一个 s_x，因此打印 “22” 而非 “12”。
//           这正是“不要返回非 const 局部 static 的引用”的原因之一。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// 预期输出：22
// 备注：本节代码为按原文描述忠实重建（原 Example 7）。
// ============================================================
#include <iostream>

int& getNextId()
{
    static int s_x{ 0 }; // note: a non-const static local variable
    ++s_x; // generate the next id
    return s_x; // and return a reference to it
}

int main()
{
    const int& id1 { getNextId() }; // id1 is a reference
    const int& id2 { getNextId() }; // id2 is a reference

    std::cout << id1 << id2 << '\n'; // prints 22 (both references refer to the same object)

    return 0;
}
