// 来源小节：7.5 Variable shadowing (name hiding)
// 示例说明：内层块没有声明自己的 apples，因此这里的 apples 一直是外层变量，赋值会修改外层。
//           （对应原文 Example 2）
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/
//
// 预期输出：
//   5
//   10
//   10
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{ // outer block
    int apples { 5 }; // here's the outer block apples

    { // nested block
        // there is no inner apples, so this refers to the outer block apples
        std::cout << apples << '\n';

        apples = 10; // this applies to outer block apples

        std::cout << apples << '\n';
    } // nested block ends

    std::cout << apples << '\n'; // outer block apples is still 10

    return 0;
}
