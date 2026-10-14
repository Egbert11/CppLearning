// ============================================================
// 来源小节：17.5 Arrays of references via std::reference_wrapper
// 示例说明：不能创建"引用的数组"——引用不是对象，不能作为元素；元素还必须
//           可赋值，而引用不能重绑定。用引用变量初始化数组并不会得到引用数组，
//           而是退化成值的数组。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper/
// 预期错误：编译错误——cannot define array of references（std::array<int&, 2>）。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>

int main()
{
    int x { 1 };
    int y { 2 };

    [[maybe_unused]] std::array<int&, 2> refarr { x, y }; // compile error: cannot define array of references

    int& ref1 { x };
    int& ref2 { y };
    [[maybe_unused]] std::array valarr { ref1, ref2 }; // ok: this is actually a std::array<int, 2>, not an array of references

    return 0;
}
