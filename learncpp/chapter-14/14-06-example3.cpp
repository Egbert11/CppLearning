// ============================================================
// 来源小节：14.6 Access functions
// 示例说明：命名约定之一——getter 用 "get" 前缀、setter 用 "set" 前缀。
//           优点是很明确这是访问函数，应可廉价调用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/access-functions/
// 备注：本节代码为按原文描述忠实重建。原文以片段形式给出，此处补一个
//       最小类与 main() 以便独立编译。
// ============================================================
class Foo
{
private:
    int m_day{};

public:
    int getDay() const { return m_day; }  // getter
    void setDay(int day) { m_day = day; } // setter
};

int main()
{
    Foo f{};
    f.setDay(5);

    return 0;
}
