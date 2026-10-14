// 来源小节：11.5 Default arguments
// 示例说明：默认值不属于函数签名——下面三个声明是三个不同签名的重载。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example10.cpp -o a
//
// 本节代码为按原文描述重建。
// 注：本文件仅声明（未调用），故无链接问题；它演示签名与默认值无关。

void print(int x);                  // signature print(int)
void print(int x, int y = 10);      // signature print(int, int)
void print(int x, double y = 20.5); // signature print(int, double)

int main()
{
    return 0;
}
