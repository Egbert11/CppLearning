// 来源小节：8.7 Goto statements
// 示例说明：非法的向前跳转 —— 本文件故意无法编译。
//           不能向前跳过某个变量的初始化，而该变量在标签处仍在作用域内；
//           跳过初始化会让变量的值未定义。
//           编译器报错形如：error: jump to label 'skip' ... crosses initialization of 'int x'
// 原文链接：https://www.learncpp.com/cpp-tutorial/goto-statements/
//
// 编译：g++ -std=c++20 -Wall 8-07-example3-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    goto skip;   // error: this jump is illegal because...
    int x { 5 }; // this initialized variable is still in scope at statement label 'skip'
skip:
    x += 3;      // what would this even evaluate to if x wasn't initialized?
    return 0;
}
