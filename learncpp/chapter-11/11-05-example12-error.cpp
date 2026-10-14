// 来源小节：11.5 Default arguments
// 示例说明：三个重载下，print(1, 2) 与 print(1, 2.5) 可解析，但 print(1) 因默认值而歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example12-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：print(1) -> "call of overloaded 'print(int)' is ambiguous"。
//
// 本节代码为按原文描述重建。

void print(int x);                  // signature print(int)
void print(int x, int y = 10);      // signature print(int, int)
void print(int x, double y = 20.5); // signature print(int, double)

int main()
{
    print(1, 2);   // will resolve to print(int, int)
    print(1, 2.5); // will resolve to print(int, double)
    print(1);      // ambiguous function call

    return 0;
}
