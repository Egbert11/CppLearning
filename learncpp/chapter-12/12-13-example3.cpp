// ============================================================
// 来源小节：12.13 In and out parameters
// 示例说明：对比返回值与 out 参数。返回值可以直接用来初始化对象或内联在
//           表达式里；out 参数则必须先有一个可赋值的对象再传入。
// 原文链接：https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/
// 备注：本节代码为按原文描述忠实重建（原 Example 3）。
// ============================================================
#include <iostream>

int getByValue()
{
    return 5;
}

void getByReference(int& x)
{
    x = 5;
}

int main()
{
    // return by value
    [[maybe_unused]] int x { getByValue() }; // can use to initialize object
    std::cout << getByValue() << '\n';       // can use temporary return value in expression

    // out-parameter
    int y{};                 // must first allocate an assignable object
    getByReference(y);       // then pass it to function to modify
    std::cout << y << '\n';  // y now holds the result

    return 0;
}
