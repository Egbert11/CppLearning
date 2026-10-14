// ============================================================
// 来源小节：25.5 Early binding and late binding（原 Example 7）
// 示例说明：用函数指针取代直接调用 —— 先按运算符编号让 fcn 指向目标函数，
//           再通过 fcn(x, y) 间接调用（late binding）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/early-binding-and-late-binding/
// 交互输入：两个整数 x y，再输入一个运算符编号（0=加, 1=减, 2=乘）。
// 预期输出（示例输入 5 3 0）：
//   ... The answer is: 8
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

    using FcnPtr = int (*)(int, int);
    FcnPtr fcn{ nullptr };
    switch (operation)
    {
    case 0:
        fcn = add;
        break;
    case 1:
        fcn = subtract;
        break;
    case 2:
        fcn = multiply;
        break;
    default:
        std::cout << "Invalid operator\n";
        return 1;
    }

    std::cout << "The answer is: " << fcn(x, y) << '\n';

    return 0;
}
