// ============================================================
// 来源小节：14.5 Public and private members and access specifiers
// 示例说明：测验 2b 解答——为 Point3d 增加 isEqual()；因为访问控制按类
//           生效，它可以直接读取形参 p 的私有成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
// 备注：本节代码为按原文描述忠实重建。原文另有一段只调用接口的 driver
//       程序，已并入此处 main()。
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

    // We can use the fact that access controls work on a per-class basis here
    // to directly access the private members of Point3d parameter p
    bool isEqual(const Point3d& p) const
    {
        return (m_x == p.m_x) && (m_y == p.m_y) && (m_z == p.m_z);
    }
};

int main()
{
    Point3d point1{};
    point1.setValues(1, 2, 3);

    Point3d point2{};
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3d point3{};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}

// 预期输出：
// point 1 and point 2 are equal
// point 1 and point 3 are not equal
