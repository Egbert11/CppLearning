// ============================================================
// 来源小节：23.4 Association
// 示例说明：间接关联——Driver 不保存 Car 指针，只保存 int m_carId；
//           通过 CarLot::getCar() 按 ID 查找 Car。
// 原文链接：https://www.learncpp.com/cpp-tutorial/association/
// 预期输出：
//   Franz is driving a Corolla
// 备注：本节代码为按原文描述重建（原 Example 3）。
// ============================================================
#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Car
{
private:
    std::string m_name{};
    int m_id{};

public:
    Car(std::string_view name, int id)
        : m_name{ name }, m_id{ id }
    {
    }

    const std::string& getName() const { return m_name; }
    int getId() const { return m_id; }
};

// Our CarLot is essentially just a static array of cars
namespace CarLot
{
    std::array<Car, 4> carLot{
        Car{ "Prius", 4 },
        Car{ "Corolla", 17 },
        Car{ "Accord", 84 },
        Car{ "Matrix", 62 }
    };

    // The CarLot can provide us a car by ID
    const Car* getCar(int id)
    {
        for (const auto& car : carLot)
        {
            if (car.getId() == id)
                return &car;
        }

        return nullptr;
    }
}

class Driver
{
private:
    std::string m_name{};
    int m_carId{}; // we're associated with the car by ID rather than pointer

public:
    Driver(std::string_view name, int carId)
        : m_name{ name }, m_carId{ carId }
    {
    }

    const std::string& getName() const { return m_name; }
    int getCarId() const { return m_carId; }
};

int main()
{
    Driver d{ "Franz", 17 }; // Franz is driving the car with ID 17

    const Car* car{ CarLot::getCar(d.getCarId()) }; // Get that car from the car lot

    if (car)
        std::cout << d.getName() << " is driving a " << car->getName() << '\n';
    else
        std::cout << d.getName() << " couldn't find his car\n";

    return 0;
}
