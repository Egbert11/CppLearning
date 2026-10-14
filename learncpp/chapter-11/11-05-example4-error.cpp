// 来源小节：11.5 Default arguments
// 示例说明：带默认值的形参无法被跳过——print(20.0) 无法匹配（不能只为 d 传值而跳过 sv）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example4-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：print(20.0) -> "no matching function for call to 'print(double)'"。
//
// 本节代码为按原文描述重建。

#include <string_view>

void print(std::string_view sv="Hello", double d=10.0);

int main()
{
    print();           // okay: both arguments defaulted
    print("Macaroni"); // okay: d defaults to 10.0
    print(20.0);       // error: does not match above function (cannot skip argument for sv)

    return 0;
}
