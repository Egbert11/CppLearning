// 来源小节：9.6 Assert and static_assert
// 示例说明：用逻辑与把字符串字面量接入断言——字符串总是为真，不改变求值结果，
//           但会让失败信息更具描述性。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example6.cpp -o a
// 说明：found 为 false，运行到断言时异常终止。预期信息形如：
//       Assertion failed: found && "Car could not be found in database",
//       file C:\VCProjects\Test.cpp, line 34
// 警告：本程序运行到断言处会异常终止（非零退出），属预期行为。
//
// 本节代码为按原文描述重建。

#include <cassert>  // for assert
#include <iostream>

int main()
{
    bool found{ false }; // pretend the database lookup failed

    assert(found && "Car could not be found in database"); // now the message is descriptive

    std::cout << "Found the car\n";

    return 0;
}
