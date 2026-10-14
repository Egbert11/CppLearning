// 来源小节：7.14 Unnamed and inline namespaces
// 示例说明：与匿名命名空间示例等价 —— 在文件作用域把函数声明为 static（内部链接）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
//
// 本节示例为按原文描述重建（对应原文 Example 2）。
// 预期输出：v1

#include <iostream>

static void doSomething() // 只能在本文件中访问
{
    std::cout << "v1\n";
}

int main()
{
    doSomething(); // 可以不加命名空间前缀调用 doSomething()

    return 0;
}
