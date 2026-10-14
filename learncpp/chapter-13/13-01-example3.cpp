// ============================================================
// 来源小节：13.1 Introduction to program-defined (user-defined) types
// 示例说明：类型别名（type alias）必须先定义后使用——它引入一个新的标识符，
//           编译器必须先看到定义；但定义本身不创建任何对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

using Length = int; // define a type alias with identifier 'Length'

int main()
{
    Length x { 5 }; // we can use 'length' here since we defined it above
    std::cout << x << '\n';

    return 0;
}

// 预期输出：
// 5
