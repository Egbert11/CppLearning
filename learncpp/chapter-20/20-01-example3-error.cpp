// 来源小节：20.1 Function Pointers
// 示例说明：函数指针不会隐式转换为 void*。
//           int (*)() -> void* 是“条件性支持的转换”，GCC/Clang 在 C++ 模式下拒绝编译；
//           （原文提到“一些编译器可能允许”，但标准并不要求它们这样做。）
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-pointers/
// 预期错误：error: invalid conversion from 'int (*)()' to 'void*' [-fpermissive]
// 说明：本节代码为按原文描述重建。请勿修复，此文件故意无法编译。

int foo()
{
    return 5;
}

int main()
{
    int (*fcnPtr)() { foo }; // okay, foo implicitly converts to function pointer to foo
    void* vPtr { foo };      // not okay (some compilers may allow this)

    (void)fcnPtr;
    (void)vPtr;
    return 0;
}
