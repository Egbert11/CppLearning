// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：直接绑定 vs 间接绑定。直接把 const 引用绑定到临时值会延长其
//           生命周期（ref1 合法）；而把引用经函数“绕一圈”再返回，则不会
//           延长，ref2 悬垂，使用它是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// !! -ub：未定义行为演示，可编译（gcc 会给出警告）。
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
// ============================================================
#include <iostream>

const int& returnByConstReference(const int& ref)
{
    return ref; // returns a reference to the parameter
}

int main()
{
    // case 1: direct binding of a const reference to a temporary extends its lifetime
    const int& ref1 { 5 }; // okay: lifetime of the temporary is extended
    std::cout << ref1 << '\n';

    // case 2: indirect binding through a function does NOT extend lifetime
    const int& ref2 { returnByConstReference(5) }; // dangling reference
    std::cout << ref2 << '\n'; // undefined behavior

    return 0;
}
