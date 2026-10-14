// ============================================================
// 来源小节：17.11 C-style string symbolic constants
// 示例说明：打印 char 变量的地址会踩坑——&c 的类型是 char*，被当作字符串处理（原 Example 6）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/
// 后缀：-ub。c 不是以空终止符结尾的字符串，却被当作字符串打印，
//       会一直打印到相邻内存中碰巧出现零字节为止，属未定义行为。
//       作者机器上的输出类似：Q╠╠╠╠╜╡4;¿■A（依其后内存内容而定）。
// ============================================================
#include <iostream>

int main()
{
    char c{ 'Q' };
    std::cout << &c; // &c has type char*, so it is treated as a string (undefined behavior)

    return 0;
}
