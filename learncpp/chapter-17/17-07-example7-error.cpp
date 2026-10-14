// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：当用初始化列表给每个元素都提供了值时可以省略长度，由编译器推导；
//           但如果用空花括号 {} 且省略长度，编译器会推出长度为 0，而零长数组
//           不被允许，因此报错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期错误：编译错误——zero-size array 'bad'。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
//       GCC 默认把零长数组当作扩展接受，需加 -pedantic-errors 才会拒绝：
//         g++ -std=c++20 -Wall -pedantic-errors 17-07-example7-error.cpp
//       这是原文所述的"编译器推导出不被允许的零长数组"。
// ============================================================
int main()
{
    int bad[] {}; // compile error: the compiler deduces a zero-length array, which is not allowed

    return bad[0];
}
