// ============================================================
// 来源小节：12.13 In and out parameters
// 示例说明：并排给出按值、按引用、按地址三种形参。按地址要求在调用处写 &，
//           能让“此处会被修改”更明显；但若直接传指针变量又会再次隐藏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/
// 备注：本节代码为按原文描述忠实重建（原 Example 4；为使程序可链接，补上了
//       三个函数的空实现）。
// ============================================================
void foo1(int x)  { (void)x; } // pass by value
void foo2(int& x) { ++x; }     // pass by reference
void foo3(int* x) { ++*x; }    // pass by address

int main()
{
    int i{};

    foo1(i);  // can't modify i
    foo2(i);  // can modify i
    foo3(&i); // can modify i

    int *ptr { &i };
    foo3(ptr); // can modify i

    return 0;
}
