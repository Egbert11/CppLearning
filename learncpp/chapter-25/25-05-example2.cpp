// ============================================================
// 来源小节：25.5 Early binding and late binding（原 Example 3）
// 示例说明：重载函数与函数模板的调用在编译期即可解析（early binding）。
//           两个调用都得到 printValue(int) / printValue<int>(int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/early-binding-and-late-binding/
// 预期输出：
//   5
//   5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

void printValue(int value) { std::cout << value << '\n'; }
void printValue(double value) { std::cout << value << '\n'; }

template <typename T>
void printValue(T value) { std::cout << value << '\n'; }

int main()
{
    printValue(5);    // calls printValue(int)
    printValue<>(5);  // calls the template instantiation printValue<int>(int)

    return 0;
}
