// 来源小节：11.9 Non-type template parameters
// 示例说明：使用运行期 assert 的 getSqrt（在运行期而非编译期检查非负）
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 预期输出（以 -DNDEBUG 编译时）：2.23607 然后 0
// 注意：默认（未定义 NDEBUG）时 assert 是启用的，getSqrt(-5.0) 会在运行期中止程序；
//       这与原文所述"assert 在非调试构建里通常被编译掉"一致。

#include <cassert>
#include <cmath> // for std::sqrt
#include <iostream>

double getSqrt(double d)
{
    assert(d >= 0.0 && "getSqrt(): d must be non-negative");

    // The assert above will probably be compiled out in non-debug builds
    if (d >= 0)
        return std::sqrt(d);

    return 0.0;
}

int main()
{
    std::cout << getSqrt(5.0) << '\n';
    std::cout << getSqrt(-5.0) << '\n';

    return 0;
}
