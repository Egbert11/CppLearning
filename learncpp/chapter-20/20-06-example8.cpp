// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：泛型 lambda 与静态变量。auto 每解析出一种不同类型，就产生一个独立的 lambda，
//           所以不同类型之间 static 局部变量不共享。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   0: hello
//   1: world
//   0: 1
//   1: 2
//   2: ding dong

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    auto print{ [](auto value) {
        static int callCount{ 0 };
        std::cout << callCount++ << ": " << value << '\n';
    } };

    print("hello"); // 0: hello
    print("world"); // 1: world

    print(1); // 0: 1 (separate static because const char* and int are different types)
    print(2); // 1: 2

    print("ding dong"); // 2: ding dong
    // --- 原文示例片段结束 ---

    return 0;
}
