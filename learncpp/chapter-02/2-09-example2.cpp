// 来源小节：2.9 Naming collisions and an introduction to namespaces
// 示例说明：原文 Example 5 —— 用 using 指令（using namespace std;）改写 Hello world。
//           可编译运行，但这正是原文警告"不要滥用"的写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/naming-collisions-and-an-introduction-to-namespaces/
//
// 编译：g++ -std=c++20 -Wall 2-09-example2.cpp -o a

#include <iostream>

using namespace std; // this is a using-directive that allows us to access names in the std namespace with no namespace prefix

int main()
{
    cout << "Hello world!";
    return 0;
}
