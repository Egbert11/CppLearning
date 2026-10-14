// 来源小节：11.5 Default arguments
// 示例说明：规则违反——某形参带默认值后，其右侧所有形参也必须带默认值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example5-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：形参 y 缺少默认实参（default argument missing for parameter 2）。
//
// 本节代码为按原文描述重建。

void print(int x=10, int y); // not allowed

int main()
{
    return 0;
}
