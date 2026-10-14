// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：addOne 接受非 const 左值引用 int&，因此必须传入具名对象（左值）；
//           传入表达式 5 + 3（右值）会产生编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
//
// *** 本文件为预期编译失败示例（-error），请勿"修复" ***
// 预期错误：addOne(5 + 3); 处——表达式不是左值（cannot bind non-const
//           lvalue reference of type 'int&' to an rvalue of type 'int'）。
// ============================================================
#include <iostream>

void addOne(int& value) // 非 const 左值引用
{
    ++value;
}

int main()
{
    int sum{ 5 + 3 };

    addOne(sum);     // 合法：sum 是左值
    addOne(5 + 3);   // 编译错误：not an lvalue

    std::cout << sum << '\n';

    return 0;
}
