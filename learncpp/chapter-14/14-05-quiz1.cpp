// ============================================================
// 来源小节：14.5 Public and private members and access specifiers
// 示例说明：测验 2a 解答——Point3d：私有数据成员 + 公有的 setValues()
//           与 print()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
// 备注：本节代码为按原文描述忠实重建。原文另有一段只调用接口的 driver
//       程序（创建 point、setValues(1,2,3)、print），已并入此处 main()。
// ============================================================
#include <iostream>

class Point3d
{
private:
    int m_x {};
    int m_y {};
    int m_z {};

public:
    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print() const
    {
        std::cout << '<' << m_x << ", " << m_y << ", " << m_z << '>';
    }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}

// 预期输出：
// <1, 2, 3>
