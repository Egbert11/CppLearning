// ============================================================
// 来源小节：12.13 In and out parameters
// 示例说明：通过两个 out 参数按引用把正弦、余弦值传回调用方，展示“返回
//           值不够用时”用 out 参数送回数据的做法。out 参数命名带 Out 后缀，
//           且位于最右侧。
// 原文链接：https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/
// 示例输入：60
// 示例输出（近似）：The sin is 0.866025 / The cos is 0.5
// 备注：本节代码为按原文描述忠实重建（原 Example 2）。
// ============================================================
#include <cmath> // for std::sin() and std::cos()
#include <iostream>

// degrees is an in parameter; sinOut and cosOut are out parameters
void getSinCos(double degrees, double& sinOut, double& cosOut)
{
    constexpr double pi { 3.14159265358979323846 }; // the value of pi
    double radians = degrees * pi / 180.0;

    sinOut = std::sin(radians); // writes to the out parameter sinOut
    cosOut = std::cos(radians); // writes to the out parameter cosOut
}

int main()
{
    std::cout << "Enter the number of degrees: ";
    double degrees{};
    std::cin >> degrees;

    double sin{};
    double cos{};
    getSinCos(degrees, sin, cos);

    std::cout << "The sin is " << sin << '\n';
    std::cout << "The cos is " << cos << '\n';

    return 0;
}
