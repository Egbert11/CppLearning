// ============================================================
// 来源小节：25.5 Early binding and late binding（原 Example 4）
// 示例说明：用 switch 直接调用目标函数（early binding）。运行路径要到运行时才决定，
//           但"调用哪个函数"在编译期已确定，属于执行路径问题而非绑定问题。
// 原文链接：https://www.learncpp.com/cpp-tutorial/early-binding-and-late-binding/
// 交互输入：两个整数 x y，再输入一个运算符编号（0=加, 1=减, 2=乘）。
// 预期输出（示例输入 5 3 0）：
//   Enter a number: Enter a second number: Enter '0' to add, '1' to subtract, '2' to multiply: The answer is: 8
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter a second number: ";
    int y{};
    std::cin >> y;

    int operation{};
    std::cout << "Enter '0' to add, '1' to subtract, '2' to multiply: ";
    std::cin >> operation;

    int result{};
    // call the target function directly using early binding
    switch (operation)
    {
    case 0:
        result = add(x, y);
        break;
    case 1:
        result = subtract(x, y);
        break;
    case 2:
        result = multiply(x, y);
        break;
    default:
        std::cout << "Invalid operator\n";
        return 1;
    }

    std::cout << "The answer is: " << result << '\n';

    return 0;
}
