// 来源小节：20.x Chapter 20 summary and quiz（Quiz 1）
// 示例说明：为三种情形写出函数原型，并在需要处补上 const：
//   a) max()：两个 double，返回较大的那个。
//   b) swap()：交换两个 int。
//   c) getLargestElement()：接收动态分配的 int 数组（和长度），返回最大元素，
//      以便调用者修改返回的那个元素（返回引用）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz/
// 说明：本节代码按原文解答重建。这里只给出原型（函数体从略），故 main 不做调用，
//       以免产生链接错误。

// --- 原文解答 ---
// a) A function max() that takes two doubles and returns the larger of the two.
double max(double x, double y);

// b) A function swap() that swaps two integers.
void swap(int& x, int& y);

// c) A function getLargestElement() that takes a dynamically allocated array of
//    integers and returns the largest number so the caller can modify the returned
//    element.
// array can't be const here, since returning a non-const reference
// to a const element would violate const-correctness.
int& getLargestElement(int* array, int length);
// --- 原文解答结束 ---

int main()
{
    // The prototypes above are the answer; no definitions are needed here.
    return 0;
}
