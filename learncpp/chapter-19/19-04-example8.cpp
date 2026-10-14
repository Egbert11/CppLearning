// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：因为每列是独立分配的，各行长度可以不同——"锯齿/三角"数组。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期输出：1 2 3 4 5 6 7 8 9 10（第 count 行有 count+1 个元素）
// 备注：本节代码为按原文描述重建（原文 Example 13）。
// ============================================================
#include <iostream>

int main()
{
    int** array { new int*[10] }; // allocate an array of 10 int pointers
    for (int count { 0 }; count < 10; ++count)
    {
        array[count] = new int[count+1]; // 第 count 行长度为 count+1
        for (int col { 0 }; col < count+1; ++col)
            array[count][col] = count + 1; // 便于观察每行长度
    }

    // 打印三角形
    for (int count { 0 }; count < 10; ++count)
    {
        for (int col { 0 }; col < count+1; ++col)
            std::cout << array[count][col] << ' ';
        std::cout << '\n';
    }

    for (int count { 0 }; count < 10; ++count)
        delete[] array[count];
    delete[] array; // this needs to be done last

    return 0;
}
