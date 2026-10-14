// 来源小节：7.5 Variable shadowing (name hiding)
// 示例说明：嵌套块中同名的内层 apples 遮蔽（shadow）外层 apples；对内层赋值不影响外层，
//           内层块结束后外层值保持不变。（对应原文 Example 1）
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/
//
// 预期输出：
//   5
//   10
//   5
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{ // outer block
    int apples { 5 }; // here's the outer block apples

    { // nested block
        // apples refers to outer block apples here
        // so print it
        std::cout << apples << '\n'; // print value of outer block apples

        int apples { 0 }; // define apples in the scope of the nested block

        // apples now refers to the nested block apples
        // the outer block apples is shadowed
        apples = 10; // this assigns value 10 to nested block apples, not outer block apples

        std::cout << apples << '\n'; // print value of nested block apples
    } // nested block apples destroyed

    std::cout << apples << '\n'; // prints value of outer block apples

    return 0;
} // outer block apples destroyed
