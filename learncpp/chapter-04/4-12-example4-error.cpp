// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：花括号初始化拒绝会丢值的隐式窄化转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 注意：本示例**故意演示编译错误**——int x { 5.5 }; 会导致
//       "narrowing conversion of '5.5' from 'double' to 'int'" 编译错误，无法通过编译。

int main()
{
    double d { 5 }; // okay: int to double is safe
    int x { 5.5 };  // error: double to int not safe

    return 0;
}
