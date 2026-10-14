// ============================================================
// 来源小节：25.5 Early binding and late binding（原 Example 5）
// 示例说明：通过函数指针间接调用（late binding/动态）—— 编译器在调用点无法确定
//           指针指向哪个函数，需在运行时读取地址再跳转。
// 原文链接：https://www.learncpp.com/cpp-tutorial/early-binding-and-late-binding/
// 预期输出：
//   5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

void printValue(int value) { std::cout << value << '\n'; }

int main()
{
    auto fcn{ printValue }; // create a function pointer pointing to printValue
    fcn(5);                 // indirect function call through the function pointer

    return 0;
}
