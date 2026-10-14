// 来源小节：11.2 Function overload differentiation
// 示例说明：仅返回类型不同无法构成重载——裸调用 getRandomValue(); 无法提示该选哪个版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/
//
// 编译：g++ -std=c++20 -Wall 11-02-example6-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误（Visual Studio 为 C2556）：两个 getRandomValue() 仅返回类型不同，不允许重载。
//   g++ 会报 "ambiguating new declaration of 'double getRandomValue()'" 一类的错误。
//
// 本节代码为按原文描述重建。

int getRandomValue();
double getRandomValue(); // error: overloads can't differ by return type alone

int main()
{
    return 0;
}
