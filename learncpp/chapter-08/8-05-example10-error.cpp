// 来源小节：8.5 Switch statement basics
// 示例说明：case 标签值必须唯一 —— 本文件故意无法编译。
//           重复的 case 54，以及 case '6'（字符 '6' 会被转换为整数 54，同样重复）。
//           编译器报错形如：error: duplicate case value
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-statement-basics/
//
// 编译：g++ -std=c++20 -Wall 8-05-example10-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    switch (54)
    {
    case 54:
        break;
    case '6': // char '6' converts to int 54 -- duplicate!
        break;
    case 54: // duplicate -- already used value 54!
        break;
    default:
        break;
    }

    return 0;
}
