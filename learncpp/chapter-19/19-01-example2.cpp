// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：把一百万个 int（约 4MB）放在栈上的定长数组里，可能撑爆栈。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：若栈够大则输出 7 并正常退出；否则发生栈溢出，程序被操作系统终止
//           （看不到任何输出）。本机 MSYS2/MinGW 工具链实测即溢出（非零退出码）。
// 备注：原文以 Visual Studio 缺省 1MB 栈为例。是否溢出取决于平台与工具链
//       的缺省栈大小（MSYS2/MinGW 与 Linux 的缺省值不同），并非未定义行为。
// ============================================================
#include <iostream>

int main()
{
    int array[1000000]; // allocate 1 million integers (probably 4MB of memory)

    array[0] = 7; // 原文无此行；仅为避免"未使用变量"警告
    std::cout << array[0] << '\n';

    return 0;
}
