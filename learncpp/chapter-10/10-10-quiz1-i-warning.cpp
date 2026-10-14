// 来源小节：10.x Chapter 10 summary and quiz（本文件编号 10-10）
// 示例说明：测验 1 之 1i —— double f { 5.0f }; float i { f }; 因为 f 不是 constexpr，
//           编译器无法判定 double -> float 是否保值，按标准这属于窄化、程序 ill-formed。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 10-10-quiz1-i-warning.cpp -o a
//       预期产生警告：warning: narrowing conversion of 'f' from 'double' to 'float' [-Wnarrowing]
//       注：GCC 默认把浮点窄化只当作警告（不是硬错误），因此本文件能编译；若要强制
//           按标准报错，需加 -pedantic-errors：
//             g++ -std=c++20 -Wall -pedantic-errors 10-10-quiz1-i-warning.cpp -o a
//               -> error: narrowing conversion of 'f' from 'double' to 'float'
//           故此处用 -warning 后缀而非 -error。（对照：constexpr 值的窄化如
//           10-10-quiz1-c-error.cpp 在 GCC 下默认即为硬错误。）
//
// 本节代码为按原文解答要点重建。

int main()
{
    double f{ 5.0f };
    float i{ f }; // 1i: 窄化转换（f 不是 constexpr）——GCC 默认仅警告，标准要求 ill-formed

    (void)i;
    return 0;
}
