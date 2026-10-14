// ============================================================
// 来源小节：14.6 Access functions
// 示例说明：命名约定之二——不带前缀，getter 与 setter 用同一个名字、
//           靠函数重载区分。C++ 标准库采用此风格。
//           缺点是外部看到 d.day(5) 时不易察觉这是修改状态。
// 原文链接：https://www.learncpp.com/cpp-tutorial/access-functions/
// 备注：本节代码为按原文描述忠实重建。原文以片段形式给出，此处补一个
//       最小类与 main() 以便独立编译。
// ============================================================
class Foo
{
private:
    int m_day{};

public:
    int day() const { return m_day; }  // getter
    void day(int day) { m_day = day; } // setter
};

int main()
{
    Foo f{};
    f.day(5); // does this look like it's setting the day member to 5?

    return 0;
}
