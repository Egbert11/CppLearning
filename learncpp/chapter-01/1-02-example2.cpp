// 来源小节：1.2 Comments
// 示例说明：演示"注释掉代码"的各种方式——逐行 //、整块 /* */，以及 #if 0 预处理指令。
// 原文链接：https://www.learncpp.com/cpp-tutorial/comments/
//
// 预期输出：
//   1

#include <iostream>

int main()
{
    std::cout << 1; // 唯一真正被编译、会输出的语句

    // Commenting out a single line
    //    std::cout << 1;

    // Commenting out a block with single-line comments on each line
    //    std::cout << 1;
    //    std::cout << 2;
    //    std::cout << 3;

    // Commenting out the same block with one multi-line comment
    /*
        std::cout << 1;
        std::cout << 2;
        std::cout << 3;
    */

    // 当被注释的代码本身含有 */ 时，可用 #if 0 预处理指令代替多行注释
#if 0
    std::cout << 1;
    std::cout << 2;
    std::cout << 3;
#endif

    return 0;
}
