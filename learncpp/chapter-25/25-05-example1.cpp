// ============================================================
// 来源小节：25.5 Early binding and late binding（原 Example 1）
// 示例说明：直接调用（early binding/静态绑定）—— 调用非成员函数与普通成员函数，
//           编译器/链接器在编译期即可确定目标地址。
// 原文链接：https://www.learncpp.com/cpp-tutorial/early-binding-and-late-binding/
// 预期输出：
//   55
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

struct Foo
{
    void printValue(int value) { std::cout << value; }
};

void printValue(int value) { std::cout << value; }

int main()
{
    printValue(5);   // direct function call

    Foo foo{};
    foo.printValue(5); // direct function call

    return 0;
}
