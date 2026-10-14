// 来源小节：20.7 Lambda captures
// 示例说明：悬垂引用。makeWalrus() 返回的 lambda 按引用捕获了局部变量 name；
//           name 随函数返回而销毁，之后调用该 lambda 是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// **未定义行为**：输出依实现而定，可能打印乱码、旧数据或崩溃。
// Warning：使用引用捕获（尤其是默认引用捕获 [&]）时要格外小心，被捕获的变量必须比 lambda 活得久。

#include <iostream>
#include <string>

// --- 原文示例片段 ---
// returns a lambda
auto makeWalrus(const std::string& name)
{
    // local @name is captured by reference
    return [&]() {
        std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
    };
}

int main()
{
    // Create a new walrus whose name is Roofus.
    // makeWalrus returns a lambda function (and @name is destroyed).
    auto walrus{ makeWalrus("Roofus") };

    // Call our walrus (the lambda returned from makeWalrus).
    // This is undefined behavior -- Roofus is now a dangling reference
    walrus();

    return 0;
}
// --- 原文示例片段结束 ---
