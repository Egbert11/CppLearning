// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：测验解答——Ball 类持有颜色与半径，用成员初始化列表构造；
//           打印其值的 print() 是“非成员函数”（见 14.8 的理由）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 备注：本节代码为按原文描述忠实重建（原文给出完整解答）。
//       m_color 用 std::string 而非 std::string_view，因为 Ball 应“拥有”颜色，
//       否则传入临时 string 时会造成悬垂。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文测验题解答 ---
class Ball
{
private:
    std::string m_color { "none" };
    double m_radius { 0.0 };

public:
    Ball(std::string_view color, double radius)
        : m_color { color }
        , m_radius { radius }
    {
    }

    const std::string& getColor() const { return m_color; }
    double getRadius() const { return m_radius; }
};

void print(const Ball& ball)
{
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

int main()
{
    Ball blue { "blue", 10.0 };
    print(blue);

    Ball red { "red", 12.0 };
    print(red);

    return 0;
}

// 预期输出：
// Ball(blue, 10)
// Ball(red, 12)
