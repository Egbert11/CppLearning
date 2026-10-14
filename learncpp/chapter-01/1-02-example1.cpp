// 来源小节：1.2 Comments
// 示例说明：演示单行注释、多行注释（C 风格）、"美化"多行注释，以及多行注释不能嵌套。
// 原文链接：https://www.learncpp.com/cpp-tutorial/comments/

#include <iostream>

int main()
{
    std::cout << "Hello world!"; // Everything from here to the end of the line is ignored

    /* This is a multi-line comment.
       This line will be ignored.
       So will this one. */

    /* This is a multi-line comment.
     * the matching asterisks to the left
     * can make this easier to read
     */

    // 下面这个嵌套写法【不能】按预期工作：注释会在第一个 */ 处提前结束。
    // /* This is a multi-line /* comment */ this is not inside the comment */
    // The above comment ends at the first */, not the second */
    // 因此上行的 "this is not inside the comment */" 会被当作代码，从而引发编译错误，
    // 这一行特意以单行注释保留，避免本文件无法编译。

    return 0;
}
