// 来源小节：2.5 Introduction to local scope
// 示例说明：用注释标出局部变量的创建点与销毁顺序（x、y 进入函数时创建，z 在定义处创建；
//           函数结束时按 z, y, x 的反序销毁）。（覆盖原文示例 3 与示例 4。）
//           预期输出：11
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example2.cpp -o a

#include <iostream>

int add(int x, int y) // x and y are created and initialized here
{
    int z{ x + y }; // z is created and initialized here

    return z;
} // z, y, and x destroyed here

int main()
{
    std::cout << add(5, 6) << '\n';

    return 0;
}
