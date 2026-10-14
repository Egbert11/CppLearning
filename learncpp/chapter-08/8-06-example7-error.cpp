// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：switch 中的变量定义与初始化 —— 本文件故意无法编译。
//           - 在第一个 case 标签之前初始化变量是非法的；
//           - 在非最后一个 case 处初始化变量也是非法的；
//           因为执行可能跳过该初始化，导致变量处于未定义（未初始化）状态，进而产生未定义行为。
//           编译器报错形如：error: jump to case label ... crosses initialization of 'int b'
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example7-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    switch (1)
    {
        int a; // okay: definition is allowed before the case labels
        int b{ 5 }; // illegal: initialization is not allowed before the case labels

    case 1:
        int y; // okay but bad practice: definition is allowed within a case
        y = 4; // okay: assignment is allowed
        break;

    case 2:
        int z{ 4 }; // illegal: initialization is not allowed if subsequent cases exist
        y = 5; // okay: y was declared above, so we can use it here too
        break;

    case 3:
        break;
    }

    return 0;
}
