// 来源小节：7.7 External linkage and variable forward declarations
// 示例说明：前向声明另一文件里定义的 sayHi()，链接器把本文件的调用连到 a.cpp 的定义。
//           （对应原文 Example 2 的 main.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
//
// 预期输出：Hi!

void sayHi(); // forward declaration for function sayHi, makes sayHi accessible in this file

int main()
{
    sayHi(); // call to function defined in another file, linker will connect this call to the function definition

    return 0;
}
