// ============================================================
// 来源小节：19.5 Void pointers（Quiz 解答）
// 示例说明：演示"void 指针"与"空指针"是两个正交概念——
//           void 指针描述指针的"类型"（可指向任意类型对象，解引用前必须显式转换）；
//           空指针描述指针的"值"（不指向任何对象）。
//           一个 void 指针完全可以是空指针。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-pointers/
// 预期输出：
//   voidPtr is null? yes
//   *castBack = 5
// 备注：本节代码为按原文描述重建（原文 Quiz 的解答说明）。
// ============================================================
#include <iostream>

int main()
{
    void* voidPtr{ nullptr }; // void 指针，且当前是空指针

    std::cout << "voidPtr is null? " << (voidPtr ? "no" : "yes") << '\n';

    int value{ 5 };
    voidPtr = &value; // 同一个 void 指针改为指向一个 int

    // 解引用前必须转换回正确的类型
    int* castBack{ static_cast<int*>(voidPtr) };
    std::cout << "*castBack = " << *castBack << '\n';

    return 0;
}
