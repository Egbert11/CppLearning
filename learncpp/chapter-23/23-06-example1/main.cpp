// ============================================================
// 来源小节：23.6 Container classes
// 示例说明：IntArray 容器类的测试程序——一个"值容器"（组合），
//           内部以动态数组保存元素的副本。演示 resize/insert/remove/
//           insertAtBeginning/insertAtEnd 以及拷贝构造与拷贝赋值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/container-classes/
// 预期输出：
//   40 1 2 3 5 20 6 7 8 30
//   10 10 10 10
// 备注：本节代码为按原文描述重建（原 Example 10 测试程序 + Example 9 完整类）。
//       第二行来自原文的拷贝构造/自赋值检查（打印四个数组的长度）。
// ============================================================
#include <iostream>
#include "IntArray.h"

int main()
{
    // Declare an array with 10 elements
    IntArray array(10);

    // Set all the elements to 1 through 10
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i+1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Print out all the numbers
    for (int i{ 0 }; i < array.getLength(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    // A few more tests to ensure the copy constructor / copy assignment work
    {
        IntArray a{ array };
        a = a; // self-assignment
        IntArray b{ a };
        b = b; // self-assignment
        IntArray c{ b };

        array = c;
        array = array; // self-assignment

        std::cout << a.getLength() << ' ' << b.getLength() << ' '
                  << c.getLength() << ' ' << array.getLength() << '\n';
    }

    return 0;
}
