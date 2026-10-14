// ============================================================
// 来源小节：13.1 Introduction to program-defined (user-defined) types
// 示例说明：定义程序自定义类型（program-defined type）Fraction，并实例化一个
//           对象。类型定义只描述 Fraction 长什么样，不创建对象；真正创建
//           对象的是 main 里的定义语句。
//           同时演示：类型名首字母大写、变量名小写不会有任何冲突
//           （Fraction fraction {};），因为 C++ 区分大小写。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================

// Define a program-defined type named Fraction so the compiler understands what a Fraction is
// (we'll explain what a struct is and how to use them later in this chapter)
// This only defines what a Fraction type looks like, it doesn't create one
struct Fraction
{
    int numerator {};
    int denominator {};
};

// Now we can make use of our Fraction type
int main()
{
    Fraction f { 3, 4 }; // this actually instantiates a Fraction object named f

    // 原文示例片段：类型名 Fraction 与变量名 fraction 不冲突
    [[maybe_unused]] Fraction fraction {}; // Instantiates a variable named fraction of type Fraction

    (void)f;
    return 0;
}
