// 来源小节：2.4 Introduction to function parameters and arguments
// 示例说明：Quiz #4 解答 —— doubleNumber() 接收一个整数参数并返回它的两倍。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
//
// 编译：g++ -std=c++20 -Wall 2-04-quiz4.cpp -o a

int doubleNumber(int x)
{
    return 2 * x; // return twice the value of x
}

int main()
{
    // A small test of doubleNumber()
    return doubleNumber(5) == 10 ? 0 : 1;
}
