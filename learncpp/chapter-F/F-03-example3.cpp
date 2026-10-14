// 来源小节：F.3 Constexpr functions (part 3) and consteval
// 示例说明：用 CONSTEVAL 宏强制某个 constexpr 调用在编译期求值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-3-and-consteval/
//
// 预期输出（-O0）：
//   5
//   5
//   6
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       For advanced readers：CONSTEVAL 用可变参数宏配合"立即调用的 consteval lambda"实现；
//       CONSTEVAL11 则是 C++11 版本的变体。
//       注意：compare(5, 6) 处在非必须常量表达式语境，-O0 时按运行期处理得到 5；
//             开启 -O2 后编译器可能改为编译期求值而得到 6（实现相关）。
#include <iostream>
#include <type_traits> // for std::is_constant_evaluated

// Uses a C++20 consteval lambda in a variadic preprocessor macro
// Note: 原文写作 `[] consteval { ... }`（去掉参数表的形式，属 C++23 便利写法）；
//       在 -std=c++20 下须写成 `[]() consteval { ... }`，否则触发 -Wc++23-extensions 警告。
#define CONSTEVAL(...) []() consteval { return __VA_ARGS__; }()

// Uses a C++11 constexpr lambda in a variadic preprocessor macro
#define CONSTEVAL11(...) [] { constexpr auto _ = __VA_ARGS__; return _; }()

constexpr int compare(int x, int y) // function is constexpr
{
    if (std::is_constant_evaluated())
        return x > y ? x : y; // greater in constant context
    else
        return x < y ? x : y; // lesser otherwise
}

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    std::cout << compare(x, 6) << '\n';            // prints 5 (runtime: lesser)
    std::cout << compare(5, 6) << '\n';            // prints 5 (may be runtime at -O0)
    std::cout << CONSTEVAL(compare(5, 6)) << '\n'; // prints 6 (always compile-time: greater)
    // --- 原文示例片段结束 ---

    return 0;
}
